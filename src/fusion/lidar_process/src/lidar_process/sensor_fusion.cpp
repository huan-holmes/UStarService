#include "lidar_process/sensor_fusion.h"

namespace UstarFusion
{
    SensorFusion::SensorFusion() : is_initialized_(false), last_timestamp_(0.0)
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
        box_array_sub_ = nh_.subscribe<jsk_recognition_msgs::BoundingBoxArray>("/detected_bounding_boxs", 1, &SensorFusion::obstacleBoxCallback, this);
    }
    void SensorFusion::obstacleBoxCallback(const jsk_recognition_msgs::BoundingBoxArray::ConstPtr &array)
    {

        if (array->boxes.size() > 0)
        {
            obstacle_array_.clear();
            for (size_t i = 0; i < array->boxes.size(); i++)
            {
                LidarClusterType raw_cluster_data;
                raw_cluster_data.raw_data = Eigen::VectorXd(2);
                raw_cluster_data.timestamp = array->header.stamp.toSec();
                float x, y;
                x = array->boxes[i].pose.position.x;
                y = array->boxes[i].pose.position.y;
                raw_cluster_data.raw_data << x, y;
                obstacle_array_.push_back(raw_cluster_data);
               
            }
        }
    }
    void SensorFusion::Process(LidarClusterType lidar_data)
    {
        if (!is_initialized_)
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
            is_initialized_ = true;
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

} // namespace UstarFusion