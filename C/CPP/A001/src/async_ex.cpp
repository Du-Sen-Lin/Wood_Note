#include <iostream>
#include <future>
#include <chrono>

int add(int a, int b) {
    // 模拟一个耗时的操作
    std::this_thread::sleep_for(std::chrono::seconds(20));
    return a + b;
}

int main() {
    // 启动异步任务
    // std::future<int> result = std::async(add, 2, 3);

    // 使用 std::launch::async 强制立即启动异步任务
    std::future<int> result = std::async(std::launch::async, add, 2, 3);

    // 使用 std::launch::deferred 延迟启动异步任务
    // std::future<int> result = std::async(std::launch::deferred, add, 2, 3);

    // 在这里进行其他操作，主线程不会被阻塞
    for (int i = 0; i < 5; ++i) {
        std::cout << "Main thread is doing other work..." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(5));
    }

    // 获取异步任务的结果
    int sum = result.get();

    std::cout << "Sum: " << sum << std::endl;

    return 0;
}
// g++ -pthread async_ex.cpp -o async_ex
// ./async_ex
