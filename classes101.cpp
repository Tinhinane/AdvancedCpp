#include <iostream>
using namespace std;

/**
Classes and Objects in C++
*/

class Student{
    // Access specifier
    public:

    // Data Members
    string name;
    int id;

    //Default constructor
    Student(){
        cout<< "Default constructor called." << endl;
        id = -1;
    }
    //Parametrized constructor
    Student(int id_student){
        cout<< "Parametrized constructor called." << endl;
        id = id_student;
    }

    // Member Functions()

    // printid is a member function not defined inside class definition
    void printid();
    // printname is a member function defined inside class definition
    void printname()
    {
       cout << "student name is: " << name;
    }
};//a class terminates by a semicolon

// Definition of printid using scope resolution operator ::
void Student::printid()
{
    cout << "Student id is: " << id;
}

int main(){
    // Declare an object of class geeks
    Student obj1;
    // accessing data member
    obj1.name = "Tinhinane";
    obj1.id = 142513;
    // accessing member function
    obj1.printname();
    cout << endl;
    obj1.printid();
    cout << endl;
    //Declare another object to test constructors
    Student obj2;
    obj2.printid();
    cout << endl;
    Student obj3(151426);
    obj3.printid();

    return 0;
}
