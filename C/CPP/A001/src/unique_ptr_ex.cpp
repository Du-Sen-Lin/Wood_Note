#include<iostream>
#include<string>
#include<memory>

class Entity{
public:
    Entity(){
        std::cout<<"Create Entity!"<<std::endl;
    }

    ~Entity(){
        std::cout<<"Destroyed Entity!"<<std::endl;
    }
    void Print(){}
};

int main(){
    {
        // std::unique_ptr<Entity> entity(new Entity()); //ok, 一般不这样写
        std::unique_ptr<Entity> entity = std::make_unique<Entity>(); // ok, 异常安全
        // std::unique_ptr<Entity> e0 = entity; // 错误， std::unique_ptr 是一个不能被拷贝的类。 因为它会导致两个 std::unique_ptr 实例共同拥有相同的资源，这是不被允许的。

        // shared_ptr
        std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>();
        std::shared_ptr<Entity> e0 = sharedEntity;

        // 弱指针
        std::weak_ptr<Entity> weakEntity = sharedEntity; // 相比shared_ptr，不会增加引用计数。

        entity->Print();
    }

    std::cin.get();
}
// g++ unique_ptr_ex.cpp -o unique_ptr_ex
// ./unique_ptr_ex
