cmake_minimum_required(VERSION 3.0.0)
project(ThreadPool VERSION 0.1.0)
message("@@ Thread Pool CMake Start @@")

message("This lib name : ${PROJECT_NAME}")

include_directories(include)

add_library(${PROJECT_NAME} SHARED ThreadPool.cpp)

target_link_libraries(
    ${PROJECT_NAME}
)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

message("@@ Thread Pool CMake Finish @@\n\n")

