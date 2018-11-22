#include <iostream>
#include <sstream>
using namespace std;

struct X { };

ostream& operator<<(ostream& os, X const&)
{
  return os << "X";
}

namespace method_a{
    //The base case: to produce an empty line when zero argument passed
    void print() {
        cout << "\n";
    }

    // The recursive case: we take an argument, alongside
    // some other args, and print them
    template <typename T, typename...Args>
    void print(T arg, Args...args){
        cout << arg << " ";
        print(args...);
    }
};
//fold expressions
namespace method_fe{
    /*
    C++17
    Fold expressions can expand using any operator including the comma-operator

    Assume that we call:
    print(1, 2, 3)

    Then this fold will expand to:

    (cout << 1 << " "), (cout << 2 << " "), (cout << 3 << " "), (cout << '\n')

    which is equivalent to:

    cout << 1 << " ";
    cout << 2 << " ";
    cout << 3 << " ";
    cout << '\n';
  */
    template <typename...Args>
    void print(Args...args)
    {
        ((std::cout << args << " "), ... , (std::cout << '\n'));
    }
};

int main()
{
  // should produce an empty line
  method_a::print();
  method_fe::print();

  // a 3.5 100 hello
  method_a::print('a', 3.5, 100, "hello");
  method_fe::print('a', 3.5, 100, "hello");

  // should produce:
  // a b
  method_a::print('a', 'b');
  method_fe::print('a', 'b');

  // should produce:
  // X Y Z
  method_a::print(X{}, "Y", "Z");
  method_fe::print(X{}, "Y", "Z");

}
