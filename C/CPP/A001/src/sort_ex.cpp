#include <algorithm>
#include <array>
#include <functional>
#include <iostream>
#include <string_view>
 
int main()
{
    std::array<int, 10> s {5, 7, 4, 2, 8, 6, 1, 9, 0, 3};
 
    auto print = [&s](std::string_view const rem)
    {
        for (auto a : s)
            std::cout << a << ' ';
        std::cout << ": " << rem << '\n';
    };
 
    std::sort(s.begin(), s.end());
    print("sorted with the default operator<");
 
    std::sort(s.begin(), s.end(), std::greater<int>());
    print("sorted with the standard library compare function object");
 
    struct
    {
        bool operator()(int a, int b) const { return a < b; }
    }
    customLess;
 
    std::sort(s.begin(), s.end(), customLess);
    print("sorted with a custom function object");
 
    std::sort(s.begin(), s.end(), [](int a, int b)
                                  {
                                      return a > b;
                                  });
    print("sorted with a lambda expression");
}
// g++ -std=c++17 sort_ex.cpp -o sort_ex
// ./sort_ex
// 正在使用的是 Ubuntu 18.04 的发行版提供的 g++ 编译器，版本号为 7.5.0。这是 Ubuntu 18.04 LTS 版本中默认的 GCC 版本，用于编译 C++ 代码. 
//     在这个版本的 g++ 中，默认使用的是 C++14 标准。在 Ubuntu 18.04 中，C++14 被设置为默认的 C++ 标准。
// 使用 -std 选项来指定支持的 C++ 标准, 这儿 可以在编译时显式指定使用 C++17 标准，在这个版本的 g++ 中，C++17 标准是支持的。
// 常见的 C++ 标准：
/*
C++98： 最初的 C++ 标准，包含了最早的 C++ 特性。
C++03： 对 C++98 的一些纠正，没有引入新的特性。
C++11： 引入了一些新特性，如 auto 关键字、lambda 表达式等。
C++14： 对 C++11 的一些扩展，引入了一些新特性。
C++17： 引入了一些新特性，如 std::optional、std::variant、std::string_view 等。
C++20： 最新的 C++ 标准，引入了许多新特性，如概念、范围-based for 循环的初始化语句、协程等。
*/