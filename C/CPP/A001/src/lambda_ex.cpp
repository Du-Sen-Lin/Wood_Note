#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>


void ForEach(const std::vector<int>& values, void(*func)(int)){
    for(int value : values)
        func(value);
}

void ForEach2(const std::vector<int>& values, const std::function<void(int)>& func){
    for(int value : values)
        func(value);
}

int main(){
    std::vector<int> values = {1, 5, 4, 2, 3};

    // 用完即弃的lambda 函数, []叫捕获方式，也就是如何传入传出参数
    ForEach(values, [](int value) {std::cout << "Value: " << value << std::endl; });
    auto lambda = [](int value) {std::cout << "Value: " << value << std::endl; };
    ForEach(values, lambda);

    // 有变量传入
    int a = 5;
    // = 按值传入所有的变量
    auto lambda2 = [=](int value) {std::cout << "Value: " << a << std::endl; };
    ForEach2(values, lambda2);

    // std::find_if
    auto it = std::find_if(values.begin(), values.end(), [](int value){return value > 3;});
    std::cout << *it << std::endl;
    // 输出找到的元素的位置
    if (it != values.end()) {
        std::cout << "First element greater than 3 found at position: " << std::distance(values.begin(), it) << std::endl;
    } else {
        std::cout << "No element greater than 3 found." << std::endl;
    }
    std::cin.get();
}
// g++ lambda_ex.cpp -o lambda_ex
// ./lambda_ex 