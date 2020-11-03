#!/usr/bin/env python2.7
# -*- coding: utf-8 -*-

import rospy
import tf
from nav_msgs.msg import Odometry
from geometry_msgs.msg import Twist
import csv
import time
now_time = time.strftime('%Y-%m-%d-%H-%M-%S', time.localtime(time.time()))
file_name = "/home/boocax/UstarService/src/drivers/universal_robot/data/"
head = ["cmd_vel_x", "cmd_angle", "cmd_pos_x", "cmd_pos_y", "cmd_distance", 
        "odom_vel_x", "odom_angle", "odom_pos_x", "odom_pos_y", "odom_distance"]
file_open = open(file_name + now_time + ".csv", "w")
csv_writer = csv.writer(file_open)
csv_writer.writerow(head)
cmd_vel_x_ = 0.0
cmd_angle_ = 0.0
cmd_pos_x_ = 0.0
cmd_pos_y_ = 0.0
cmd_distance_ = 0.0

odom_vel_x_ = 0.0
odom_angle_ = 0.0
odom_pos_x_ = 0.0
odom_pos_y_ = 0.0
odom_distance_ = 0.0
def velocityInfoCallback(msg):
        global cmd_vel_x_
        rospy.loginfo("Subscribe vel Info: x:%s z:%d", msg.linear.x, msg.angular.z)
        cmd_vel_x_ = msg.linear.x
       

def odomInfoCallback(msg):
        global cmd_vel_x_, cmd_angle_, cmd_pos_x_, cmd_pos_y_, cmd_distance_ 
        global odom_vel_x_, odom_angle_, odom_pos_x_, odom_pos_y_, odom_distance_
        rospy.loginfo("Subscribe vel Info: x:%s  y:%d  z:%d", msg.twist.twist.linear.x, msg.twist.twist.linear.y, msg.twist.twist.linear.z)
        (r, p, y) = tf.transformations.euler_from_quaternion([msg.pose.pose.orientation.x, msg.pose.pose.orientation.y, msg.pose.pose.orientation.z, msg.pose.pose.orientation.w])
        odom_angle_ = y
        odom_vel_x_ = msg.twist.twist.linear.x
        odom_pos_x_ = msg.pose.pose.position.x
        odom_pos_y_ = msg.pose.pose.position.y
        
        csv_writer.writerow([cmd_vel_x_, cmd_angle_, cmd_pos_x_, cmd_pos_y_, cmd_distance_,
                         odom_vel_x_, odom_angle_, odom_pos_x_, odom_pos_y_, odom_distance_])
                


def main():
        odom_node = rospy.init_node("odom_test_node", anonymous=True)
        odom_info_sub = rospy.Subscriber("/odom", Odometry, odomInfoCallback)
        vel_info_sub = rospy.Subscriber("/cmd_vel", Twist, velocityInfoCallback)
        rospy.spin()
        file_open.close()

if __name__ == '__main__':
    main()