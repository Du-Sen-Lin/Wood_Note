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







## 2、C基础

 1、extern ex: 声明变量名而不定义, 不需要建立存储空间。需要在一个源文件中引用另外一个源文件中定义的变量，我们只需在引用的文件中将变量加上 extern 关键字的声明即可。

```c
extern int i; //声明，不是定义
```

2、常量定义：#define 预处理器；const 关键字

前缀：0x 十六进制 0 八进制 后缀：后缀是 U 和 L 的组合，U 表示无符号整数（unsigned），L 表示长整数（long）

```c
#define WINDTH 5
const int HEIGHT = 10;
```

3、存储类: auto register static extern 定义C程序中变量/函数的范围（可见性）和生命周期。

```c
// auto: auto 存储类是所有局部变量默认的存储类。{auto int month} auto 只能用在函数内，即 auto 只能修饰局部变量。
// register: 用于定义存储在寄存器中而不是 RAM 中的局部变量。
// static: 指示编译器在程序的生命周期内保持局部变量的存在, 使用 static 修饰局部变量可以在函数调用之间保持局部变量的值。 static 修饰符也可以应用于全局变量。当 static 修饰全局变量时，会使变量的作用域限制在声明它的文件内。
// static example: 每次调用函数，函数中的值不会被重置，所以对于不需要覆盖的场景可用，不需要写到函数外部去。
static int count=10; /* 全局变量 - static 是默认的 */
void func_static(void) {
    static int thingy = 5;
    thingy ++;
    printf("thingy 为 %d, count 为 %d\n", thingy, count);
}
// extern: 提供一个全局变量的引用，全局变量对所有的程序文件都是可见的。
```

4、运算符：

```
// 逻辑运算符：&& || ！
// 位运算符： & | ^ ~ << >>
// 杂项运算符：sizeof() 返回变量的大小；ptr = &a 返回变量的地址；* 指向一个变量, *ptr 就是变量a；?: 条件表达式
```

5、初始化变量：局部变量被定义时，系统不会对其初始化；全局变量定义时，系统会自动对其初始化。

```
// 正确地初始化变量是一个良好的编程习惯，否则有时候程序可能会产生意想不到的结果。
//static: https://www.runoob.com/w3cnote/cpp-static-usage.html
```

6、函数传递参数方式：传值调用；引用调用

```c
// 传值调用：函数内的参数改变不会影响实际参数。
// 引用调用：指针传递方式，形参为指向实参地址的指针，当对形参的指向操作时，就相当于对实参本身进行的操作。
void swap(int* x, int* y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
    return;
}
```

7、数组

```c
// 传递数组给函数：void myFunction(int *param){}; void myFunction(int param[10]){}; void myFunction(int param[]){}; 
// 从函数返回数组：C 语言不允许返回一个完整的数组作为函数的参数。但是，您可以通过指定不带索引的数组名来返回一个指向数组的指针。返回一维数组：int * myFunction()
// C 不支持在函数外返回局部变量的地址，除非定义局部变量为 static 变量。
int* getRandom() {
    static int r[10];
    int i;
    srand((unsigned)time(NULL)); // 设置种子
    for (i = 0; i < 10; ++i) {
        r[i] = rand();
    }
    return r;
}
// 指向数组的指针: 数组名是一个指向数组中第一个元素的常量指针。
```



## 3、C++ 基础

### 3-1、linux环境安装、windows vs2019安装

### 3-2、C++工作原理：编译与链接

### 3-3、C++变量

1、基本数据类型：int(4字节byte, 32bit), unsigned int(4), char(1),  short(2), long(4), long long(4),  float(4), double(8), bool(1)

2、sizeof(int)

### 3-4、C++ 函数

1、模块化，防止代码重复

2、声明 .h, 定义 .cpp

3、不要抽出太多函数，程序变慢：每次调用函数时，编译器生成一个call指令。为了调用一个函数，需创建一个堆栈结构，把参数和返回地址等推进堆栈。需要调到二进制执行文件不同部分执行函数指令，内存中跳跃执行函数，跳跃和执行都需要时间。

### 3-5、C++头文件

1、头文件保护：防止头文件被多次调用导致重定义错误

```c++
// 方法1：
#pragma once

// 方法2：
#ifndef _LOG_H  // 如果 _LOG_H 宏没有被定义
#defind _LOG_H   // 那么定义它，防止重复包含
// 这里放置头文件的内容
#endif
```

2、引用头文件

” 相对路径 “； <路径>

3、标准库：.h 是C (stdlib.h), 无.h是C++(iostream)

### 3-6、vs调试

1、断点、读取内存

### 3-7、条件与分支（if）





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

