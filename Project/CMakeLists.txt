cmake_minimum_required(VERSION 3.26)
project(Project)

set(CMAKE_CXX_STANDARD 17)

add_executable(Project main.cpp
        List.cpp
        List.h
        Node.h
        Queue.cpp
        Queue.h
        Stack.cpp
        Stack.h)
