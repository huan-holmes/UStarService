#include <ros/ros.h>

#include "ustar_sim_node.h"




int main(int argc, char **argv)
{
    ros::init(argc, argv, "ustar_sim_node");

    Simulation::UStarSimulation uss;
    uss.run();
    ros::spinOnce();

    return(0);
}