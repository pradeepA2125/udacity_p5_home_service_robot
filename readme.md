# Robotics-nanodegree-Home-Service-Robot
Project 5 of Udacity Robotics Software Engineer Nanodegree


### slam test
`test_slam.sh` script file to launch it for manual mapping test.

### Localization and Navigation  
`test_navigation.sh` script file to launch it for manual navigation test.  
Your robot should be able to navigate in the environment after a 2D Nav Goal command is issued.  
`pick_objects.sh` file that will send multiple goals for the robot to reach.  
 robot displays a message that it reached its destination, waits 5 seconds, travels to the desired drop off zone, and displays a message that it reached the drop off zone."  
### Home Service Functions  
 `add_marker.sh` file that will publish a marker to rviz.  
The home service robot should be simulated as follow:  
* Initially show the marker at the pickup zone.
* Hide the marker once your robot reach the pickup zone.
* Wait 5 seconds to simulate a pickup.
* Show the marker at the drop off zone once your robot reaches it.

### launch files have been configured for the custom map and world created in earlier projects
* rviz config has been saved to default space direcltly and markers can be seen in rviz as view_navigation.launch is launced

following ROS packages were used and the process of obtaining them is detailed below:
* gmapping
* turtlebot_teleop
* turtlebot_rviz_launchers
* turtlebot_gazebo

