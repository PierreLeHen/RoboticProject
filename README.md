# RoboticProject


# On the Turtlebot laptop #

##### Initialisation with the Turtlebot #####

roscore

roslaunch turtlebot_bringup minimal_with_hokuyo.launch

rosrun hokuyo_node hokuyo_node

roslaunch turtlebot_brinup 3dsensor.launch

# On the teleoperating laptop #

##### For simulation only #####

roslaunch turtlebot_gazebo turtlebot_world.launch world_file:=path/to/file.world

#### For real world ####

# To create the map
rosrun gmapping slam_gmapping scan:/scan

# To save the map
rosrun map_server map_saver -f 'name of the file'

# To launch AMCL + move base
roslaunch turtlebot_navigation amcl_launch.demo map_file:='path of the file'

# To reach a goal saved in the file simple_navigation_goals.cpp
rosrun simple_navigation_goals simple_navigation_goals

# Find_object_2d pkg #

In find_object_2d package place the find_object_3d.launch file in the launch directory and then run the command line in the terminal

# For 2d identification:
rosrun find_object_2d find_object_2d image:=/camera/rgb/image_raw _image_transport:=compressed _objects_path:=:=~/path/to/samples

# For 3d identification
roslaunch find_object_2d find_object_3d.launch subscribe_depth:=true _image_transport:=compressed _objects_path:=~/path/to/samples

#  Color detection #

In opencv_apps package, place the red_hsv_color_filter.launch file in the launch directory and then run the commad line in the terminal

# In HSV #
roslaunch opencv_apps red_hsv_color_filter.launch

# Links GitHub #

##### Find Object 2D #####

https://github.com/introlab/find-object/tree/master#find_object_2d-ros-package

##### Open CV #####

https://github.com/ros-perception/opencv_apps

# Additional command lines  

catkin_make													# Build the workspace

source devel/setup.bash										# Source the workspace after catkin_make

rosrun uvc_camera uvc_camera_node							# Use find_object_2d package with the webcam

sudo chmod a+rw dev/port number								# if the access to the port of hokuyo_node is denied

roslaunch turtlebot_teleop keyboard_teleop.launch			# teleoperates the Turtlebot with the keyboard

rostopic echo /amcl_pose                      #get the pose and the orientation of the robot from AMCL
