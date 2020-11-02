#!/usr/bin/env python
# -*- coding: utf-8 -*-

import rospy
from nav_msgs.msg import Odometry
from geometry_msgs.msg import Twist
from queue import Queue

cmd_velx_q = Queue()
cmd_angle_q = Queue()
odom_velx_q = Queue()
odom_angle_q = Queue()

def velocityInfoPublisher(vel_info_pub, rate):
        while not rospy.is_shutdown():
                vel_msg = Twist()
                vel_msg.linear.x = 0.0
                vel_msg.linear.y = 0.0
                vel_msg.angular.z = 0.0
                cmd_velx_q.put(vel_msg.linear.x)
                cmd_angle_q.put(vel_msg.angular.z)
                vel_info_pub.publish(vel_msg)
                if (cmd_velx_q.qsize() >= 10):
                        cmd_velx_q.get()
                        cmd_angle_q.get()
                rospy.loginfo("Publish vel message[%s, %d, %d]", vel_msg.linear.x, vel_msg.linear.y, vel_msg.angular.z)
                rate.sleep()

def odomInfoCallback(msg):
    rospy.loginfo("Subscribe vel Info: x:%s  y:%d  z:%d", msg.twist.twist.linear.x, msg.twist.twist.linear.y, msg.twist.twist.linear.z)
    odom_velx_q.put(msg.twist.twist.linear.x)
    odom_angle_q.put(msg.twist.twist.angular)
    if (odom_velx_q.qsize() >= 10):
        odom_velx_q.get()
        odom_angle_q.get()

def main():
        odom_node = rospy.init_node("odom_test_node", anonymous=True)
        odom_info_sub = rospy.Subscriber("/odom", Odometry, odomInfoCallback)
        #rospy.spin()

        vel_info_pub = rospy.Publisher('/cmd_vel', Twist, queue_size=10)
        rate = rospy.Rate(10)
        velocityInfoPublisher(vel_info_pub, rate)

if __name__ == '__main__':
    main()
