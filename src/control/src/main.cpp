

#include <ros/ros.h>

#include "control/control.h"
using namespace UstarController;
int main(int argc, char **argv)
{
	ros::init(argc, argv, "controller");

	Controller con;
	con.start();
	ros::spin();

	return (0);
}
