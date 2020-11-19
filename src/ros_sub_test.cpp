#include "ros/ros.h"
#include "ros_topic_test/MsgTest.h"


void msgCallbackFn(const ros_topic_test::MsgTest::ConstPtr& msg)
{
  ROS_INFO("receive msg = %s", msg->strdata.c_str());
  ROS_INFO("receive msg = %d", msg->ndata);
}


int main(int argc, char **argv)
{
  ros::init(argc, argv, "ros_sub_test");	
  ros::NodeHandle nh;

  ros::Subscriber ros_test_sub = nh.subscribe("ros_test_msg", 1000, msgCallbackFn);

  ros::spin();

  return 0;
}	
