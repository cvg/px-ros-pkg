cmake_minimum_required(VERSION 2.8.3)
project(px_comm)

find_package(catkin REQUIRED COMPONENTS std_msgs message_generation)

add_message_files(
  DIRECTORY msg
  FILES Mavlink.msg OpticalFlow.msg
)

generate_messages(
  DEPENDENCIES
  std_msgs
)

catkin_package(
   CATKIN_DEPENDS message_runtime
)
