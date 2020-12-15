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

    ~SensorFusion::SensorFusion()
    {
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
        double delta_t = (lidar_data.timestamp - last_timestamp_) / 1000000.0;
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