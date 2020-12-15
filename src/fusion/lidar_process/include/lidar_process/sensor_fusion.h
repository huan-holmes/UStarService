#ifndef SENSOR_FUSION_H_
#define SENSOR_FUSION_H_
#include "lidar_process/kalman_filter.h"
#include "lidar_process/sensor_type.h"
namespace UstarFusion
{
    class SensorFusion
    {
    public:
        SensorFusion();
        ~SensorFusion();

        void Process(LidarClusterType lidar_data);

        KalmanFilter kf_;
    private:
        bool is_initialized_;
        long last_timestamp_;
        Eigen::MatrixXd H_lidar_;
        Eigen::MatrixXd R_lidar_;
    }
} // namespace UstarFusion

#endif