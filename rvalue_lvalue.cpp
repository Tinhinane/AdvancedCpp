#include <iostream>
using namespace std;

int square(int& x){
// square(40) raises an error
// error: cannot bind non-const lvalue reference of type ‘int&’ to an rvalue of type ‘int’
    cout << "square int& x" << endl;
    return x*x;
}

int square(const int& x) {
    cout << "square const int& x" << endl;
    return x*x;
}

int main(){
    /*simplified definition
    *lvalue: any object that occupies an identifiable memory location
    *rvalue: defined by exclusion
    */

    //part 1: lvalue example
    int i; //i is an lvalue
    int* p = &i; //i's address is identifiable
    i = 2; //memory content is modifiable

    cout << "i content is : " << i << endl;
    cout << "i address is (p): " << p << endl;

    //part 2: rvalue examples
    int j = 4; // 4 is an rvalue
    j = (i+2); //(i+2) is an rvalue
    //int* ptr = &(i+2);//  error: lvalue required as unary ‘&’ operand

    //part 3: references (lvalue references)
    int k;
    int& ref = k; //ref is an lvalue reference
    ref = 5;//OK

    //int& ref2 = 5; // error: cannot bind non-const lvalue reference of type ‘int&’ to an rvalue of type ‘int’
    //exception : a constant lvalue reference
    const int& ref3 = 5;
    cout << ref3 << endl;

    cout << square(i) << endl;
    cout << square(40) << endl;

    return 0;
}
