#!/usr/bin/env python
# -*- coding: utf-8 -*-

import rospy
from nav_msgs.msg import Odometry
from geometry_msgs.msg import Twist

def velocity_publisher():
	# ROS节点初始化
    rospy.init_node('vel_publisher', anonymous=True)

	# 创建一个Publisher，发布名为/person_info的topic，消息类型为learning_topic::Person，队列长度10
    vel_info_pub = rospy.Publisher('/cmd_vel', Twist, queue_size=10)

	#设置循环的频率
    rate = rospy.Rate(10) 

    while not rospy.is_shutdown():
		# 初始化learning_topic::Person类型的消息
    	vel_msg = Twist()
    	vel_msg.linear.x = 0.0
    	vel_msg.linear.y = 0.0
    	vel_msg.angular.z = 0.0
		vel_info_pub.publish(vel_msg)
        rospy.loginfo("Publsh vel message[%s, %d, %d]", vel_msg.linear.x, vel_msg.linear.y, vel_msg.angular.z)

		# 按照循环频率延时
        rate.sleep()

def odomInfoCallback(msg):
    rospy.loginfo("Subcribe vel Info: x:%s  y:%d  z:%d", 
			 msg.linear.x, msg.linear.y, msg.angular.z)

def odom_subscriber():
	# ROS节点初始化
    rospy.init_node('odom_subscriber', anonymous=True)

	# 创建一个Subscriber，订阅名为/person_info的topic，注册回调函数personInfoCallback
    rospy.Subscriber("/odom", Odometry, odomInfoCallback)

	# 循环等待回调函数
    rospy.spin()


if __name__ == '__main__':
    odom_subscriber()