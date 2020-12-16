#ifndef SENSOR_FUSION_H_
#define SENSOR_FUSION_H_
#include "lidar_process/kalman_filter.h"
#include "lidar_process/sensor_type.h"
#include <ros/ros.h>
#include <jsk_recognition_msgs/BoundingBoxArray.h>
namespace UstarFusion
{
    class SensorFusion
    {
    public:
        SensorFusion();

        void run();
        void Process(LidarClusterType lidar_data);
        
        void obstacleBoxCallback(const jsk_recognition_msgs::BoundingBoxArray::ConstPtr &array);

        KalmanFilter kf_; 
    private:
        ros::NodeHandle nh_;
        ros::Subscriber box_array_sub_;

        std::vector<LidarClusterType> obstacle_vector_;
        std::vector<LidarClusterType> obstacle_array_;

        

        bool is_initialized_;
        long last_timestamp_;
        Eigen::MatrixXd H_lidar_;
        Eigen::MatrixXd R_lidar_;
    };
} // namespace UstarFusion

#endif