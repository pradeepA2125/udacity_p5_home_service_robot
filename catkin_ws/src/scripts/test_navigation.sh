#!/bin/sh
xterm  -e "cd /home/workspace/catkin_ws; source devel/setup.bash ; roslaunch turtlebot_gazebo turtlebot_world.launch  world_file:=/home/workspace/catkin_ws/src/maps/rb.world" &
sleep 5
xterm -e "cd /home/workspace/catkin_ws; source devel/setup.bash ; roslaunch turtlebot_gazebo amcl_demo.launch map_file:=/home/workspace/catkin_ws/src/maps/map.yaml " &
sleep 5
xterm  -e "cd /home/workspace/catkin_ws; source devel/setup.bash ; roslaunch turtlebot_rviz_launchers view_navigation.launch" &