#include<iostream>
#include<thread>

static bool s_Finished = false;

void DoWork(){
    using namespace std::literals::chrono_literals;
    std::cout << "Started thread id=" << std::this_thread::get_id() << std::endl;
    while(!s_Finished){
        std::cout << "Working...\n";
        std::this_thread::sleep_for(1s);
    }
}

int main(){
    std::thread worker(DoWork);
    std::cin.get();
    s_Finished = true;

    worker.join(); // 在主线程上等待工作进程完成所有的执行后，再继续执行主线程。
    std::cout << "Finished." << std::endl;
    std::cout << "Started thread id=" << std::this_thread::get_id() << std::endl; //id 与DoWork不一致，因为在不同线程上
    std::cin.get();
}
// 在 Linux 系统上，需要使用 -pthread 标志来链接线程库。在编译和链接时添加这个标志可以解决这个问题。修改编译命令如下：
// g++ -pthread thread_ex.cpp -o thread_ex
// ./thread_ex