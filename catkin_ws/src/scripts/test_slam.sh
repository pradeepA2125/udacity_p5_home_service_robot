#!/bin/sh
xterm  -e "cd /home/workspace/catkin_ws; source devel/setup.bash ; roslaunch turtlebot_gazebo turtlebot_world.launch world_file:=/home/workspace/catkin_ws/src/maps/rb.world" &
sleep 5
xterm  -e "cd /home/workspace/catkin_ws; source devel/setup.bash ; roslaunch turtlebot_teleop keyboard_teleop.launch " &
sleep 5
xterm -e "cd /home/workspace/catkin_ws; source devel/setup.bash ; roslaunch turtlebot_gazebo gmapping_demo.launch  " &
sleep 5
xterm  -e "cd /home/workspace/catkin_ws; source devel/setup.bash ; roslaunch turtlebot_rviz_launchers view_navigation.launch" &