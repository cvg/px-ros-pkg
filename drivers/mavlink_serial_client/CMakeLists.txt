cmake_minimum_required(VERSION 2.8.3)
project(mavlink_serial_client)

find_package(catkin REQUIRED COMPONENTS cmake_modules roscpp std_msgs sensor_msgs image_transport px_comm)
find_package(Boost REQUIRED COMPONENTS thread system signals)
find_package(Eigen REQUIRED)

catkin_package(
  INCLUDE_DIRS include
  CATKIN_DEPENDS roscpp std_msgs sensor_msgs image_transport px_comm
  DEPENDS boost eigen
)

###########
## Build ##
###########

include_directories(include
  ../../mavlink/include/mavlink/v1.0
  ${catkin_INCLUDE_DIRS}
  ${Eigen_INCLUDE_DIRS}
)

add_executable(mavlink_serial_client
  src/SerialComm.cc
  src/mavlink_serial_client.cc
)

target_link_libraries(mavlink_serial_client
  ${catkin_LIBRARIES}
)

add_dependencies(mavlink_serial_client px_comm_gencpp)
