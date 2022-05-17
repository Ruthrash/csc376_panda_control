#ifndef CLIENT_H
#define CLIENT_H

#include <ros/ros.h>
#include "csc376_panda_control/JointAngleCommand.h"
#include <array>

class Client{

public:
    Client(int argc, char **argv);
    ~Client();
    bool goToJointConfiguration(const std::array<double, 7> &q_goal); 
    std::array<double,7> getCurrentJointConfiguration(); 
    std::array<double,7> getCurrentEEFrame(); 

private: 
    ros::NodeHandle node_; 
    ros::ServiceClient service_client;
};

#endif