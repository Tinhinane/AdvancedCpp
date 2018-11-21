#include <iostream>
using namespace std;

//primary template with non-type parameters
template <unsigned long long num>
unsigned long long factorial(){
    return num*factorial<num-1>();
}
//note: specializations override the primary template
template <> unsigned long long factorial<0>() { cout << "fact 0\n"; return 1; }
template <> unsigned long long factorial<1>() { return 1; }

/***REMINDER: non-type parameter templates
all nontype parameters, except for references, are prvalues.
• are not modifiable
• does not have an address
• cannot be bound to lvalue references
***/
template <int x, int& y>
void foo()
{
    //++x; // ill-formed
    ++y; // OK
    //&x; // ill-formed
    &y; // OK
    //int& z = x; // ill-formed
    int& w = y; // OK
}
//int x{};

int main()
{
    //foo<5, x>();
    cout << factorial<0>() << endl;
    cout << factorial<1>() << endl;
    cout << factorial<5>() << endl;
    cout << factorial<20>() << endl;
}
