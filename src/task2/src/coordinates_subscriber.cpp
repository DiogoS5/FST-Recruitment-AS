#include "ros/ros.h"
#include "task2/coords_2d_array.h"
#include "visualization_msgs/MarkerArray.h"

class CoordinateSubscriber {
public:
    CoordinateSubscriber() : 
        n(), 
        sub(n.subscribe("coordinates", 10, &CoordinateSubscriber::callback, this)),
        pub(n.advertise<visualization_msgs::MarkerArray>("visualization_marker_array", 10)) 
    {}
private:
    ros::NodeHandle n;
    ros::Publisher pub;
    ros::Subscriber sub;

    void callback(const task2::coords_2d_array::ConstPtr& msg){
        ROS_DEBUG("Received coordinates");

        visualization_msgs::MarkerArray marker_array;

        for (int i=0; i < msg->coordinates.size(); ++i) {
            visualization_msgs::Marker marker;
            marker.header.frame_id = "map";
            marker.header.stamp = ros::Time::now();
            marker.ns = "coordinates";
            marker.id = i;
            marker.type = visualization_msgs::Marker::SPHERE;
            marker.action = visualization_msgs::Marker::ADD;
            marker.pose.position.x = msg->coordinates[i].x; 
            marker.pose.position.y = msg->coordinates[i].y;
            marker.pose.position.z = 0; 
            marker.pose.orientation.x = 0.0; marker.pose.orientation.y = 0.0; 
            marker.pose.orientation.z = 0.0; marker.pose.orientation.w = 1.0;
            marker.scale.x = 0.2; marker.scale.y = 0.2; marker.scale.z = 0.2;
            marker.color.a = 1.0; marker.color.r = 0.0; marker.color.g = 1.0; 
            marker.color.b = 0.0;

            marker_array.markers.push_back(marker);
        }

        pub.publish(marker_array);
        ROS_DEBUG("Published marker array");
    }
};



int main(int argc, char **argv) {
    ros::init(argc, argv, "Subscriber");

    CoordinateSubscriber coordinate_subscriber;

    ros::spin();

    return 0;
}