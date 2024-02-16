cmake_minimum_required(VERSION 3.8.0)
add_executable(31_1_graph main.cpp ${MY_INCLUDE_DIR}/IGraph.h  ${MY_INCLUDE_DIR}/ListGraph.h  ListGraph.cpp  ${MY_INCLUDE_DIR}/MatrixGraph.h MatrixGraph.cpp)

target_include_directories(31_1_graph PUBLIC ${MY_INCLUDE_DIR})