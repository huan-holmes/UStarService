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

def velocityInfoCallback(msg):
       rospy.loginfo("Subscribe vel Info: x:%s z:%d", msg.linear.x, msg.angular.z)
       cmd_velx_q.put(msg.linear.x)
       cmd_angle_q.put(msg.angular.z) 
       if (cmd_velx_q.qsize() >= 10): 
                cmd_velx_q.get()
                cmd_angle_q.get()

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
        vel_info_sub = rospy.Subscriber("/cmd_test_topic", Twist, velocityInfoCallback)
        rospy.spin()
if __name__ == '__main__':
    main()
