#! /bin/bash
source /opt/ros/kinetic/setup.sh
source ~/UstarService/devel/setup.bash

bag_file=~/UstarService/src/fusion/radar_process/data/3.bag

move=0


gnome-terminal -x bash -c "roslaunch mapping gmapping.launch"
if [ $? -eq 0 ]; then
	sleep 3
	gnome-terminal --tab -e 'bash -c "roslaunch radar_process test_pcl.launch"' 
	move=1
else
	echo "stage start falied"
fi
sleep 3
gnome-terminal -x bash -c "rosbag play --clock -l $bag_file"
