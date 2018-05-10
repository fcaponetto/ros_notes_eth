#include "husky_pillar_controller/HuskyPillarController.hpp"

namespace husky_pillar_controller {

HuskyPillarController::HuskyPillarController(ros::NodeHandle& nodeHandle) :
		  nodeHandle_(nodeHandle)
{
	// check if the parameters exists, and if not exists send error and shutdown
	//    if (!(nodeHandle.getParam("scan_topic_name", topic_name_)
	//            & nodeHandle.getParam("scan_topic_queue_size", topic_size_queue_))) {
	//      ROS_ERROR("Could not read parameters.");
	//      ros::requestShutdown();
	//    }

	topic_name_ = "/scan";
	topic_size_queue_ = 1;

	// create a subscriber to the topic_name
	subscriber_ = nodeHandle_.subscribe(topic_name_, topic_size_queue_,
			&HuskyPillarController::scanCallback, this);

	pub_husky_twist_ =
			nodeHandle_.advertise<geometry_msgs::Twist>("/husky_velocity_controller/cmd_vel", 10);
	ROS_INFO("Successfully launched node.");
}

HuskyPillarController::~HuskyPillarController()
{
}

void HuskyPillarController::scanCallback(const sensor_msgs::LaserScan& msg) {
	// search for the min value in the vector of msg.ranges
	std::vector<float> ranges = msg.ranges;
	float theta = 0.0;      //Turn angle.
	auto min_idx = 0;       //Index of distance of pillar.
	geometry_msgs::Twist cmd_msg;

	float small = ranges[0];
	for (int i = 0; i < ranges.size(); ++i)
	{
		float v = ranges[i];
		if(small > v)
		{
			small = v;
			min_idx = i;
		}
	}

    //Calculates turn angle
    theta = msg.angle_min + min_idx * msg.angle_increment;

    // Set angular velocity on z axis so that Husky can turn around
    cmd_msg.angular.z = -theta;
    cmd_msg.linear.x = small;
	cmd_msg.linear.y = small;

	pub_husky_twist_.publish(cmd_msg);

	// display the ming value
	ROS_INFO_STREAM("Pillar range: " + std::to_string(small));
	ROS_INFO_STREAM("Pillar turn angle: " + std::to_string(-theta));

}

}/* namespace */


