#include "ros/ros.h"

#include "std_msgs/Float32.h"

float WHEEL_RADIUS;

float Speed;

const float RPM = 60;

ros::Subscriber speed_sub;

ros::Publisher rpm_pub;

int main(int argc, char **argv)
{
  ros::init(argc, argv, "speed_calc_node");

  ros::NodeHandle node_handle;

  rpm_pub = node_handle.advertise<std_msgs::Float32>("rpm", 10);

  ros:: Publisher speed_pub = node_handle.advertise<std_msgs::Float32>("speed", 10);

  ros::Rate pub_rate(10);

  ROS_INFO("Publishing Speed...");

  while(ros::ok())
  {

    std_msgs::Float32 speed_msg;

    speed_msg.data = Speed;

    speed_pub.publish(speed_msg);

    pub_rate.sleep();
  }
}
