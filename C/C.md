# 一、基础环境

## 1、vscode

官网：https://code.visualstudio.com/docs/?dv=win

汉化：chinese

c/c++插件：c/c++

c/c++运行环境：c/c++ Compile Run extension

其他插件：C/C++ Snippets; EPITECH C/C++ Headers; File Templates ; GBKtoUTF8; Include Autocomplete; 

windows: 下载安装编译器, 

https://code.visualstudio.com/docs/cpp/config-mingw

通过msys2, https://www.msys2.org/

（linux 下直接根据提示apt install gcc/ g++）



## 2、vs

官网：https://visualstudio.microsoft.com/zh-hans/downloads

下载最新：vs2022

安装，根据需要选择一些安装， 通过 [仅选择所需的组件](https://docs.microsoft.com/visualstudio/install/install-visual-studio) 来节省安装时间和磁盘空间。 你始终可以根据需要随时以增量方式添加更多组件。（工具/获取工具和功能；文件/项目/找到打开visual studio安装程序/）

安装位置：（为了不卡，放在了SSD）

![image-20220610000425218](C:\Users\19478\AppData\Roaming\Typora\typora-user-images\image-20220610000425218.png)



# 二、编译

参考： g++ 编译&库链接相关知识： https://zhuanlan.zhihu.com/p/372722440

### 1、gcc: GCC中的GUN C Compiler（C 编译器 ）

```
gcc test.c -o test
./test
```

### 2、C生成动态链接库（so）并调用：

参考：C动态链接库的编译： https://blog.csdn.net/weixin_40437821/article/details/110671132

```
$ gcc test_a.c test_b.c test_c.c -fPIC -shared -o libtest.so   // 编译成一个动态库：libtest.so
$ gcc test_main.c -L. -ltest -o test_main  // 测试调用 动态库的链接
$ ldd test   // 测试是否动态连接，ibtest.so => not found, bashrc添加.so的环境;  export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/home/***/HDD/wood/work/Research/CPP/c_so/src/libtest.so
$ ./test      // 查看如何调用动态库函数
```



### 3、g++: GCC中的GUN C++ Compiler（C++编译器）

```
g++ testcpp.cpp -o testcpp
./testcpp
# 多个cpp
g++ cpp文件名称 cpp文件名称 -o 可执行文件名称
```

### 4、C++动态连接库的编译：

```
g++ testcpp_a.cpp testcpp_b.cpp -fPIC -shared -o libtestcpp.so
g++ testcpp_main.cpp -L. -ltestcpp -o testcpp_main
./testcpp_main
```

### 5、cmake编译：

#### 5-1、windows:

```
windows 安装cmake:
下载msi, 安装。
cd build; 
cmake ..; 
再vs打开sln文件
```

#### 5-2、linux:

参考：cmake编译c++:  https://cmake.org/documentation/    ;    https://zhuanlan.zhihu.com/p/373256365

CMake编译生成CPP动态库与静态库：

https://blog.csdn.net/CSDN__Kaker/article/details/122048776

https://blog.csdn.net/cindywry/article/details/86063930

ubuntu 源码安装cmake-3.23.2:

```
https://blog.csdn.net/jingtaoaijinping/article/details/109111957
# 环境配置：
wget https://github.com/Kitware/CMake/releases/download/v3.23.2/cmake-3.23.2.tar.gz
tar -zxvf cmake-3.23.2.tar.gz
cd cmake-3.23.2
./bootstrap
make -j4     // 4线程
make install

# 编译：
cd build; 
cmake .. ; 
make ; 
cd ../bin ; 
./*** 
```

cmake 编译生成可执行文件： example: TestDemo

```
-TestDemo
-- bin   // 可执行文件
-- build  // 编译生成文件
-- include // 头文件：.h
-- lib   // 库文件：.so .a
-- src  // 源文件 .c .cpp
-- CMakeLists.txt
```

CMakeLists.txt: 

```
cmake_minimum_required(VERSION 3.10)
# set the project name 工程名
project(TestDemo)
# 设置编译模式
set(CMAKE_BUILD_TYPE Release)
# 设置可执行文件与链接库保存的路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
# 设置头文件目录
include_directories(
${PROJECT_SOURCE_DIR}/include
)
# add the executable 添加编译文件
add_executable(TestDemo src/00_class.cpp)

```

cmake 编译生成动态库：example : cmakedemo

CMakeLists: 

```
cmake_minimum_required(VERSION 3.10)

# set the project name 工程名
project(TestDemo)

# 设置编译模式
set(CMAKE_BUILD_TYPE Release)

# 设置可执行文件与链接库保存的路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

# 设置头文件目录
include_directories(
${PROJECT_SOURCE_DIR}/include
)

# 生成动态链接库 SHARED
add_library(dymc_lib SHARED ${PROJECT_SOURCE_DIR}/include/so_test.h
                            ${PROJECT_SOURCE_DIR}/src/test_a.c 
                            ${PROJECT_SOURCE_DIR}/src/test_b.c 
                            ${PROJECT_SOURCE_DIR}/src/test_c.c)
    
# 添加下面两行调用 链接库生成可执行文件
# ADD_EXECUTABLE(hello_dymc src/test_main.c)
# TARGET_LINK_LIBRARIES(hello_dymc dymc_lib)

```

cmake 调用动态链接库：example : cmakedemo_test

CMakeLists:

```
cmake_minimum_required(VERSION 3.10)

# set the project name 工程名
project(TestDemo)

# 设置编译模式
set(CMAKE_BUILD_TYPE Release)

# 设置可执行文件与链接库保存的路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

# 设置头文件目录
include_directories(
${PROJECT_SOURCE_DIR}/inc
)

# 链接库路径
link_directories(${LIBRARY_OUTPUT_PATH})
# 链接库，dymc_lib 为库名
link_libraries(dymc_lib)

# 生成目标文件
add_executable(TestDemo src/test_main.c)

# 链接库文件
TARGET_LINK_LIBRARIES(TestDemo dymc_lib)

```



# 三、基础知识

## 1、API:

1、简单入门： [ https://www.runoob.com/cplusplus/cpp-exceptions-handling.html](https://www.runoob.com/cplusplus/cpp-exceptions-handling.html)

​		中文网： http://c.biancheng.net/cplus/  （部分内容收费）

2、API：https://cplusplus.com/doc/  

3、进阶： https://github.com/CnTransGroup/EffectiveModernCppChinese





# 四、W

## 1、Effective Modern C++

### Effective Modern C++ （一）:

#### 1、类型推导

##### （1）模板类型推导；

##### （2）auto类型推导；

##### （3）decltype;

#####   (4) 查看类型推导结果：

IDE编辑器；编译器诊断；运行时输出（typeid(x).name()）

#### 2、auto

  作用：让编译器分析表达式所属的类型。必须初始化。

#####   （5) 优先考虑auto而非显式类型声明；

 顶层const: int* const p1 = &a; 修饰p1, 即指针本身，赋值规则：https://blog.csdn.net/weixin_43744293/article/details/117955427

 底层const: const int* p2 = &a; 修饰*p2, 即指针的指向地址的值，https://blog.csdn.net/weixin_43744293/article/details/117440727

#####   （6）auto推导若非己愿，使用显式类型初始化惯用法

不可见的代理类可能会使auto从表达式中推导出“错误的”类型;

解决办法：显式类型初始器惯用法强制auto推导出你想要的结果; 如 auto sum = static_cast<Matrix>(m1 + m2 + m3 + m4);

### Effective Modern C++ （二）:

#### 3、现代C++

  (7) 



# Code source:

