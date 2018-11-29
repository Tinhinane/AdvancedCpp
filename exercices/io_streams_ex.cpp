#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

//TODO use templates
//reminder: c++ structs everything is by default public
struct format_container{
    format_container(char s='['){
        if(s=='{'){
            start_delim='{'; end_delim = '}';
        }
    }
    mutable std::ostream* out{};
    //default struct values
    char start_delim='[';
    char end_delim=']';
};

/*Create an output operator that takes an ostream and a format_container that
sets the ostream pointer for that format_container and returns it.*/
const format_container& operator<<(std::ostream& os, const format_container& fc){
    fc.out = &os;
    return fc;
}

/*Create another output operator that takes a format_container and a vector and
prints the vector on the given stream according to the example above.*/
std::ostream& operator<<(const format_container& fc, std::vector<int> vec){
    *(fc.out) << fc.start_delim;
    std::vector<int>::iterator itr;
    for(itr = vec.begin(); itr < vec.end()-1; itr++){
        *(fc.out) << *(itr) << ",";
    }
    *(fc.out) << vec.at(vec.size()-1) << fc.end_delim;
    return *(fc.out);
}

int main(){

    vector<int> vec{2, 5, 1, 7, 10};
    format_container fc{'['};
    cout << fc << vec;
    cout << "\n";
    cout << format_container{'{'} << vec;
    return 0;
}
