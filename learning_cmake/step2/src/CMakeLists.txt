
# Basic settings
cmake_minimum_required(VERSION 2.8)
set(SOURCE_FILE_LIST main.cpp)
add_executable(step2 ${SOURCE_FILE_LIST})

# which is project binary directory (where to use cmake)
MESSAGE(STATUS "-------- This is Project Binary Path" ${PROJECT_BINARY_DIR})
# which is project source path (where to use main CMakeLists.txt file, and also the path after cmake command)
MESSAGE(STATUS "-------- This is Project Source Path" ${PROJECT_SOURCE_DIR})

# set executable file output path
set(EXECUTABLE_OUTPUT_PATH  ${PROJECT_BINARY_DIR}/bin)

# install runtime file to bin
INSTALL(TARGETS step2 RUNTIME DESTINATION bin)