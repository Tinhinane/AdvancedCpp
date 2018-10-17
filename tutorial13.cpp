/*topic advanced features on functions in C++*/
#include <iostream>
#include <functional>
#include <vector>

double MultBy2(double num){
    return num*2;
}

double MultBy3(double num){
   return num*3;
}

double DoMath(std::function<double(double)> func, double num){
    return func(num);
}
/*PROBLEM:
a function that receives a list and and returns a list of
odd values from that list*/
bool IsNumOdd(int num){
        if(num%2==0)
            return true;
        else
            return false;
}

std::vector<int> GenerateOddList(std::vector<int> oldList, std::function<bool(int)> verifOdd){
    std::vector<int> v;
    for(const auto& i : oldList) // access by const reference
        if(verifOdd(i))
            v.push_back(i);
    return v;
}


int main()
{
  auto times2 = MultBy2;
  std::cout << "5 * 2 = " << times2(5) << "\n";
  std::cout << "6 * 2 = " << DoMath(times2, 6) << "\n";
  //store different functions in a vector
  std::vector<std::function<double(double)>> funcs(2);
  //now reference by index
  funcs[0] = MultBy2;
  funcs[1] = MultBy3;

  std::cout << IsNumOdd(5) << "\n";
  std::cout << IsNumOdd(4) << "\n";
  std::vector<int> testVector = {0, 1, 2, 3, 4, 5};
  std::vector<int> returnedVector = GenerateOddList(testVector, IsNumOdd);
  for(const auto& i : returnedVector)
    std::cout << i << " ";
}
