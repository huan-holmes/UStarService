#include <ros/ros.h>

#include "markers_node.h"




int main(int argc, char **argv)
{
    ros::init(argc, argv, "ustar_sim_node");

    UStarSlam::UStarSimulation uss;
    uss.run();
    ros::spinOnce();

    return(0);
}