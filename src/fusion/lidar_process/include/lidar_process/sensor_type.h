#ifndef SENSOR_TYPE_H_
#define SENSOR_TYPE_H_
namespace UstarFusion
{
    struct LidarClusterType
    {
        Eigen::VectorXd raw_data;
        long long timestamp;
    };
    
}
#endif