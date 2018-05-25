# 编译动态库和静态库

## 1 添加目录和文件

```
mkdir src
touch CMakeLists.txt
touch COPYRIGHT
cd src
touch CMakeLists.txt
touch hello.h
touch hello.cpp
```

## 2 添加代码

hello.h
```
#ifndef STEP3_HELLO_H
#define STEP3_HELLO_H

#include <iostream>

void hello(void);
#endif //STEP3_HELLO_H

```

hello.cpp
```
#include "hello.h"

using std::cout;
using std::endl;

void hello(void)
{
    cout << "Hello Wolrd" << endl;
    return;
}
```

## 添加src目录中的CMakeLists.txt文件

```
# 基本设置
cmake_minimum_required(VERSION 2.8)

set(LIB_HELLO_SRC hello.cpp)

# 生成库文件
add_library(hello_dynamic SHARED ${LIB_HELLO_SRC})
add_library(hello_static SHARED ${LIB_HELLO_SRC})

# 设置库的基本属性（名称和版本）
set_target_properties(hello_dynamic PROPERTIES OUTPUT_NAME "hello")
set_target_properties(hello_dynamic PROPERTIES VERSION 1.2 SOVERSION 1)

set_target_properties(hello_static PROPERTIES OUTPUT_NAME "hello")

# 设置库输出目录
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

# 安装目录
INSTALL(TARGETS hello_dynamic hello_static
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib)

# 安装头文件
INSTALL(FILES hello.h DESTINATION inlcude/hello)
```

## 编译和安装
```
mkdir build
cd build
cmake ..
make
make install
```

进入安装目录看一下：

```
cd /tmp
tree step3
```
下面是结果：
```
tep3
                                                                                                        │├── inlcude
                                                                                                        ││   └── hello
                                                                                                        ││       └── hello.h
                                                                                                        │└── lib
                                                                                                        │    ├── libhello.so
                                                                                                        │    ├── libhello.so.1 -> libhello.so.1.2
                                                                                                        │    └── libhello.so.1.2
                                                                                                        │

```

## 关于INSTALL

命令格式：
```
INSTALL(TARGETS targets...
[[ARCHIVE|LIBRARY|RUNTIME]
[DESTINATION <dir>]
[PERMISSIONS permissions...]
[CONFIGURATIONS
[Debug|Release|...]]
[COMPONENT <component>]
[OPTIONAL]
] [...])
```

- TARGETS后面跟的就是我们通过ADD_EXECUTABLE或者ADD_LIBRARY定义的目标文件，可能是可执行二进制、动态库、静态库
- 目标类型也就相对应的有三种，ARCHIVE特指静态库，LIBRARY特指动态库，RUNTIME特指可执行目标二进制。
- DESTINATION定义了安装的路径

关于FILES、还有PRGRAMS、DOCS在Step2中有简单的使用。

## 参考
[https://blog.csdn.net/primeprime/article/details/53020147](https://blog.csdn.net/primeprime/article/details/53020147)