#include<iostream>
#include<string>

// 1、函数重载
// void Print(int value){
//     std::cout << value << std::endl;
// }

// void Print(float value){
//     std::cout << value << std::endl;
// }

// void Print(std::string value){
//     std::cout << value << std::endl;
// }

// 2、模板 templates
template<typename T>
void Print(T value){
    std::cout << value << std::endl;
}

int main(){
    Print(5);
    Print("Wood");
    Print(5.5f);
    std::cin.get();
}

// g++ templates_ex.cpp -o templates_ex
// ./templates_ex
