#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include "std_msgs/String.h"
#include <string>

int main(int argc, char **argv) {
    ros::init(argc, argv, "Publisher");
    ros::NodeHandle n;

    ros::Publisher test_pub;
    test_pub = n.advertise<std_msgs::Int32>("test", 1000);

    while(ros::ok()) {
        std_msgs::Int32 msg;
        std::string input;

        std::cout << "Enter a number (or q to quit): ";
        std::cin >> input;

        if (input == "q") {
            ros::shutdown();
            break; 
        }
        
        try {
            msg.data = std::stoi(input);
            test_pub.publish(msg);
        } catch (const std::invalid_argument& e) {
            std::cout << "Invalid input\n";
        }

        ros::spinOnce();
    }

    return 0;
}