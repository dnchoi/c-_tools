cmake_minimum_required(VERSION 3.0.0)

# 프로젝트 정보
project(
  Application
  VERSION 0.1
  DESCRIPTION "Golf cart Vision controller"
  LANGUAGES CXX
)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS -pthread)
message(STATUS CMAKE_BUILD_TYPE)                     # -- CMAKE_BUILD_TYPE
message(STATUS ${CMAKE_BUILD_TYPE})                  # -- Debug
message(STATUS "Configuration: ${CMAKE_BUILD_TYPE}") # -- Configuration: Debug
message(STATUS "Compiler")
message(STATUS " - ID       \t: ${CMAKE_CXX_COMPILER_ID}")
message(STATUS " - Version  \t: ${CMAKE_CXX_COMPILER_VERSION}")
message(STATUS " - Path     \t: ${CMAKE_CXX_COMPILER}\n\n")

set (obj_Header "${CMAKE_CURRENT_SOURCE_DIR}/lib/obj/include")
set (gst_capture_reader_Header "${CMAKE_CURRENT_SOURCE_DIR}/lib/gst_capture_reader/include")
set (Thread_Pool_Header "${CMAKE_CURRENT_SOURCE_DIR}/lib/ThreadPool/include")
set (Header "${CMAKE_CURRENT_SOURCE_DIR}/include")

# add_definitions(-DCMAKE_EXPORT_COMPILE_COMMANDS=ON)

message("${Header}")
message("${obj_Header}")
message("${gst_capture_reader_Header}")
message("${Thread_Pool_Header}")

# include_directories(
#     ${Header}
#     ${obj_Header}
#     ${gst_capture_reader_Header}
#     ${Thread_Pool_Header}
# )

#INIT
# Lib 등록을 위한 작업 -> 해당 Lib Cmake 동작 후 build
add_subdirectory(
    lib/obj
)
message("Object detector shared lib build done")
add_subdirectory(
    lib/gst_capture_reader
)
message("Gstreamer capture reader shared lib build done")
add_subdirectory(
    lib/ThreadPool
)
message("Thread pool shared lib build done")
#INIT

add_executable (${PROJECT_NAME} Application.cpp)

# include lib file in program
target_link_libraries(
    ${PROJECT_NAME}
    obj
    gst_capture_reader
    ThreadPool
    pthread
)
target_include_directories(
    ${PROJECT_NAME} 
    PUBLIC 
        ${Header} 
        ${obj_Header} 
        ${gst_capture_reader_Header}
        ${Thread_Pool_Header}
)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)
