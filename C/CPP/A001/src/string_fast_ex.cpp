#include <iostream>
#include <string>

static uint32_t s_AllocCount = 0;

void* operator new(size_t size){
    s_AllocCount++;
    std::cout << "Allocating " << size << " bytes\n";
    return malloc(size);
}
#define STRING_VIEW 0
#if STRING_VIEW
void PrintName(std::string_view name){
    std::cout << name << std::endl;
}
#else
void PrintName(const std::string& name){
    std::cout << name << std::endl;
}
#endif

int main(){
    std::string name = "Du Wood";
    // std::string name = "0123456789012345"; //Allocating 17 bytes
    // std::cout << "Allocating " << sizeof(name) << " bytes" << std::endl; // 32

#if STRING_VIEW
    std::string_view firstname(name.c_str(), 3);
    std::string_view sencondname(name.c_str() + 3, 4);
#else
    std::string firstname = name.substr(0, 2);  // 从索引 0 开始，截取 2 个字符
    std::string secondname = name.substr(3, 4);  // 从索引 3 开始，截取 4 个字符
    // s_AllocCount为0 因为 operator new 函数并没有被调用。这可能是由于编译器的一些优化导致的。==> 小字符串，不会触及堆分配。加长就会发现就行了堆分配。
#endif

    PrintName(firstname);

    std::cout << s_AllocCount << " allocations" << std::endl;
    std::cin.get();
}


// int main(){ // 不会产生分配 const char*
//     const char* name = "Du Wood";
//     std::string_view firstname(name, 3);
//     std::string_view sencondname(name + 3, 4);
//     PrintName(firstname);
//     std::cout << s_AllocCount << " allocations" << std::endl;
//     std::cin.get();
// }

// g++ -std=c++17 string_fast_ex.cpp -o string_fast_ex
// ./string_fast_ex