# 基本设置
cmake_minimum_required(VERSION 2.8)

# 设置LIB库的源代码文件
set(LIB_HELLO_SRC hello.cpp)

# 设置生成静态库和动态库
add_library(hello_dynamic SHARED ${LIB_HELLO_SRC})
add_library(hello_static SHARED ${LIB_HELLO_SRC})

# 设置静态库和静态库的属性
set_target_properties(hello_dynamic PROPERTIES OUTPUT_NAME "hello")
set_target_properties(hello_dynamic PROPERTIES VERSION 1.2 SOVERSION 1)
set_target_properties(hello_static PROPERTIES OUTPUT_NAME "hello")

# 设置 库文件的输出路径
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

# 安装路径
INSTALL(TARGETS hello_dynamic hello_static
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib)

# 安装头文件
INSTALL(FILES hello.h DESTINATION inlcude/hello)