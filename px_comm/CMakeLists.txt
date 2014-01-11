cmake_minimum_required(VERSION 2.8.3)
project(px_comm)

find_package(catkin REQUIRED COMPONENTS geometry_msgs std_msgs message_generation)

add_message_files(
  DIRECTORY msg
  FILES CameraInfo.msg Mavlink.msg OpticalFlow.msg
)

add_service_files(
  DIRECTORY srv
  FILES SetCameraInfo.srv
)

generate_messages(
  DEPENDENCIES
  geometry_msgs
  std_msgs
)

# if RTI DDS is found
if(DEFINED ENV{NDDSHOME})
  catkin_package(
    INCLUDE_DIRS include
    LIBRARIES px_comm_dds
    CATKIN_DEPENDS message_runtime
  )

  set(NDDSHOME $ENV{NDDSHOME})

  include_directories(
    include
    include/px_comm
    ${NDDSHOME}/include
    ${NDDSHOME}/include/ndds
  )

  add_definitions(-DRTI_UNIX)

  add_library(px_comm_dds
    dds_msg/DDSImage.cxx
    dds_msg/DDSImagePlugin.cxx
    dds_msg/DDSImageSupport.cxx
  )
else()
  catkin_package(
    INCLUDE_DIRS include
    CATKIN_DEPENDS message_runtime
  )
endif()
