#include <iostream>
using namespace std;

//const functions
//A function becomes const when const keyword is used in function’s declaration.
//A const function is not allow them to modify the object on which they are called.

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
        cout << "const fct" << endl;
        cout << "Student id is : " << _id << endl;
    }
    //overloading the function with a non-const version
    void print_student() {
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
