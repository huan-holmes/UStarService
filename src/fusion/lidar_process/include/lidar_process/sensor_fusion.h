#ifndef SENSOR_FUSION_H_
#define SENSOR_FUSION_H_
#include "lidar_process/kalman_filter.h"
#include "lidar_process/sensor_type.h"
#include <ros/ros.h>
#include <iostream>
#include <jsk_recognition_msgs/BoundingBoxArray.h>
#include "visualization_msgs/MarkerArray.h"
namespace UstarFusion
{
    class SensorFusion
    {
    public:
        SensorFusion();

        void run();
        void Process(LidarClusterType lidar_data);
        
        void obstacleBoxCallback(const jsk_recognition_msgs::BoundingBoxArray::ConstPtr &array);
        void markerPublish();
        void match();

        KalmanFilter kf_; 
    private:
        ros::NodeHandle nh_;
        ros::Rate rate_;
        ros::Subscriber box_array_sub_;
        ros::Publisher markerArr_pub_;

        visualization_msgs::MarkerArray marker_array_;

        std::vector<LidarClusterType> obstacle_vector_;
        std::vector<LidarClusterType> obstacle_array_;

        uint32_t shape_;
        double obstacle_vel_;
        double match_distance_;
        int obstacle_count_;

        bool is_initialized_;

        bool is_kalman_initialized_;
        long last_timestamp_;
        Eigen::MatrixXd H_lidar_;
        Eigen::MatrixXd R_lidar_;
    };
} // namespace UstarFusion

#endif