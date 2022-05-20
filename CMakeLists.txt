cmake_minimum_required(VERSION 3.2)
project(hackerrank)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-ggdb3 -DDEBUG -Werror -Wno-unused-function -fno-inline -fconcepts")

find_package(TBB REQUIRED)

# include
include_directories(include)

# source flies
add_library(Catch2 INTERFACE)

# utils/common functions
file(GLOB UTILS_FILES utils/*.cpp)

# C++
file(GLOB CPP_FILES cpp/*.cpp)

# interview prep kit
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
file(GLOB INTERVIEW_PREP_KIT_MISCELLANEOUS_FILES interview_prep_kit/miscellaneous/*.cpp)
file(GLOB INTERVIEW_PREP_KIT_STRING_FILES interview_prep_kit/string/*.cpp)
file(GLOB INTERVIEW_PREP_KIT_GREEDY_FILES interview_prep_kit/greedy/*.cpp)
file(GLOB INTERVIEW_PREP_KIT_DP_FILES interview_prep_kit/DP/*.cpp)

#problem solving
file(GLOB PROBLEM_SOLVING problem_solving/*.cpp)

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
                          ${INTERVIEW_PREP_KIT_GRAPH_FILES}
                          ${INTERVIEW_PREP_KIT_MISCELLANEOUS_FILES}
                          ${INTERVIEW_PREP_KIT_STRING_FILES}
                          ${INTERVIEW_PREP_KIT_GREEDY_FILES}
                          ${INTERVIEW_PREP_KIT_DP_FILES}
                          ${PROBLEM_SOLVING})
target_link_libraries(hackerrank Catch2 ${TBB_IMPORTED_TARGETS})
