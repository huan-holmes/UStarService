#include "ros/ros.h"
#include "std_srvs/Empty.h"
#include <unistd.h>
int main(int argc, char** argv)
{
    ros::init(argc, argv, "amcl_location_node");
    ros::NodeHandle n;
    ros::ServiceClient client = n.serviceClient<std_srvs::Empty>("global_localization");
    std_srvs::Empty srv;

    int trytimes = 0;
    while(!(client.call(srv)) && trytimes < 5)
    {
        ROS_ERROR("Failed call global localization");
        trytimes++;
        sleep(1);
        continue;
    }
    if(trytimes == 5)
    {
        ROS_ERROR("Has try 5 times No useful!!!!!!!");
    }
    else
    {
        ROS_INFO("call global localization successful");
    }
    return 0;
}
