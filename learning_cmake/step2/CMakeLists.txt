# Basic Settings
cmake_minimum_required(VERSION 2.8)
project(step2)
set(CMAKE_CXX_STANDARD 11)

# set install prefix
set(CMAKE_INSTALL_PREFIX /tmp/step2)

# add source file folder
add_subdirectory(src)

# set file install path
INSTALL(FILES COPYRIGHT README.md DESTINATION share/doc/cmake/step2)
# set programs installl path
INSTALL(PROGRAMS runstep2.sh DESTINATION bin)
# set doc directory install path
INSTALL(DIRECTORY doc DESTINATION doc/cmake/step2)
