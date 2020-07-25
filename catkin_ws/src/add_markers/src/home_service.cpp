#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include <nav_msgs/Odometry.h>
#include <math.h>
#include <geometry_msgs/PoseWithCovarianceStamped.h>

visualization_msgs::Marker marker;
ros::Publisher marker_pub;
float startx = 3.0;
float starty = 0.0;
float goalx = 4.0;
float goaly = 4.0;
bool start = false;
bool goal = false;

void robPoseCallback(const geometry_msgs::PoseWithCovarianceStamped::ConstPtr& msg) {
    
  double robotX = msg->pose.pose.position.x;
  double robotY = msg->pose.pose.position.y;
  ROS_INFO("Received nav_msgs");

  if(std::abs(msg->pose.pose.position.x - startx) < 0.3 && std::abs(msg->pose.pose.position.y - starty) < 0.3 && marker.action == visualization_msgs::Marker::ADD){
    marker.action = visualization_msgs::Marker::DELETE;
    marker_pub.publish(marker);
    ROS_INFO(" picked up");
  }
  if(std::abs(msg->pose.pose.position.x - goalx) < 0.3 && std::abs(msg->pose.pose.position.y - goaly) < 0.3 && marker.action == visualization_msgs::Marker::DELETE){
    marker.action = visualization_msgs::Marker::ADD;
    marker.pose.position.x = goalx;
    marker.pose.position.y = goaly;
    marker_pub.publish(marker);
    ROS_INFO(" droped out");
  }
}


int main( int argc, char** argv )
{
  ros::init(argc, argv, "home_service");
  ros::NodeHandle n;
  marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 1);
  ros::Subscriber amcl_sub = n.subscribe("amcl_pose", 10, robPoseCallback);

  // Set our initial shape type to be a cube
  uint32_t shape = visualization_msgs::Marker::CUBE;

  // Set the frame ID and timestamp.  See the TF tutorials for information on these.
  marker.header.frame_id = "map";
  marker.header.stamp = ros::Time::now();

  // Set the namespace and id for this marker.  This serves to create a unique ID
  // Any marker sent with the same namespace and id will overwrite the old one
  marker.ns = "cube";
  marker.id = 0;

  // Set the marker type.  Initially this is CUBE, and cycles between that and SPHERE, ARROW, and CYLINDER
  marker.type = shape;

  // Set the pose of the marker.  This is a full 6DOF pose relative to the frame/time specified in the header
  marker.pose.position.x = startx;
  marker.pose.position.y = starty;
  marker.pose.position.z = 0;
  marker.pose.orientation.x = 0.0;
  marker.pose.orientation.y = 0.0;
  marker.pose.orientation.z = 0.0;
  marker.pose.orientation.w = 1.0;
  // Set the scale of the marker -- 1x1x1 here means 1m on a side
  marker.scale.x = 0.5;
  marker.scale.y = 0.5;
  marker.scale.z = 0.5;

  // Set the color -- be sure to set alpha to something non-zero!
  marker.color.r = 0.0f;
  marker.color.g = 0.0f;
  marker.color.b = 1.0f;
  marker.color.a = 1.0;

  marker.lifetime = ros::Duration();
  while (ros::ok())
  {
    // Publish the marker
    while (marker_pub.getNumSubscribers() < 1)
    {
      if (!ros::ok())
      {
        return 0;
      }
      ROS_WARN_ONCE("Please create a subscriber to the marker");
      sleep(1);
    }
    
    marker_pub.publish(marker);
    ros::spinOnce();
  }
}