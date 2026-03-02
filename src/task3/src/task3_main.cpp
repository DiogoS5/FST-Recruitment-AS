#include "ros/ros.h"
#include "task3_handle.hpp"


int main(int argc, char** argv) {

	ros::init(argc, argv, "task3_node");

	ros::NodeHandle nh;
	Task3Handle task3Handle(nh);

	ros::Rate loop_rate(10);

	while (ros::ok()) {

		task3Handle.run();	// run node

		ros::spinOnce();			// Keeps node alive basically
		loop_rate.sleep();		// Sleep for loop_rate
	}

	return 0;
}
