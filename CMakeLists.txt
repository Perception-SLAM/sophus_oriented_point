cmake_minimum_required (VERSION 2.6)
set( CMAKE_EXPORT_COMPILE_COMMANDS ON )
project (Pose)
include_directories (
  /usr/include/eigen3
  /usr/local/include/sophus
)
add_executable(Pose pose_from_point_and_direction_vector.cpp)
