#pragma once

#include <ros/ros.h>
#include "sensor_msgs/LaserScan.h"

namespace husky_highlevel_controller {

/*!
 * Class containing the Husky Highlevel Controller
 */
class HuskyHighlevelController {
public:
	/*!
	 * Constructor.
	 */
	HuskyHighlevelController(ros::NodeHandle& nodeHandle);

	/*!
	 * Destructor.
	 */
	virtual ~HuskyHighlevelController();

private:
	//! ROS topic subscriber.
	ros::Subscriber subscriber_;
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
