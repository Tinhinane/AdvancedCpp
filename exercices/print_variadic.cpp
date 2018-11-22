#include <iostream>

using namespace std;

struct X { };

ostream& operator<<(ostream& os, X const&)
{
  return os << "X";
}

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

int main()
{
  // should produce an empty line
  print();

  // should produce:
  // a 3.5 100 hello
  print('a', 3.5, 100, "hello");

  // should produce:
  // a b
  print('a', 'b');

  // should produce:
  // X Y Z
  print(X{}, "Y", "Z");
}
