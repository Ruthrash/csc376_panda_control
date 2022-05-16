#ifndef PANDA_ROS_H
#define PANDA_ROS_H

#include <ros/ros.h>
#include "csc376_panda_control/JointAngleCommand.h"

#include <eigen3/Eigen/Core>

//franka panda related .h files
#include <franka/control_types.h>
#include <franka/duration.h>
#include <franka/robot.h>
#include <franka/model.h>
#include <franka/robot_state.h>
#include <franka/rate_limiting.h>
#include <franka/exception.h>

class PandaROS
{
public:
    // PandaROS();
    // franka::Model model_;
    ~PandaROS();
    PandaROS(ros::NodeHandle &node, const std::string &robot_ip);

protected:

private:
    franka::Robot robot_;

    ros::ServiceServer service_server;
    bool ServiceServerCB(csc376_panda_control::JointAngleCommand::Request  &req,
                         csc376_panda_control::JointAngleCommand::Response &res);

};

#endif