#include "ros/ros.h"
#include "project1/WeatherStatusCheck.h"

bool determineWeatherStatus(project1::WeatherStatusCheck::Request &req,
                      project1::WeatherStatusCheck::Response &res)
{
  string GPS_location = req.GPS_location ;

  if(GPS_location == "q" )
  {
    res.answer = "Cool";
    
    return false;
    
  }
  else 
  { 
  return true;
  }
}


int main(int argc, char **argv)
{
  ros::init(argc, argv, "weather_status_service_server_node");

  ros::NodeHandle node_handle;

  ros::ServiceServer service = node_handle.advertiseService("weather_status_check", determineWeatherStatus);

  ROS_INFO("Weather Status Check Server Running...");

  ros::spin();

  return 0;
}
