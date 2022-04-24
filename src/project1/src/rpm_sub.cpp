#include "ros/ros.h"

#include "std_msgs/Float32.h"

const float RPM = 60;

float WHEEL_RADIUS;

float Speed;

ros::Subscriber speed_sub;

ros::Publisher rpm_pub;

void subCallback(const std_msgs::Float32::Ptr& rpm)
{
  
  ros::NodeHandle callback_node_handle;
  
  if (callback_node_handle.getParam("wheel_radius", WHEEL_RADIUS))
   {
      std_msgs::Float32 speed_msg;

      // Speed = Circumference * Rev/s
      Speed = speed_msg.data = (2 * WHEEL_RADIUS * 3.14159) * (rpm->data / 60);

      std_msgs::Float32 msg;

      msg.data = RPM;

      rpm_pub.publish(msg);
   }
   else 
   {
      ROS_WARN(" speed_limit is crossed.");
   }
  
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "rpm_sub_node");

  ros::NodeHandle node_handle;

  rpm_pub = node_handle.advertise<std_msgs::Float32>("rpm", 10);

  ros::Subscriber speed_calc = node_handle.subscribe("speed", 10, subCallback);

  ros::spin( );

  return 0;
}
