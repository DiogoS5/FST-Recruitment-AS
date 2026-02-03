#include "ros/ros.h"
#include "task2/coords_2d_array.h"
#include <string>

class CoordinatePublisher {
public:
    CoordinatePublisher() : n(), pub(n.advertise<task2::coords_2d_array>("coordinates", 1000)) {
        loadParams();
    }

    void publish() {
        if (pub) {
            pub.publish(msg);
            ROS_INFO("Published coordinates");
        } else {
            ROS_ERROR("Publisher not initialized!");
        }
    }

private:
    ros::NodeHandle n;
    ros::Publisher pub;
    task2::coords_2d_array msg;

    void loadParams() {
        XmlRpc::XmlRpcValue coordinate_list;

        if (n.getParam("/coordinates", coordinate_list)) {
            for (int i = 0; i < coordinate_list.size(); ++i) {
                task2::coords_2d c;
                // Have to convert from XmlRpc type
                c.x = static_cast<double>(coordinate_list[i]["x"]);
                c.y = static_cast<double>(coordinate_list[i]["y"]);
                
                msg.coordinates.push_back(c);
            }
            ROS_INFO("Successfully loaded coordinates from parameter server");
        } else {
            ROS_ERROR("Failed to load coordinates from parameter server!");
        }
    }
};

int main(int argc, char** argv) {
    ros::init(argc, argv, "coordinates_publisher");
    
    CoordinatePublisher coordinates_pub;

    ros::Rate loop_rate(1);

    while(ros::ok()) {
        task2::coords_2d_array coordinates;
        
        coordinates_pub.publish();

        ros::spinOnce();
        loop_rate.sleep();
    }
}
