#include <ros/ros.h>

#include "ustar_sim_node.h"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "ustar_sim_node");

    Simulation::UStarSimulation uss;
    
    while (ros::ok())
    {
        uss.run();
        ros::spinOnce();
    }
    return (0);
}