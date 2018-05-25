# 使用其他的库文件

在step3中生成了动态库和静态库，这里我们使用一下它们。

## 1 创建目录和文件

```
mkdir src
mkdir lib
mkdir -p include/hello

touch CMakeLists.txt
touch COPYRIGHT
touch README.md

cd src
touch main.cpp
touch CMakeLists.txt

cd ..
cp PATH_step3/build/lib/* ./lib/
cp PATH_step3/src/hello.h ./include/hello/
```

> 因为在Step3中，将lib文件和头文件都安装在了tmp目录中，重启或者重新登录都会把它们清除，所以我们把头文件和库文件都拷贝出来放在根目录中的lib目录好include文件中，如果有多个第三方库，可以创建一个ThirdParity目录用来管理它们。

## 2 在main函数中使用共享库

```
#include <iostream>

#include "hello.h"

int main()
{
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
```

## 3 更新CMakeLists.txt文件

src目录中
```
cmake_minimum_required(VERSION 2.8)

add_executable(main main.cpp)

include_directories(../include/hello)

find_library(HELLO_LIB NAMES hello PATHS "../lib")

MESSAGE(STATUS "Library path HELLO_LIB is " ${HELLO_LIB})

target_link_libraries(main ${HELLO_LIB})

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
```

主工程目录中
```
cmake_minimum_required(VERSION 2.8)

project(step4)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(src)
```

## 编译运行

```
mkdir build
cd build
cmake ..
make
./bin/main
```