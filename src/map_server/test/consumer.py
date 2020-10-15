from __future__ import print_function

PKG = 'static_map_server'
NAME = 'consumer'

import sys
import unittest
import time

import rospy
import rostest
from nav_msgs.srv import GetMap


class TestConsumer(unittest.TestCase):
    def __init__(self, *args):
        super(TestConsumer, self).__init__(*args)
        self.success = False

    def callback(self, data):
        print(rospy.get_caller_id(), "I heard %s" % data.data)
        self.success = data.data and data.data.startswith('hello world')
        rospy.signal_shutdown('test done')

    def test_consumer(self):
        rospy.wait_for_service('static_map')
        mapsrv = rospy.ServiceProxy('static_map', GetMap)
        resp = mapsrv()
        self.success = True
        print(resp)
        while not rospy.is_shutdown() and not self.success:  # and time.time() < timeout_t: <== timeout_t doesn't exists??
            time.sleep(0.1)
        self.assert_(self.success)
        rospy.signal_shutdown('test done')

if __name__ == '__main__':
    rostest.rosrun(PKG, NAME, TestConsumer, sys.argv)
