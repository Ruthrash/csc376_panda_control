
#include <cmath>//for M_PI_
#include <csc376_panda_control/Client.hpp>

int main(int argc, char **argv){
    
    Client client_object(argc, argv);

    std::array<double, 7> q_goal =  {{M_PI_4, -M_PI_4, 0, -3 * M_PI_4, 0, M_PI_2, M_PI_4}};
    client_object.goToJointConfiguration(q_goal);

    /* print current joint and EE configurations*/
    std::array<double,7> q_current = client_object.getCurrentJointConfiguration();
    std::cout<<"Current Joint configuration: ";
    for (size_t i = 0; i < 7; i++) {
        std::cout<<q_current[i]<<", ";
    }
    std::cout<<"\n";

    std::array<double,7> ee_current = client_object.getCurrentJointConfiguration();
    std::cout<<"Current End-effector configuration: ";
    for (size_t i = 0; i < 7; i++) {
        std::cout<<ee_current[i]<<", ";
    }
    std::cout<<"\n";

    return 0; 
}
