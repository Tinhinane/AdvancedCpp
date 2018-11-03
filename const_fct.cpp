#include <iostream>
using namespace std;

//const functions
//A function becomes const when const keyword is used in function’s declaration.
//A const function is not allow to modify the object on which they are called.

class Student{
    // Access specifier
    public:
    //Default constructor
    Student(){
        _id = 1892;
    }
    //const parameter
    void set_id(const int& id){
        _id = id;
    }
    //const return value
    const int& get_id(){
        return _id;
    }
    //add the keyword "const" at the end of a funct declaration to make it a const function
    //a const function can only call another const function
    void print_student() const{
        //changing data members in const functions is illegal
        //because "this" pointer type is "const Student* const"
        //meaning it is const pointer pointing to a const value
        //_id = 2000;
        cout << "const fct" << endl;
        cout << "Student id is : " << _id << endl;
    }
    //overloading the function with a non-const version
    void print_student() {
        //changing data members is legal
        //because "this" pointer type in non-const member fcts is "Student* const"
        //meaning we can change what it points to, but we cannot change the location memory it points to
        _id = 2000;
        cout << "non-const fct" << endl;
        cout << "Student id is : " << get_id() << endl;
    }

private:
    int _id;
};//a class terminates by a semicolon


int main(){
    Student obj;
    obj.print_student();
    const Student obj2;
    obj2.print_student();
    return 0;
}
