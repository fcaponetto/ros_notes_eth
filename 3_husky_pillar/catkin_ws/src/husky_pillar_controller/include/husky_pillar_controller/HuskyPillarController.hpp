#pragma once

#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include "sensor_msgs/LaserScan.h"

namespace husky_pillar_controller {

/*!
 * Class containing the Husky Highlevel Controller
 */
class HuskyPillarController {
public:
	/*!
	 * Constructor.
	 */
	HuskyPillarController(ros::NodeHandle& nodeHandle);

	/*!
	 * Destructor.
	 */
	virtual ~HuskyPillarController();

private:
	//! ROS topic subscriber.
	ros::Subscriber subscriber_;
	//! ROS topic publisher.
	ros::Publisher pub_husky_twist_;
	//! ROS node handle.
	ros::NodeHandle nodeHandle_;

	/* Parameters from YAML file */
	std::string topic_name_;
	std::int32_t topic_size_queue_;

	/*!
	* ROS topic callback method.
	* @param message the received message.
	*/
	void scanCallback(const sensor_msgs::LaserScan& msg);
};

} /* namespace */
