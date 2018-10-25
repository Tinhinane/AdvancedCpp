#include <iostream>
using namespace std;

/***
Define a class Integer which acts as int but for which only the following operations are
allowed: + (both unary and binary), - (both unary and binary), *, /, %, ++ and -- (both in prefix
and postfix versions, with the same semantics as for int). How can you make these operations
also legal for mixed expressions with int and Integer?
Overload operator << and operator >> for Integer. Could be a good idea to implement
operator<< first of all operators.
***/
class Integer{
public:
    Integer(int i=0){ _i=i;}
    //insertion and extraction operators
    friend std::ostream& operator<<(std::ostream& os, const Integer& obj);
    friend std::istream& operator>>(std::istream& is, Integer& obj);
    Integer& operator++()//prefix increment
    {
        // actual increment takes place here
        _i++;
        return *this;
    }
    //The int parameter is a dummy parameter used to differentiate between
    //prefix and postfix versions of the operators.
    //Post-increment creates a copy of the object,
    //increments the value of the object
    //returns the copy from before the increment
    Integer operator++(int)//postfix increment
    {
        Integer tmp(*this); // copy
        this->_i++; // pre-increment
        return tmp; // return old value
    }
    //Unary + and - operators Because operator-
    //They do not modify the Integer object sent
    //We should make them const functions
    Integer operator+() const{
        return Integer(_i);
    }
    Integer operator-() const{
        return Integer(-this->_i);
    }
    /***
    *Binary operators are typically implemented as non-members to maintain
    *symmetry (for example, when adding a Integer object and an integer, if
    *operator+ is a member function of the Integer type, then only
    *Integer+integer would compile, and not integer+Integer).
    ***/
    friend Integer operator+(const Integer& lhs, const Integer& rhs);
    friend Integer operator-(const Integer& lhs, const Integer& rhs);
    friend Integer operator*(const Integer& lhs, const Integer& rhs);
    friend Integer operator/(const Integer& lhs, const Integer& rhs);
    friend Integer operator%(const Integer& lhs, const Integer& rhs);
    //postfix increment

private:
    int _i;
};

/***
*1) cout is an object of ostream class
*2) These operators must be overloaded as a global function,
*and if we want to allow them to access private data members of class,
*we must make them friend.
***/
std::ostream& operator<<(std::ostream& os, const Integer& obj)
{
    // write obj to stream
    os << obj._i;
    return os;
}

//cin is an object of istream class
//note that parameter point must be non-const so we can modify the class members
//with the input values
std::istream& operator>>(std::istream& is, Integer& obj)
{
    is >> obj._i;
    return is;
}

Integer operator+(const Integer& lhs, const Integer& rhs)
{
   return Integer(lhs._i + rhs._i);
}

Integer operator-(const Integer& lhs, const Integer& rhs)
{
   return Integer(lhs._i - rhs._i);
}

Integer operator*(const Integer& lhs, const Integer& rhs)
{
   return Integer(lhs._i * rhs._i);
}

Integer operator/(const Integer& lhs, const Integer& rhs)
{
   return Integer(lhs._i / rhs._i);
}

Integer operator%(const Integer& lhs, const Integer& rhs)
{
   return Integer(lhs._i % rhs._i);
}

int main(){
    Integer my_int(3);
    cout << "enter a number" << endl;
    Integer a;
    cin >> a;
    cout << "the number you just entered is: " << a << endl;
    cout << "before postfix increment: " << my_int << " after postfix increment: " << my_int++ << endl;
    cout << "before prefix increment: " << my_int << " after prefix increment: " << ++my_int << endl;
    cout << +my_int << endl;
    cout << -my_int << endl;
    return 0;
}
