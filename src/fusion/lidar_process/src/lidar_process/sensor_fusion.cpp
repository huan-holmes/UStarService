#include "lidar_process/sensor_fusion.h"

namespace UstarFusion
{
    SensorFusion::SensorFusion() : is_initialized_(false), is_kalman_initialized_(false), last_timestamp_(0.0),
                                   obstacle_vel_(1.2), match_distance_(0.0), obstacle_count_(0), rate_(10), delay_time_(20),
                                   shape_(visualization_msgs::Marker::CUBE)
    {
        H_lidar_ = Eigen::MatrixXd(2, 4);
        H_lidar_ << 1, 0, 0, 0,
            0, 1, 0, 0;
        R_lidar_ = Eigen::MatrixXd(2, 2);
        R_lidar_ << 0.0225, 0,
            0, 0.0225;
    }

    void SensorFusion::run()
    {
        markerArr_pub_ = nh_.advertise<visualization_msgs::MarkerArray>("fusion_obstacle_marker", 5);
        box_array_sub_ = nh_.subscribe("detected_bounding_boxs", 10, &SensorFusion::obstacleBoxCallback, this);
        markerPublish();
    }

    void SensorFusion::obstacleBoxCallback(const jsk_recognition_msgs::BoundingBoxArray::ConstPtr &array)
    {

        if (array->boxes.size() > 0)
        {
            obstacle_array_.clear();
            if (is_initialized_)
            {
                double delta_t = array->header.stamp.toSec() - last_timestamp_;
                match_distance_ = delta_t * obstacle_vel_;

                //ROS_INFO_STREAM(match_distance_);
            }
            last_timestamp_ = array->header.stamp.toSec();

            for (size_t i = 0; i < array->boxes.size(); i++)
            {
                LidarClusterType raw_cluster_data;
                raw_cluster_data.raw_data = Eigen::VectorXd(2);
                raw_cluster_data.timestamp = array->header.stamp.toSec();

                float x, y;
                x = array->boxes[i].pose.position.x;
                y = array->boxes[i].pose.position.y;
                raw_cluster_data.raw_data << x, y;
                raw_cluster_data.obstacle_id = i;
                raw_cluster_data.lose_count = 0;
                obstacle_array_.push_back(raw_cluster_data);
                if (!is_initialized_)
                {
                    obstacle_count_++;
                    obstacle_vector_.push_back(raw_cluster_data);
                }
            }
            if (is_initialized_)
                match();
            if (!is_initialized_)
                is_initialized_ = true;
        }
    }

    void SensorFusion::match()
    {
        int size = obstacle_array_.size();
        std::vector<int> index_update;
        for (int i = 0; i < obstacle_vector_.size(); i++)
            index_update.push_back(0);
        for (int i = 0; i < size; i++)
        {
            double x1 = obstacle_array_[i].raw_data[0];
            double y1 = obstacle_array_[i].raw_data[1];
            double distance_min = DBL_MAX;
            int index;

            for (int j = 0; j < obstacle_vector_.size(); j++)
            {
                double x2 = obstacle_vector_[j].raw_data[0];
                double y2 = obstacle_vector_[j].raw_data[1];
                double distance = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
                if (distance < distance_min)
                {
                    distance_min = distance;
                    index = j;
                }
            }
            //ROS_INFO("min: %.3f, match: %.3f", distance_min, match_distance_);
            if (distance_min <= match_distance_)
            {

                obstacle_vector_[index].raw_data = obstacle_array_[i].raw_data;
                obstacle_vector_[index].lose_count = 0;
                index_update[index] = 1;
            }
            else
            {

                obstacle_vector_.push_back(obstacle_array_[i]);
                obstacle_vector_.back().obstacle_id = obstacle_count_;
                obstacle_vector_.back().lose_count = 0;
                index_update.push_back(1);
                obstacle_count_++;
            }
        }
        //ROS_INFO_STREAM(sizeof(index_update));
        //ROS_INFO("a: %d, v: %d", obstacle_array_.size(), obstacle_vector_.size());
        int count = 0;
        for (int i = 0; i < index_update.size(); i++)
        {
            if (index_update[i])
                continue;
            obstacle_vector_[i - count].lose_count++;
            if (obstacle_vector_[i - count].lose_count > delay_time_)
            {
                obstacle_vector_.erase(obstacle_vector_.begin() + i - count);
                count++;
            }
        }
        //ROS_INFO_STREAM(obstacle_array_.size());
        //ROS_INFO_STREAM(obstacle_vector_.size());
        //ROS_INFO("a: %d, v: %d", obstacle_array_.size(), obstacle_vector_.size());
    }

    void SensorFusion::Process(LidarClusterType lidar_data)
    {
        if (!is_kalman_initialized_)
        {
            Eigen::Vector4d x;
            x << lidar_data.raw_data[0], lidar_data.raw_data[1], 0, 0;

            if (fabs(x(0)) < 0.001)
                x(0) = 0.001;
            if (fabs(x(1)) < 0.001)
                x(1) = 0.001;
            kf_.Initialization(x);
            Eigen::MatrixXd P = Eigen::MatrixXd(4, 4);
            P << 1.0, 0.0, 0.0, 0.0,
                0.0, 1.0, 0.0, 0.0,
                0.0, 0.0, 1000.0, 0.0,
                0.0, 0.0, 0.0, 1000.0;
            kf_.SetP(P);
            Eigen::MatrixXd Q = Eigen::MatrixXd(4, 4);
            Q << 1.0, 0.0, 0.0, 0.0,
                0.0, 1.0, 0.0, 0.0,
                0.0, 0.0, 1.0, 0.0,
                0.0, 0.0, 0.0, 1.0;
            kf_.SetQ(Q);
            last_timestamp_ = lidar_data.timestamp;
            is_kalman_initialized_ = true;
            return;
        }
        //double delta_t = (lidar_data.timestamp - last_timestamp_) / 1000000.0;
        double delta_t = lidar_data.timestamp - last_timestamp_;
        last_timestamp_ = lidar_data.timestamp;
        Eigen::MatrixXd F = Eigen::MatrixXd(4, 4);
        F << 1.0, 0.0, delta_t, 0.0,
            0.0, 1.0, 0.0, delta_t,
            0.0, 0.0, 1.0, 0.0,
            0.0, 0.0, 0.0, 1.0;
        kf_.SetF(F);

        // 预测
        kf_.Prediction();
        kf_.SetH(H_lidar_);
        kf_.SetR(R_lidar_);
        kf_.KFUpdate(lidar_data.raw_data);
    }

    void SensorFusion::markerPublish()
    {
        marker_array_.markers.clear();
        for (int i = 0; i < obstacle_vector_.size(); i++)
        {
            visualization_msgs::Marker marker;
            marker.header.frame_id = "base_link";
            marker.header.stamp = ros::Time::now();
            marker.ns = "sensor_fusion_node";
            marker.id = obstacle_vector_[i].obstacle_id;
            marker.type = shape_;
            marker.action = visualization_msgs::Marker::ADD;

            marker.pose.position.x = obstacle_vector_[i].raw_data[0];
            marker.pose.position.y = obstacle_vector_[i].raw_data[1];
            marker.pose.position.z = 0;
            marker.pose.orientation.x = 0.0;
            marker.pose.orientation.y = 0.0;
            marker.pose.orientation.z = 0.0;
            marker.pose.orientation.w = 1.0;

            marker.scale.x = 0.5;
            marker.scale.y = 0.5;
            marker.scale.z = 0.3;

            marker.color.r = 0;
            marker.color.g = 0;
            marker.color.b = 0;
            marker.color.a = 1;

            marker.lifetime = ros::Duration(0.1);

            marker_array_.markers.push_back(marker);

            marker.id = obstacle_vector_[i].obstacle_id + 1000;
            marker.type = visualization_msgs::Marker::TEXT_VIEW_FACING;
            marker.scale.x = 0.3;
            marker.scale.y = 0.3;
            marker.scale.z = 0.3;
            marker.pose.position.x = obstacle_vector_[i].raw_data[0];
            marker.pose.position.y = obstacle_vector_[i].raw_data[1];
            marker.pose.position.z = 0.5;
            marker.pose.orientation.x = 0.0;
            marker.pose.orientation.y = 0.0;
            marker.pose.orientation.z = 0.0;
            marker.pose.orientation.w = 1.0;
            marker.scale.z = 0.1;
            marker.color.g = 1.0f;
            marker.color.a = 1;
            std::ostringstream str;
            str << obstacle_vector_[i].obstacle_id;
            marker.text = str.str();
            marker_array_.markers.push_back(marker);
        }
        markerArr_pub_.publish(marker_array_);
        rate_.sleep();
    }
} // namespace UstarFusion