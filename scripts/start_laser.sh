#！/bin/bash
source /opt/ros/melodic/setup.bash
source /home/mingo/UStarService/devel/setup.bash
### start gmapping ##############################
###roslaunch ustar_slam demo_gmapping1.launch
### start laser ################################
roslaunch ustar_slam ustar_laser.launch
