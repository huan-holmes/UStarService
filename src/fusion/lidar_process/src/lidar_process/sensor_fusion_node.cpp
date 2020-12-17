#include "lidar_process/sensor_fusion.h"
using namespace UstarFusion;

int main(int argc, char** argv)
{
    ros::init(argc, argv, "sensor_fusion_node");
    SensorFusion sf;
    
    while (ros::ok())
    {
        sf.run();
        ros::spinOnce();
        //ros::Rate(10).sleep();
    }
    return 0;
}
