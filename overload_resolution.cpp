#include <iostream>

/*Rule: overload resolution decides which function to call:
1. exact matches, if fails then try 2
2. function templates (specialization will be used if the
primary template is considered;), if fails then 3
3. argument conversions, if fails then overload resolution failed!
*/

template <typename T>
void print(T) { std::cout << "1\n"; }
//template explicit specialization
template <>
void print<int>(int) { std::cout << "2\n"; }

void print(int&&) { std::cout << "3\n"; }

int main(){
    int x{};
    print(1.0);//exact match fails, so it will call function template, print 1
    print(1);//exact match works, so it will print 3
    print(x);//exact match fails, so it will consider function templates, and will pick the specialization, prints 2
}
