#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
 
typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;
 
int main(int argc, char** argv){
 int goal1 =0;
 ros::init(argc, argv, "simple_navigation_goals");
 
//tell the action client that we want to spin a thread by default
MoveBaseClient ac("move_base", true);
  
//wait for the action server to come up
    while(!ac.waitForServer(ros::Duration(5.0))){
       ROS_INFO("Waiting for the move_base action server to come up");
     }
   
     move_base_msgs::MoveBaseGoal goal;
   
     //we'll send a goal to the robot to move 1 meter forward
     goal.target_pose.header.frame_id = "map";
   goal.target_pose.header.stamp = ros::Time::now();
if(!goal1)
   {
     goal.target_pose.pose.position.x = 0.797854802116;
     goal.target_pose.pose.position.y = 0.879871426445;
     goal.target_pose.pose.orientation.w = 0.97229615157;
 goal.target_pose.pose.orientation.z = -0.233752419541;
}
else{
goal.target_pose.pose.position.x = -0.425269873409;
     goal.target_pose.pose.position.y = -1.97424206623;
     goal.target_pose.pose.orientation.w = 0.728064436849;
 goal.target_pose.pose.orientation.z = -0.685508698555;
}
    
   
     ROS_INFO("Sending goal");
     ac.sendGoal(goal);
   
     ac.waitForResult();
   
     if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
	{
       ROS_INFO("Hooray, the base moved 1 meter forward");	
	goal1=1;
	}
     else
       ROS_INFO("The base failed to move forward 1 meter for some reason");
   
     return 0;
  }
