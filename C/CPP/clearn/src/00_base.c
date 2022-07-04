/* https://www.runoob.com/cprogramming/c-functions.html */

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <time.h>

// 1、extern ex: 声明变量名而不定义, 不需要建立存储空间。需要在一个源文件中引用另外一个源文件中定义的变量，我们只需在引用的文件中将变量加上 extern 关键字的声明即可。
extern int i; //声明，不是定义

// 2、常量定义：#define 预处理器；const 关键字
// 前缀：0x 十六进制 0 八进制 后缀：后缀是 U 和 L 的组合，U 表示无符号整数（unsigned），L 表示长整数（long）
#define WINDTH 5
const int HEIGHT = 10;

// 3、存储类: auto register static extern 定义C程序中变量/函数的范围（可见性）和生命周期。
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

// 4、运算符：
// 逻辑运算符：&& || ！
// 位运算符： & | ^ ~ << >>
// 杂项运算符：sizeof() 返回变量的大小；ptr = &a 返回变量的地址；* 指向一个变量, *ptr 就是变量a；?: 条件表达式

// 5、初始化变量：局部变量被定义时，系统不会对其初始化；全局变量定义时，系统会自动对其初始化。
// 正确地初始化变量是一个良好的编程习惯，否则有时候程序可能会产生意想不到的结果。
//static: https://www.runoob.com/w3cnote/cpp-static-usage.html

// 6、函数传递参数方式：传值调用；引用调用
// 传值调用：函数内的参数改变不会影响实际参数。
// 引用调用：指针传递方式，形参为指向实参地址的指针，当对形参的指向操作时，就相当于对实参本身进行的操作。
void swap(int* x, int* y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
    return;
}

// 7、数组
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

int main(int argc, char const *argv[])
{
    printf("int size: %lu \n", sizeof(int));
    int i = 2;
    printf("$$ %d\n", i);

    printf("$$ %d\n", WINDTH * HEIGHT);

    while (count --) {
        func_static();
    }
    
    int a = 100, b = 200;
    swap(&a, &b); // &a 表示指向 a 的指针，即变量 a 的地址
    printf(" a: %d \t b: %d \n", a, b);

    int *p;
    p = getRandom();
    for (int i=0; i< 10; i++) {
        printf( "*(p + %d) : %d\n", i, *(p + i));
    }
    return 0;
}
