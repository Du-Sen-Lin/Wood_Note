#include<iostream>
#include<vector>

int main(){
    std::vector<int> myVector; // 创建一个存储整数的空向量

    myVector.push_back(10); // 将10添加到向量末尾
    myVector.push_back(20); // 将20添加到向量末尾
    myVector.push_back(30);

    int value = myVector[0]; // 访问第一个元素，值为10
    int size = myVector.size(); // 获取向量的大小，此时为2
    for (int i = 0; i < myVector.size(); ++i) {
        std::cout << myVector[i] << " ";
    }
    std::cout<<std::endl;
    // myVector.pop_back(); // 删除向量末尾的元素
    myVector.erase(myVector.begin() + 1); // 移除某一个元素
    for (auto it = myVector.begin(); it != myVector.end(); ++it) {
        std::cout << *it << " ";
    }
    myVector.clear(); // 清空向量，使其变为空    
    std::cin.get();    
}

// g++ vector_ex.cpp -o vector_ex
// ./vector_ex