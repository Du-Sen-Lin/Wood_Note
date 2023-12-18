#include<iostream>
#include<thread>
#include<chrono>


// struct Timer{
//     std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
//     std::chrono::duration<float> duration;
//     Timer(){
//         start = std::chrono::high_resolution_clock::now();
//     }
//     ~Timer(){
//         end = std::chrono::high_resolution_clock::now();
//         duration = end - start;
//         float ms = duration.count()*1000.0f;
//         std::cout<<"Timer took " << ms << "ms" << std::endl;
//     }
// };


class Timer
{
public:
    Timer() : beg_(clock_::now()) {} // 构造函数：初始化计时器，记录当前时间点。
    void reset() { beg_ = clock_::now(); } // reset 函数：重置计时器，将起始时间点设置为当前时间点。
    // double elapsed() const { // elapsed 函数：计算自上次重置以来经过的时间，并以秒为单位返回。
    //     return std::chrono::duration_cast<second_>
    //         (clock_::now() - beg_).count(); }
    double elapsed() const { // elapsed 函数：计算自上次重置以来经过的时间，并以毫秒为单位返回。
        return std::chrono::duration_cast<second_>
            (clock_::now() - beg_).count() * 1000.0f; }    
    void out(std::string message = ""){ // out 函数：输出经过的时间，并可附带一条消息。
        double t = elapsed();
        std::cout << message << "\nelasped time:" << t << "ms\n" << std::endl;
        reset();
    }
private:
    typedef std::chrono::high_resolution_clock clock_;
    typedef std::chrono::duration<double, std::ratio<1> > second_;
    std::chrono::time_point<clock_> beg_;
};


void Function(){
    Timer timer;
    for (int i=0; i<100; i++){
        // std::cout << "Hello" << std::endl;
        std::cout << "Hello\n";
    }
    // 输出经过的时间
    timer.out("Task completed");    
}


int main(){
    // using namespace std::literals::chrono_literals;

    // auto start = std::chrono::high_resolution_clock::now();
    // std::this_thread::sleep_for(1s);
    // auto end = std::chrono::high_resolution_clock::now();
    // std::chrono::duration<float> duration = end - start;
    // std::cout << duration.count() << "s " << std::endl;

    Function(); // 0.09358ms
 
    std::cin.get();
}
// g++ time_chrono_ex.cpp -o time_chrono_ex
// ./time_chrono_ex
