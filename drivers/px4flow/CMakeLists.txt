cmake_minimum_required(VERSION 2.8.3)
project(px4flow)

find_package(catkin REQUIRED COMPONENTS roscpp std_msgs sensor_msgs image_transport px_comm)
find_package(Boost REQUIRED COMPONENTS thread system signals)

catkin_package(
  INCLUDE_DIRS include
  CATKIN_DEPENDS roscpp std_msgs sensor_msgs image_transport px_comm
  DEPENDS boost
)

###########
## Build ##
###########

include_directories(include
  ../../mavlink/include/mavlink/v1.0
  ${catkin_INCLUDE_DIRS}
)

add_executable(px4flow_node
  src/SerialComm.cc
  src/px4flow_node.cc
)

target_link_libraries(px4flow_node
  ${catkin_LIBRARIES}
)

add_dependencies(px4flow_node px_comm_gencpp)

#############
## Install ##
#############

install(TARGETS px4flow_node
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

install(DIRECTORY launch/
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}/launch
  PATTERN ".svn" EXCLUDE
)
