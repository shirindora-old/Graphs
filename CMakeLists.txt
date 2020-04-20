cmake_minimum_required(VERSION 3.15)
project(Graphs)

set(CMAKE_CXX_STANDARD 14)

add_executable(Graphs main.cpp Vertex.h Graph.cpp Graph.h Queue.cpp Queue.h Stack.cpp Stack.h)