#include "ros/ros.h"
#include <geometry_msgs/Twist.h>

class PublishVelocity
{
    public:
        PublishVelocity();
        ~PublishVelocity();
        void velocityInfoPublisher();
        void run();

    private:
        ros::NodeHandle nh_;
        ros::Publisher cmd_vel_pub_;
        ros::Rate rate_;

        geometry_msgs::Twist cmd_vel_;


        double vel_x_;
        double vel_y_;
        double angle_z_;


};

int main(int argc, char **argv)
{
    ros::init(argc, argv, "cmd_test_node");
    PublishVelocity velpub;
    while (ros::ok())
    {
        velpub.run();
        ros::spinOnce();
        
    }
    return(0);
}

PublishVelocity::PublishVelocity() : rate_(10), vel_x_(0.2), vel_y_(0.0), angle_z_(0.0)
{

}

PublishVelocity::~PublishVelocity()
{

}

void PublishVelocity::run()
{
    cmd_vel_pub_ = nh_.advertise<geometry_msgs::Twist>("cmd_test_topic", 10);
    velocityInfoPublisher();
}

void PublishVelocity::velocityInfoPublisher()
{
    cmd_vel_.linear.x = vel_x_;
    cmd_vel_.linear.y = vel_y_;
    cmd_vel_.angular.z = angle_z_;
    cmd_vel_pub_.publish(cmd_vel_);
    rate_.sleep();
}