#include <iostream>
#include <vector>

using namespace std;

//abstract base class
class Food{
public:
    //pure virtual function
    Food(const std::string& n)
        :_name(n)
    {}
    virtual bool is_vegetarien() = 0;
    std::string get_name() const{
        return _name;
    }
    virtual ~Food() = default;
protected:
    std::string _name;
};

class Pizza: public Food{
public:
    Pizza(std::string n, bool veg)
        :Food(n), _veg(veg)
    {}
    bool is_vegetarien() override{
        return _veg;
    }

    ~Pizza(){}
protected:
    bool _veg;
};

class Pizza_Roll: public Pizza{
public:
    Pizza_Roll(std::string n, bool veg)
        :Pizza(n+" roll", veg)
    {}
};

class Salad: public Food{
public:
    Salad(std::string n)
        :Food(n)
    {}
    bool is_vegetarien() override{
        return true;
    }
};

/*
base class of all guest types. Contains the name of the guest, a virtual function
prefer which takes an object of type Food and returns true and a function eat which
takes a Food object and prints a message whether or not the guest prefers that food.
The message should have the following format: <name of guest> eat <name of food>.
if the guest prefers the food and <name of guest> does not want <name of food>.
if the guest does not prefer the food.
*/
class Guest{
public:
    Guest(std::string gn)
        :_gname(gn)
    {}
    virtual bool prefer(Food* food){ return true; }
    void eat(Food* food){
        if(this->prefer(food)){
            std::cout << _gname << " eats " << food->get_name() << endl;
        }
        else{
            std::cout << _gname << " does not want " << food->get_name() << endl;
        }
    }
    virtual ~Guest() = default;
protected:
    std::string _gname;
};

class Salad_Lover: public Guest{
public:
    Salad_Lover(std::string gn)
        :Guest(gn)
    {}
    bool prefer(Food* food) override{
        return (typeid(*food).name()==typeid(Salad).name());
    }
};

class Pizza_Lover: public Guest{
public:
    Pizza_Lover(std::string gn)
        :Guest(gn)
    {}
    bool prefer(Food* food) override{
        return (typeid(*food).name()==typeid(Pizza).name());
    }
};

class Vegetarian: public Guest{
public:
    Vegetarian(std::string gn)
        :Guest(gn)
    {}
    bool prefer(Food* food) override{
        return food->is_vegetarien();
    }
};

/* if implemented correctly this program
   should give the following output:

Gus eat Vegetarian Pizza.
Gus eat Calzone.
Gus eat Ham Pizza roll.
Gus eat Vegetarian Pizza roll.
Gus eat Salad.
Sally does not want Vegetarian Pizza.
Sally does not want Calzone.
Sally does not want Ham Pizza roll.
Sally does not want Vegetarian Pizza roll.
Sally eat Salad.
Pete eat Vegetarian Pizza.
Pete eat Calzone.
Pete does not want Ham Pizza roll.
Pete does not want Vegetarian Pizza roll.
Pete does not want Salad.
Velma eat Vegetarian Pizza.
Velma does not want Calzone.
Velma does not want Ham Pizza roll.
Velma eat Vegetarian Pizza roll.
Velma eat Salad.
*/

int main()
{
    vector<Guest*> guests {
         new Guest {"Gus"},
         new Salad_Lover {"Sally"},
         new Pizza_Lover {"Pete"},
         new Vegetarian {"Velma"}
    };

    // the true and false parameters represents
    // wheter or not the pizza/pizza roll is vegetarian
    vector<Food*> foods {
        new Pizza {"Vegetarian Pizza", true},
        new Pizza {"Calzone", false},
        new Pizza_Roll {"Ham Pizza", false},
        new Pizza_Roll {"Vegetarian Pizza", true},
        new Salad {"Salad"}
    };
    for (auto guest : guests)
    {
        for (auto food : foods)
        {
             guest->eat(food);
        }
    }
}
