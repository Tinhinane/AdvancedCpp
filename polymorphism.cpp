#include <iostream>
#include <vector>
//abstract base class
class Entity{
public:
    Entity(const std::string& name)
        :_name(name){
            std::cout << "Entity constructor" << std::endl;
    }
    virtual std::string GetName() = 0;//pure virtual function
    virtual ~Entity() { std::cout << "Entity destructor." << std::endl; }//virtual destructor important to avoid memory leaks
protected:
    std::string _name;
};

class Player: public Entity{
public:
    Player(const std::string& name)
        :Entity(name){
            std::cout << "Player constructor." << std::endl;
    }
    ~Player(){ std::cout << "Player destructor." << std::endl;}
    std::string GetName() override { return "Player: " + _name;}
};

class Moderator: public Entity{
public:
    Moderator(const std::string& name)
        :Entity(name){
            std::cout << "Moderator constructor." << std::endl;
    }
    ~Moderator(){ std::cout << "Moderator destructor." << std::endl;}
    std::string GetName() override { return "Moderator: " + _name;}
};

void printName(Entity* e){
    std::cout << e->GetName() << std::endl;
}

// class Base
// {
// public:
//     Base() { std::cout << "Constructor Base" << std::endl; }
//     virtual ~Base() { std::cout << "Destructor Base" << std::endl; }
// };
// class Derived : public Base
// {
// public:
//     Derived() { std::cout << "Constructor Derived" << std::endl; }
//     ~Derived() { std::cout << "Destructor Derived" << std::endl; }
// };

int main(){
    std::vector<Entity*> entities {
         new Player {"Gus"},
         new Player {"Sally"},
         new Moderator {"Pete"}
    };

    for (auto entity : entities)
    {
        printName(entity);
    }
    // std::cout << "------------" << std::endl;
    // Base* bp{new Derived()};//calls first base constructor then subconstructors
    // std::cout << typeid(*bp).name() << std::endl;
    // delete bp;//calls destructor up to the base destructor
    // std::cout << "------------" << std::endl;
    // Base* base = new Base();
    // std::cout << typeid(*bp).name() << std::endl;
    // delete base;
    return 0;
}
