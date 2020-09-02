

#include <ros/ros.h>

#include "gmapping/gmapping.h"
using namespace UstarSlam;
int main(int argc, char **argv)
{
	ros::init(argc, argv, "gmapping_node");

	UstarGMapping gn;
	gn.startLiveSlam();
	ros::spin();

	return (0);
}
