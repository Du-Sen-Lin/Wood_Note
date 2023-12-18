#include <iostream>

// 静态

// #include <iostream>

// int main() {
//     const int rows = 3;
//     const int cols = 4;

//     // 二维数组
//     int matrix[rows][cols] = {
//         {1, 2, 3, 4},
//         {5, 6, 7, 8},
//         {9, 10, 11, 12}
//     };

//     // 访问元素
//     std::cout << "Element at matrix[1][2]: " << matrix[1][2] << std::endl;

//     return 0;
// }


// 动态
int main() {
    const int rows = 3;
    const int cols = 4;

    // 动态二维数组
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
    }

    // 初始化元素
    int counter = 1;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = counter++;
        }
    }

    // 访问元素
    std::cout << "Element at matrix[1][2]: " << matrix[1][2] << std::endl;

    // 释放内存
    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}

// g++ multi_array_ex.cpp -o multi_array_ex
// ./multi_array_ex  