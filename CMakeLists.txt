cmake_minimum_required(VERSION 3.2)
project(hackerrank)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "-g -DDEBUG -std=c++0x -Werror -Wno-unused-function")

# include
#include_directories(include)

# source flies
add_library(Catch2 INTERFACE)
file(GLOB CPP_FILES cpp/*.cpp)
file(GLOB INTERVIEW_PREP_KIT_FILES interview_prep_kit/*.cpp)

# add precompiled headers
target_include_directories(Catch2 INTERFACE 3rdParty/Catch2/single_include)

# create test executable
add_executable(hackerrank ${CPP_FILES} ${INTERVIEW_PREP_KIT_FILES})
target_link_libraries(hackerrank Catch2)
