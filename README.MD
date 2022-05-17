## Dependencies 
- libfranka 
- Eigen

## usage 

```
mkdir -p ~/catkin_ws/src && cd ~/catkin_ws/src 
catkin_init_workspace
git clone 

cd ~/catkin_ws
catkin_make_isolated 
source ../devel_isolated/setup.bash 
```

run the controller server 

```
rosrun csc376_panda_control panda_ros_server 
```

In a new terminal run the controller client 

```
rosrun csc376_panda_control main 
```