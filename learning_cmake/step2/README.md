# cmake 外部构建

这个工程主要是模拟清洁的使用cmake创建工程，并且支持编译和安装。主要有以下特点：

- 主目录中有src子目录，doc子目录，还有COPYRIGHT，README.md等文件
- 安装COPYRIGHT和README.md文件
- 安装脚本
- 安装doc目录
- 安装可执行文件

## 1 创建目录和文件

```
mkdir src
mkdir doc
touch COPYRIGHT
touch README.md
touch CMakeLists.txt
touch runstep2.sh
cd src
touch main.cpp
touch CMakeLists.txt
cd ../doc
touch step2.txt
```

## 2 添加文件内容
在main文件中添加一个hello world就行：
```
#include <iostream>

using namespaace std;

int main()
{
    cout << "Hello World" << endl;
}
```
其他文件可以不用添加，要想添加也没啥。

## 3 修改CMakeLists.txt文件

在src目录中的CMakeLists.txt文件中内容
```

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
```

在主目录中添加内容

```
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

```

## 编译安装
```
mkdir build
cd build
cmake ..
make
make install
```