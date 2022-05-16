#include "csc376_panda_control/JointAngleCommand.h"
#include <cmath>
#include <ros/ros.h>
int main(int argc, char **argv)
{
    ros::init(argc, argv, "add_two_ints_client");
    ros::NodeHandle n;
    ros::ServiceClient client = n.serviceClient<csc376_panda_control::JointAngleCommand>("joint_angles_controller");
    csc376_panda_control::JointAngleCommand srv;
    srv.request.joint_angles = {{M_PI_4, -M_PI_4, 0, -3 * M_PI_4, 0, M_PI_2, M_PI_4}};

    if (client.call(srv))
    {
        ROS_INFO("Success");
    }
    else
    {
        ROS_ERROR("Failed to call service add_two_ints");
    return 1;
    }    
    return 0; 
}