#include <iostream>
using namespace std;

/**
Use cases of references in C++
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
