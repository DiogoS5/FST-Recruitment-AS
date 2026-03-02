#ifndef TASK3_HPP
#define TASK3_HPP

#include "visualization_msgs/MarkerArray.h"
#include "task2/coords_2d_array.h"

class Task3 {
	
	public:

		// constructor
		Task3();

		// getters
		visualization_msgs::MarkerArray getOutput();

		// setters
		void setInput(const task2::coords_2d_array inputData);
		
		// methods
		void runAlgorithm();

	private:

		// attributes
		task2::coords_2d_array _input;
		visualization_msgs::MarkerArray _output;
};

#endif
