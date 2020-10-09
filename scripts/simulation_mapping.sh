#! /bin/bash
source /opt/ros/kinetic/setup.sh
source ~/UstarService/devel/setup.bash
move=0

gnome-terminal -x bash -c "roslaunch simulator stage.launch"
if [ $? -eq 0 ]; then
	sleep 3
	gnome-terminal --tab -e 'bash -c "roslaunch simulator gmapping.launch"' 
	move=1
else
	echo "gmapping start falied"
fi
if [ $move -eq 1 ]; then
	sleep 4
	gnome-terminal --tab -e 'bash -c "roslaunch turtlebot_teleop keyboard_teleop.launch"'
else
	echo "keyboard start failed"
fi
