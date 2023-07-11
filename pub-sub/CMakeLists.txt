cmake_minimum_required(VERSION 3.10)

project(Zmq_Pub_Sub)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/output/bin)

find_package(Protobuf REQUIRED)
include_directories(include ${PROTOBUF_INCLUDE_DIR})
link_directories(${PROTOBUF_LIBRARY})

include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/proto)

aux_source_directory(${CMAKE_SOURCE_DIR}/src SRCS)
aux_source_directory(${CMAKE_SOURCE_DIR}/proto PROTOS)



add_executable(zmq_comm ${SRCS} ${PROTOS})

target_link_libraries(zmq_comm zmq pthread ${PROTOBUF_LIBRARY})