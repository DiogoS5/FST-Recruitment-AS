#include "ros/ros.h"
#include "std_msgs/Int32.h"

void testCallback(const std_msgs::Int32::ConstPtr& msg){
    ROS_INFO("Received: [%d]", msg->data);
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "Subscriber");
    ros::NodeHandle n;

    ros::Subscriber test_sub;
    test_sub = n.subscribe("test", 1000, testCallback);

    ros::spin();

    return 0;
}