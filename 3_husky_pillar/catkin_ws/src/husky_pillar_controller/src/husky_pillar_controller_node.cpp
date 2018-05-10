#include <ros/ros.h>
#include "husky_pillar_controller/HuskyPillarController.hpp"

int main(int argc, char** argv)

{
  ros::init(argc, argv, "husky_pillar_controller");
  ros::NodeHandle nodeHandle("~");

  husky_pillar_controller::HuskyPillarController huskyPillarController(nodeHandle);

  ros::spin();
  return 0;
}
