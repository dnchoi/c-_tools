cmake_minimum_required(VERSION 3.0.0)
project(obj VERSION 0.1.0)
message("@@ Object detection CMake Start @@")

message("This lib name : ${PROJECT_NAME}")
include_directories(include)
add_library(${PROJECT_NAME} SHARED obj.cpp)
add_library(wrapper::system ALIAS ${PROJECT_NAME})

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

message("@@ Object detection CMake Finish @@\n\n")

