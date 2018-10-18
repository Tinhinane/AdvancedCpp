#include <iostream>
using namespace std;

void intialization_test(){
    //1: Copy initialization
    int x = 7; //OK
    cout << "x is " << x << endl;
    int y = 7.2; //y will become 7 (BAD) because copy initialization implicitly converts a value to make it work
    cout << "y is " << y << endl;

    /*2: Direct initialization
    *try to convert the supplied value to the same type as the object.
    */
    int k(7);
    cout << "k is " << k << endl;
    int l(12.2);
    cout << "l is " << l << endl;

    /*3: Value initialization
    * Call a default constructor to initialize the object
    */
    int num{};
    cout << "num is " << num << endl;
    bool test{};
    cout << "test is " << test << endl;

    /*4: List initialization
    *Narrowing conversions are prohibited during list initializations.
    *Prefer list initialization, it is less prone to errors.
    */
    int x1{7.2}; //error: narrowing conversion of ‘7.2000000000000002e+0’ from ‘double’ to ‘int’
    char c1{1024}; //error
    int x2{7};
}

int main(){
    // int x{2};
    // if(x=0)
    //     cout << "x is zero" << endl;
    // else
    //     cout << "Value of x is " << x << endl;

    intialization_test();

    return 0;
}
