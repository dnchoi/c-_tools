cmake_minimum_required(VERSION 3.0.0)
project(gst_capture_reader VERSION 0.1.0)
message("@@ Gstreamer capture reader CMake Start @@")

message("This lib name : ${PROJECT_NAME}")
message("OpenCV libraries add")

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIR})
message("${OpenCV_INCLUDE_DIR}")
include_directories(include)

add_library(${PROJECT_NAME} SHARED gst_capture_reader.cpp)
add_library(wrapper::system ALIAS ${PROJECT_NAME})

target_link_libraries(
    ${PROJECT_NAME}
    ${OpenCV_LIBRARIES}
)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

message("@@ Gstreamer capture reader CMake Finish @@\n\n")

