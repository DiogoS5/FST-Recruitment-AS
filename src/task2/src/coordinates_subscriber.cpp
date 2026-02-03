#include "ros/ros.h"
#include "geometry_msgs/Point.h"

void callback(const geometry_msgs::Point::ConstPtr& msg){
    ROS_INFO("Received: (%f, %f, %f)", msg->x, msg->y, msg->z );
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "Subscriber");
    ros::NodeHandle n;

    ros::Subscriber test_sub;
    test_sub = n.subscribe("coordinates", 1000, callback);

    ros::spin();

    return 0;
}