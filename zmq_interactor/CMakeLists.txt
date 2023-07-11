cmake_minimum_required(VERSION 3.10)

project(Zmq_Pub_Sub)

include_directories(${CMAKE_SOURCE_DIR}/include)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/output/bin)

add_subdirectory(${PROJECT_SOURCE_DIR}/src)