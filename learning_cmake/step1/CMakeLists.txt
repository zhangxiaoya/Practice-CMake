cmake_minimum_required(VERSION 2.8)

# these are basic settings
project(step1)
set(CMAKE_CXX_STANDARD 11)

# these are new settings
set(SOURCE_FILE_LIST main.cpp)

MESSAGE(STATUS "This is BINARY dir " ${PROJECT_BINARY_DIR})
MESSAGE(STATUS "This is SOURCE dir " ${PROJECT_SOURCE_DIR})

#add_executable(step1 main.cpp)
add_executable(step1 ${SOURCE_FILE_LIST})