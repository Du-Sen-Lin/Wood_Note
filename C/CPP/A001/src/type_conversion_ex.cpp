#include<iostream>


class Base {
    virtual void foo() {}
};

class Derived : public Base{};
int main(){

    // 静态转换（static_cast）：
    // 用于基本类型之间的转换，以及具有继承关系的类之间的转换。
    // 在编译时进行检查，相对安全。
    int a = 10;
    double b = static_cast<double>(a);

    // 动态转换（dynamic_cast）
    // 用于类层次结构中的多态类型转换，需要有虚函数。
    // 在运行时进行检查，只能用于指针或引用。
    Base* basePtr = new Derived();
    Derived* derivedPtr = dynamic_cast<Derived*>(basePtr);

    // 常量转换（const_cast）:
    // 用于添加或删除变量的常量性。
    // 主要用于指针或引用
    const int c = 10;
    int* d = const_cast<int*>(&c);
    
    // 重新解释转换（reinterpret_cast）：
    // 用于不同类型之间的二进制位的转换，通常用于指针之间的转换。
    // 非常危险，慎用。
    // int* ptr = reinterpret_cast<int*>(someVoidPointer);


    std::cin.get();
}
// g++ type_conversion_ex.cpp -o type_conversion_ex
// ./type_conversion_ex