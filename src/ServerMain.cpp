#include "csc376_panda_control/PandaROS.hpp"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "talker");
    ros::NodeHandle n;
    PandaROS control_object(n, "192.168.1.107");
    ros::Rate loop_rate(30);
    while(ros::ok())
    {
        ros::spinOnce();
        loop_rate.sleep();
    }
    return 0;
}