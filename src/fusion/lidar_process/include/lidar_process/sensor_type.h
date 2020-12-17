#ifndef SENSOR_TYPE_H_
#define SENSOR_TYPE_H_
#include "Eigen/Dense"
namespace UstarFusion
{
    struct LidarClusterType
    {
        Eigen::VectorXd raw_data;
        long timestamp;
        int obstacle_id;
        int lose_count;
    };
    
}
#endif