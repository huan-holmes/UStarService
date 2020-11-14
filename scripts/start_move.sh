#! /bin/bash
source /opt/ros/kinetic/setup.sh
source ~/UstarService/devel/setup.bash
gnome-terminal --tab -e 'bash -c "roslaunch move_base ustar_move.launch"' 
sleep 5
#gnome-terminal --tab -e 'bash -c "rosrun rqt_reconfigure rqt_reconfigure"'
