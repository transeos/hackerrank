cmake_minimum_required(VERSION 3.2)
project(hackerrank)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "-g -DDEBUG -std=c++11")

# include
#include_directories(include)

# source flies
file(GLOB HACKERRANK_CPP_CLASS_TEMPLATES src/hackerrank_cpp_class_templates.cpp)

add_library(Catch2 INTERFACE)
file(GLOB HACKERRANK_FILES src/abstract_class.cpp)

# add precompiled headers
target_include_directories(Catch2 INTERFACE 3rdParty/Catch2/single_include)

# create test executable
add_executable(hackerrank ${HACKERRANK_FILES})
target_link_libraries(hackerrank Catch2)
