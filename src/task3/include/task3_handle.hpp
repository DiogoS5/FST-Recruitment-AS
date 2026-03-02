#ifndef TASK3_HANDLE_HPP
#define TASK3_HANDLE_HPP

#include "ros/ros.h"
#include "task3.hpp"


class Task3Handle {

	public:

		// constructor
		Task3Handle(ros::NodeHandle &nodeHandle);

		// methods
		void run();

	private:

		// attributes
		ros::NodeHandle _nodeHandle;
		ros::Publisher _pubOutput;
		ros::Subscriber _subInput;
		Task3 _task3;		// instance of the algorithm itself

		// callbacks
		void inputCallback(const task2::coords_2d_array& input);

};

#endif
