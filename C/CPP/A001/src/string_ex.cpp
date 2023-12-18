#include<iostream>
#include<string>
#include<cstring>

class String{
private:
    char* m_Buffer;
    unsigned int m_Size;
public:
    String(const char* string){
        m_Size = strlen(string);
        m_Buffer = new char[m_Size + 1];
        memcpy(m_Buffer, string, m_Size + 1);
        //  memcpy(m_Buffer, string, m_Size);
        //  m_Buffer[m_Size] = 0;
    }
    // 添加拷贝构造函数
    String(const String& other): m_Size(other.m_Size){
        std::cout<<"copy-------"<<std::endl;
        // m_Size = other.m_Size;
        m_Buffer = new char[m_Size + 1];
        memcpy(m_Buffer, other.m_Buffer, m_Size + 1);
    }    
    ~String(){ // 不加会内存泄漏
        delete[] m_Buffer;
    }
    char& operator[](unsigned int index){
        return m_Buffer[index];
    }
    friend std::ostream& operator<<(std::ostream& stream, const String& string);
};

std::ostream& operator<<(std::ostream& stream, const String& string){
    stream << string.m_Buffer;
    return stream;
}

// 不写 void PrintString(String string)，这样会多次调用拷贝构造函数，每次调用都会发生复制，浪费性能。直接传引用，只发生String second = string 这一个复制。
void PrintString(const String& string){
    std::cout<<string<<std::endl;
}

int main(){
    String string = "Wood";
    // 赋值 -- 崩溃：浅拷贝，默认的拷贝构造函数。代码中，当你执行 String second = string; 时，实际上只是将 m_Buffer 的指针从 string 复制到了 second，而不是创建一个新的内存副本。
    // string 和 second 都被销毁时，它们会尝试释放相同的内存，导致了问题。
    // 需要实现一个自定义的拷贝构造函数，以确保在创建新对象时会分配新的内存并复制原始字符串。
    // String second = string;
    // std::cout << string << std::endl;
    // std::cout << second << std::endl;

    // 要做的：分配一个新的char数组，来存储复制的字符串。深拷贝，实现拷贝构造函数。
    String second = string;
    second[2] = 'a';
    PrintString(string);
    PrintString(second);
    // std::cout << string << std::endl;
    // std::cout << second << std::endl;

    
    std::cin.get();
}

// g++ string_ex.cpp -o string_ex
// ./string_ex