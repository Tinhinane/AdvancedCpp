#include <iostream>
using namespace std;

/**
Use cases of references in C++
- T&&: Called rvalue-reference, binds to both prvalues and xvalues without any
implicit conversions.
- T const&: Called const lvalue-reference, can also bind to non-const objects,
both lvalues and rvalues.
- T&: Called lvalue-reference, can only bind to lvalues.
**/

void fun(int const& a) { cout << 1; }// c will call this function
void fun(int& a) { cout << 2; } // a will call this function
void fun(int&& a) { cout << 3; }// variable 23 will call this function

int main(){

    int a;
    int const c{};
    fun(23);
    fun(a);
    fun(c);

    return 0;
}
