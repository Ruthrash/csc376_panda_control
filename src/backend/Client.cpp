#include "csc376_panda_control/Client.hpp"

Client::~Client(){}

Client::Client(int argc, char **argv){
    ros::init(argc, argv, "panda_joint_control_client");
    ros::ServiceClient service_client = node_.serviceClient<csc376_panda_control::JointAngleCommand>("joint_angles_controller");
}

bool Client::goToJointConfiguration(const std::array<double, 7> &q_goal){
    csc376_panda_control::JointAngleCommand srv;

    for (size_t i = 0; i < 7; i++) {
        srv.request.joint_angles[i] = q_goal[i];
    }
    if (service_client.call(srv))
    {
        ROS_INFO("Success");
        return true; 
    }
    else
    {
        ROS_ERROR("Failed to call service to go to joint configuration");
    	return false;
    }  

}


/*
todo: get true joint angle and EE configuration and return it 
*/
std::array<double,7> Client::getCurrentJointConfiguration(){
    return {{M_PI_4, -M_PI_4, 0, -3 * M_PI_4, 0, M_PI_2, M_PI_4}};

}
std::array<double,7> Client::getCurrentEEFrame(){
    return {{M_PI_4, -M_PI_4, 0, -3 * M_PI_4, 0, M_PI_2, M_PI_4}};
}
