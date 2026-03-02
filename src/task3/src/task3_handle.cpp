#include "task3_handle.hpp"		// include header file


Task3Handle::Task3Handle(ros::NodeHandle &nodeHandle): _nodeHandle(nodeHandle) {
	_subInput = _nodeHandle.subscribe("coordinates", 10, &Task3Handle::inputCallback, this);
	_pubOutput = _nodeHandle.advertise<visualization_msgs::MarkerArray>("visualization_marker_array", 10);
}

void Task3Handle::run() {
	_task3.runAlgorithm();
	_pubOutput.publish(_task3.getOutput());	// get info from algorithm and publish it
}

void Task3Handle::inputCallback(const task2::coords_2d_array& input) {
	_task3.setInput(input);		// pass info to algorithm
}
