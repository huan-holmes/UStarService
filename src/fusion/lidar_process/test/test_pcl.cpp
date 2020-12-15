#include "lidar_process/filter.h"
using namespace UstarFusion;
int main(int argc, char** argv)
{
    ros::init(argc, argv, "my_pcl_node");

    LaserFilter filter;
    filter.startFilter();
    ros::spin();

    return 0;
}