#include <cstddef> // gives access to size_t
#include <iostream>
#include <string>

/*exercice on function templates*/

using namespace std;

template <typename M>
M add(M const& lhs, M const& rhs){
    return lhs + rhs;
}

double multiply(double const& lhs, double const& rhs)
{
    return lhs * rhs;
}

 /*
   reduce function:
 - a reference to an array of arbitrary size and type,
 - an initial value, which should be default initialized if no value is passed by the caller,
 - a function pointer to a function which takes two const references to some arbitrary
 type, and return a single value of the same type. If the caller omits this parameter
 it should default to addition
  */

template <typename T, size_t size>
T reduce(const T (&array)[size], T x = {}, T(*fct)(T const&, T const&) = add){
    T res = x;
    for(auto el: array){
        res = fct(res, el);
    }
    return res;
}

int main()
{
    double pi[]{0.0505, 0.0505, 0.0405};
    double factorial[]{1.0, 2.0, 3.0, 4.0, 5.0};
    std::string concat[]{" ", "world"};

    std::cout << reduce({1,2,3,4,5}) << std::endl;//res = 15
    std::cout << reduce(pi, 3.0) << std::endl;//res = 3.1415
    std::cout << reduce(factorial, 1.0, multiply) << std::endl;//res = 120
    std::cout << reduce<std::string>(concat, "hello") << std::endl;//res = "hello world"
}
