#include<iostream>
#include<vector>

void HelloWorld(){
    std::cout << "Hello World!" << std::endl;
}

// void HelloWorld(int a){
//     std::cout << "Hello World! value: " << a << std::endl;
// }

void PrintValue(int value){
    std::cout << "Value: " << value << std::endl;
}

void ForEach(const std::vector<int>& values, void(*func)(int)){
    for(int value : values)
        func(value);
}

int main(){
    // 方式1： c语言中的原始函数指针
    void(*func)() = HelloWorld;
    func();

    // 方式2：
    typedef void(*HelloWorldFunction)();
    HelloWorldFunction func2 = HelloWorld;
    func2();

    // 方式3：
    auto func3 = HelloWorld;
    func3();

    // typedef void(*HelloWorldFunction)(int);
    // HelloWorldFunction func2 = HelloWorld;
    // func2(8);

    std::vector<int> values = {1, 5, 4, 2, 3};
    ForEach(values, PrintValue);

    // 用完即弃的lambda 函数, []叫捕获方式，也就是如何传入传出参数
    ForEach(values, [](int value) {std::cout << "Value: " << value << std::endl; });

    std::cin.get();
}
// g++ function_ptr_ex.cpp -o function_ptr_ex
// ./function_ptr_ex