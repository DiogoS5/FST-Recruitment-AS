#include "task3.hpp"		


// constructor
Task3::Task3() {}

// getter
visualization_msgs::MarkerArray Task3::getOutput() {
	return _output;
}

// setter
void Task3::setInput(const task2::coords_2d_array inputData) {
	_input = inputData;		// save value
}

void Task3::runAlgorithm() {
	_output.markers.clear();

	const auto& _coordinates = _input.coordinates;

	for (int i=0; i < _coordinates.size(); ++i) {
		visualization_msgs::Marker marker;
		marker.header.frame_id = "map";
		marker.header.stamp = ros::Time::now();
		marker.ns = "coordinates";
		marker.id = i;
		marker.type = visualization_msgs::Marker::SPHERE;
		marker.action = visualization_msgs::Marker::ADD;
		marker.pose.position.x = _coordinates[i].x; 
		marker.pose.position.y = _coordinates[i].y;
		marker.pose.position.z = 0; 
		marker.pose.orientation.x = 0.0; marker.pose.orientation.y = 0.0; 
		marker.pose.orientation.z = 0.0; marker.pose.orientation.w = 1.0;
		marker.scale.x = 0.2; marker.scale.y = 0.2; marker.scale.z = 0.2;
		marker.color.a = 1.0; marker.color.r = 0.0; marker.color.g = 1.0; 
		marker.color.b = 0.0;

		_output.markers.push_back(marker);
	}
}
