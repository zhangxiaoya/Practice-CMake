cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_STANDARD 11)

project(Tutorial)

# should we use our own math functions
option(USE_MYMATH "Use tutorial provided math implementation" ON)

# 添加变量，分别表示主版本号和副版本号
# set project version
set(Tutorial_VERSION_MAJOR 1)
set(Tutorial_VERSION_MINOR 0)

# 下面是添加配置文件，在项目的源代码目录中添加TutorialConfig.h.in文件，
# 这里面填写我们的配置，在项目的可执行目录生成一个对应的头文件，实际上把
# 配置文件中的配置变量生成到这个头文件中，然后项目的源代码可以包含这个头
# 文件，这样就能使用在CMakeLists文件的配置了。
# configure a header file to pass some of the CMake settings
# to the source code
configure_file(
        "${PROJECT_SOURCE_DIR}/TutorialConfig.h.in"
        "${PROJECT_BINARY_DIR}/TutorialConfig.h"
)

# 把二进制目标也加到include目录中，因为生成的TutorialConfig.h文件是在那个目录中
# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
include_directories("${PROJECT_BINARY_DIR}")

# add the MathFunctions library?
#
if (USE_MYMATH)
    include_directories ("${PROJECT_SOURCE_DIR}/MathFunctions")
    add_subdirectory (MathFunctions)
    set (EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)
endif (USE_MYMATH)


add_executable(Tutorial main.cpp)
target_link_libraries (Tutorial  ${EXTRA_LIBS})

# add the install targets
install (TARGETS Tutorial DESTINATION bin)
install (FILES "${PROJECT_BINARY_DIR}/TutorialConfig.h"
        DESTINATION include)

include(CTest)

# does the application run
add_test (TutorialRuns Tutorial 25)
# does it sqrt of 25
add_test (TutorialComp25 Tutorial 25)
set_tests_properties (TutorialComp25 PROPERTIES PASS_REGULAR_EXPRESSION "25 is 5")
# does it handle negative numbers
add_test (TutorialNegative Tutorial -25)
set_tests_properties (TutorialNegative PROPERTIES PASS_REGULAR_EXPRESSION "-25 is 0")
# does it handle small numbers
add_test (TutorialSmall Tutorial 0.0001)
set_tests_properties (TutorialSmall PROPERTIES PASS_REGULAR_EXPRESSION "0.0001 is 0.01")
# does the usage message work?
add_test (TutorialUsage Tutorial)
set_tests_properties (TutorialUsage PROPERTIES PASS_REGULAR_EXPRESSION "Usage:.*number")