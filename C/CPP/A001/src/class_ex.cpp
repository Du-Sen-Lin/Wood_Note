#include<iostream>
#include<string>

class Entity
{
private:
    std::string m_Name;
    int m_Age;
public:
    Entity(const std::string& name):m_Name(name), m_Age(-1){}
    Entity(int age):m_Name("UnKnown"), m_Age(age){}
};

int main(){
    //常用方式（栈）
    // Entity a("Wood");
    // Entity b(25);

    // 隐式转换（隐式构造函数）
    Entity a = "Wood";
    Entity b = 22;

    std::cin.get();
}