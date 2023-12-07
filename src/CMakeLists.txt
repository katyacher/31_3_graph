cmake_minimum_required(VERSION 3.8.0)
add_executable(31_1_graph main.cpp ${MY_INCLUDE_DIR}/IGraph.h IGraph.cpp ListGraph.cpp MatrixGraph.cpp)

target_include_directories(31_1_graph PUBLIC ${MY_INCLUDE_DIR})