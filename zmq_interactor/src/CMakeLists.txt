aux_source_directory(. DIR_SRCS)

add_executable(zmq_interactor ${DIR_SRCS})

target_link_libraries(zmq_interactor zmq pthread)
