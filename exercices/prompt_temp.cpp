#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <sstream>
#include <cassert>
#include <type_traits>
/*** (topic: SFINAE and tag dispatch)
REMINDER: If a function call is performed, overload resolution decides which
function to call according to the following order:
1. exact matches (#1)
2. function templates (#2, #3; differentiate between them go to step 3)
3. argument conversions (e.g. between #2 and #3)
4. overload resolution fails
***/
using namespace std;

//helper functions

//#1 matches only strings
void prompt_helper(std::istream& is, std::string& result, int)
{
    getline(is, result);
}

//#2 A: Containers will fail for all types that don't have a type named size_type
// B: Compiler will select this function and won't consider #3 because the third
// argument 0 matches int type, won't need to go to step 3 (argument conversion)
template<typename T, typename = typename T::size_type>
void prompt_helper(std::istream& is, T& result, int)
{
    using vtype = typename T::value_type;
    vtype a{};
    while(is >> a)
        result.push_back(a);
}

//#3 others
template <typename T>
void prompt_helper(std::istream& is, T& result, long){
    is >> result;
}

//Prompt function
template <typename T>
T prompt(std::istream& is)
{
    T result;
    prompt_helper(is, result, 0);
    return result;
}

// Should compile and give no output if everything is correct.
int main()
{
    {
        istringstream iss{"57"};
        auto val = prompt<int>(iss);
        cout << val << "\n";
        assert(val == 57);
    }
    {
        istringstream iss{"3.141592"};
        auto val = prompt<double>(iss);
        cout << val << endl;
        assert(val == 3.141592);
    }
    {
        istringstream iss{"this is a test"};
        auto val = prompt<string>(iss);
        cout << val << endl;
        assert(val == "this is a test");
    }

    {
        vector<int> result{1, 2, 3, 4, 5};
        istringstream iss{"1 2 3 4 5"};
        auto val = prompt<vector<int>>(iss);
        for (auto v: val)
            cout << v << " ";
        cout << endl;
        assert(val == result);
    }
    {
        list<string> result{"this", "is", "a", "test"};
        istringstream iss{"this is a test"};
        auto val = prompt<list<string>>(iss);
        for (auto v: val)
            cout << v << " ";
        cout << "\n";
        assert(val == result);
    }
}
