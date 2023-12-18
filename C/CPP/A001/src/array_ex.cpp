#include <iostream>
#include <array>

int main() {
    // 声明并初始化一个 std::array
    std::array<int, 5> myArray = {1, 2, 3, 4, 5};

    // 访问元素
    std::cout << "Element at index 2: " << myArray[2] << std::endl;

    // 修改元素
    myArray[2] = 10;

    // 遍历数组
    std::cout << "Updated array: ";
    for (const auto& element : myArray) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    // 获取数组大小
    std::cout << "Array size: " << myArray.size() << std::endl;

    // 使用迭代器遍历数组
    std::cout << "Array elements using iterators: ";
    for (auto it = myArray.begin(); it != myArray.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}

// g++ array_ex.cpp -o array_ex
// ./array_ex
