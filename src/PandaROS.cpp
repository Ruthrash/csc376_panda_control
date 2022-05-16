#include "csc376_panda_control/PandaROS.hpp"
#include "csc376_panda_control/MotionGenerator.hpp"

#include <iostream>
#include <franka/control_types.h>



// PandaROS::PandaROS(){}
PandaROS::~PandaROS(){}
//, model_(robot_.loadModel())
PandaROS::PandaROS(ros::NodeHandle &node, const std::string &robot_ip): robot_(robot_ip){
    service_server = node.advertiseService("joint_angles_controller", &PandaROS::ServiceServerCB, this);


}

bool PandaROS::ServiceServerCB(csc376_panda_control::JointAngleCommand::Request  &req,
                        csc376_panda_control::JointAngleCommand::Response &res){

    try{                    
        std::array<double, 7> q_goal ;
        for (size_t i = 0; i < 7; i++) {
            q_goal[i] = req.joint_angles[i];
        }

        MotionGenerator motion_generator(0.5, q_goal);
        robot_.control(motion_generator);

    }
    catch (const franka::Exception& ex) {
        std::cerr << ex.what() << std::endl;
    } 
 
    return 1; 


}