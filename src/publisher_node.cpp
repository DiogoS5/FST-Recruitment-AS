#include "ros/ros.h"
#include "std_msgs/Int32.h"

int main(int argc, char **argv) {
    ros::init(argc, argv, "Publisher");
    ros::NodeHandle n;

    ros::Publisher test_pub;
    test_pub = n.advertise<std_msgs::Int32>("test", 1000);

    ros::Rate loop_rate(1);

    while(ros::ok()) {
        std_msgs::Int32 msg;
        if(!(std::cin >> msg.data)){
            std::cout << "Please enter a valid integer\n";
        };

        test_pub.publish(msg);

        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}