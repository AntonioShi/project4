cmake_minimum_required(VERSION 3.8)
project(project4)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp text01.cpp text02.cpp text03.cpp text02_1.cpp text02_2.cpp)
add_executable(project4 ${SOURCE_FILES} text01.cpp text02.cpp text03.cpp text02_1.cpp)