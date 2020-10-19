#! /bin/bash
source /opt/ros/kinetic/setup.sh
source ~/UstarService/devel/setup.bash

gnome-terminal --tab -e 'roslaunch simulator stage.launch' -t 3 --tab -e 'roslaunch simulator gmapping.launch'
