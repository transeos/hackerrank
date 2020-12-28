cmake_minimum_required(VERSION 3.2)
project(hackerrank)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "-g -DDEBUG -Werror -Wno-unused-function")

# include
include_directories(include)

# source flies
add_library(Catch2 INTERFACE)
file(GLOB UTILS_FILES utils/*.cpp)
file(GLOB CPP_FILES cpp/*.cpp)

#interview prep kit
file(GLOB INTERVIEW_PREP_KIT_ARRAY_FILES interview_prep_kit/array/*.cpp)
file(GLOB INTERVIEW_PREP_KIT_HASHMAP_FILES interview_prep_kit/hashmaps/*.cpp)
file(GLOB INTERVIEW_PREP_KIT_RECURSION_FILES interview_prep_kit/recursion/*.cpp)
file(GLOB INTERVIEW_PREP_KIT_SEARCH_FILES interview_prep_kit/search/*.cpp)
file(GLOB INTERVIEW_PREP_KIT_SORTING_FILES interview_prep_kit/sorting/*.cpp)
file(GLOB INTERVIEW_PREP_KIT_WARMUP_FILES interview_prep_kit/warm-up/*.cpp)
file(GLOB INTERVIEW_PREP_KIT_LINKED_LIST_FILES interview_prep_kit/linked_list/*.cpp)
file(GLOB INTERVIEW_PREP_KIT_TREE_FILES interview_prep_kit/tree/*.cpp)
file(GLOB INTERVIEW_PREP_KIT_STACKS_QUEUES_FILES interview_prep_kit/stacks_queues/*.cpp)
file(GLOB INTERVIEW_PREP_KIT_GRAPH_FILES interview_prep_kit/graph/*.cpp)

# add precompiled headers
target_include_directories(Catch2 INTERFACE 3rdParty/Catch2/single_include)

# create test executable
add_executable(hackerrank ${UTILS_FILES} ${CPP_FILES}
                          ${INTERVIEW_PREP_KIT_ARRAY_FILES}
                          ${INTERVIEW_PREP_KIT_HASHMAP_FILES}
                          ${INTERVIEW_PREP_KIT_RECURSION_FILES}
                          ${INTERVIEW_PREP_KIT_SEARCH_FILES}
                          ${INTERVIEW_PREP_KIT_SORTING_FILES}
                          ${INTERVIEW_PREP_KIT_WARMUP_FILES}
                          ${INTERVIEW_PREP_KIT_LINKED_LIST_FILES}
                          ${INTERVIEW_PREP_KIT_TREE_FILES}
                          ${INTERVIEW_PREP_KIT_STACKS_QUEUES_FILES}
                          ${INTERVIEW_PREP_KIT_GRAPH_FILES})
target_link_libraries(hackerrank Catch2)
