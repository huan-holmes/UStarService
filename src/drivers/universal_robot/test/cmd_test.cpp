#include "ros/ros.h"
#include <geometry_msgs/Twist.h>
#include <dynamic_reconfigure/server.h>
#include <universal_robot/CmdTestConfig.h>
#include <nav_msgs/Odometry.h>
#include "tf/transform_datatypes.h"
#include "tf/LinearMath/Matrix3x3.h"
#include <tf/transform_listener.h>
class PublishVelocity
{
    public:
        PublishVelocity();
        ~PublishVelocity();
        void velocityInfoPublisher();
        void run();
        void reconfigureCB(universal_robot::CmdTestConfig &config, uint32_t level);
        void odomCallback(const nav_msgs::Odometry &msg);
    private:
        ros::NodeHandle nh_;
        tf::TransformListener tf_listener_;
        ros::Publisher cmd_vel_pub_;

        ros::Subscriber odom_sub_;
        double theta_;
        double distance_;

        std::string base_frame_;
        std::string odom_frame_;

        double dest_distance_;
        double tolerance_distance_;
        
        geometry_msgs::Twist cmd_vel_;

        dynamic_reconfigure::Server<universal_robot::CmdTestConfig> *dsrv_;
        


        double vel_x_;
        double vel_y_;
        double angle_z_;


};

int main(int argc, char **argv)
{
    ros::init(argc, argv, "cmd_test_node");
    PublishVelocity velpub;
    ros::Rate rate_(10);
    while (ros::ok())
    {
        velpub.run();
        ros::spinOnce();
        rate_.sleep();
    }
    return(0);
}

PublishVelocity::PublishVelocity() : vel_x_(0.2), vel_y_(0.0), angle_z_(0.4), dest_distance_(1.0), tolerance_distance_(0.01)
{
    base_frame_ = "base_link";
    odom_frame_ = "odom";
    cmd_vel_pub_ = nh_.advertise<geometry_msgs::Twist>("cmd_vel", 10);
    //odom_sub_ = nh_.subscribe("odom", 1, &PublishVelocity::odomCallback, this);
    dsrv_ = new dynamic_reconfigure::Server<universal_robot::CmdTestConfig>;
    dynamic_reconfigure::Server<universal_robot::CmdTestConfig>::CallbackType cb = boost::bind(&PublishVelocity::reconfigureCB, this, _1, _2);
    dsrv_->setCallback(cb);
}

PublishVelocity::~PublishVelocity()
{

}
void PublishVelocity::odomCallback(const nav_msgs::Odometry &msg)
{
    tf::Quaternion quat;
    tf::quaternionMsgToTF(msg.pose.pose.orientation, quat);
 
    // the tf::Quaternion has a method to acess roll pitch and yaw
    double roll, pitch, yaw;
    tf::Matrix3x3(quat).getRPY(roll, pitch, yaw);
    theta_ = atan2(sin(yaw), cos(yaw));
    distance_ = sqrt(msg.pose.pose.position.x * msg.pose.pose.position.x + msg.pose.pose.position.y * msg.pose.pose.position.y);
    ROS_INFO_STREAM(theta_);
    
    if (distance_ >= 1.0) {
        ROS_INFO_STREAM(distance_);
        vel_x_ = 0.0;
    }
}

void PublishVelocity::reconfigureCB(universal_robot::CmdTestConfig &config, uint32_t level)
{
    vel_x_ = config.velocity_x;
    vel_y_ = config.velocity_y;
    angle_z_ = config.angle_z;
}

void PublishVelocity::run()
{
    velocityInfoPublisher();   
}

void PublishVelocity::velocityInfoPublisher()
{
    tf::StampedTransform transform;
    try
    {
        tf_listener_.lookupTransform(odom_frame_, base_frame_, ros::Time(0), transform);
    }
    catch(tf::TransformException &ex)
    {
        ROS_ERROR("%s",ex.what());
        
        return;
    }
    distance_ = sqrt(pow(transform.getOrigin().x(), 2) + pow(transform.getOrigin().y(), 2));
    cmd_vel_.linear.x = 0.2;
    cmd_vel_.linear.y = 0.0;
    cmd_vel_.angular.z = 0.0; 
    // if (fabs(distance_ - dest_distance_) < tolerance_distance_) 
    // {
    //     ROS_INFO_STREAM(fabs(distance_ - dest_distance_));
    //     ROS_INFO("x: %.3lf y: %.3lf distance: %.3lf dest_distance_: %.3lf tolerance_distance: %.3lf", 
    //     transform.getOrigin().x(), transform.getOrigin().y(), distance_, dest_distance_, tolerance_distance_);
    //     cmd_vel_.linear.x = 0.0;
    //     cmd_vel_.linear.y = 0.0;
    //     cmd_vel_.angular.z = 0.0;
    //     ros::Duration(1.0).sleep();
    // } 
    // else
    // {
    //     cmd_vel_.linear.x = vel_x_;
    //     cmd_vel_.linear.y = 0.0;
    //     cmd_vel_.angular.z = 0.0; 
    // }
    cmd_vel_pub_.publish(cmd_vel_);
}