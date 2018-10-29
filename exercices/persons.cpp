/***
Define a type for storing a persons name (first and last name as two separate strings) and address
(street, post code and city as three separate strings). Overload the operator>> and operator<< to
read and write, respectively, such data, given a certain format (e.g first and last name in that order
on the first line and the three parts of the address on three successive lines). Write a test program
which copies a stream of names and addresses.
***/
#include <iostream>
#include <vector>
#include <sstream>
#include <iterator>
#include <string>
using namespace std;

class Person{
public:
    Person(string fn="", string ln="", string st="", string pc="", string ct="")
        :_firstname(fn), _lastname(ln), _street(st), _postcode(pc), _city(ct){}
    //insertion and extraction operators
    friend std::ostream& operator<<(std::ostream& os, const Person& obj);
    friend std::istream& operator>>(std::istream& is, Person& obj);
private:
    string _firstname;
    string _lastname;
    string _street;
    string _postcode;
    string _city;
};

std::ostream& operator<<(std::ostream& os, const Person& obj){
    // write obj to stream
    os << obj._firstname << " " << obj._lastname << "\n" << obj._street << "\n"
    << obj._postcode << "\n" << obj._city;
    return os;
}

//How to stop reading
std::istream& operator>>(std::istream& is, Person& obj){
    cout << "Enter name: " << endl;
    string fullname;
    getline(is, fullname);
    //extract firstname and lastname (format firstname lastnames)
    //More about strings and stringstreams: https://stackoverflow.com/questions/312245/what-are-the-string-stream-and-stringstream-classes-in-c
    std::istringstream txt(fullname);
    std::vector<std::string> results(std::istream_iterator<std::string>{txt},
                                 std::istream_iterator<std::string>());
    obj._firstname = results[0];
    const char* const delim = " ";
    std::ostringstream lastname;
    std::copy(results.begin()+1, results.end(),
           std::ostream_iterator<std::string>(lastname, delim));
    obj._lastname = lastname.str();

    cout << "Enter your address" << endl;
    getline(is, obj._street);
    getline(is, obj._postcode);
    getline(is, obj._city);
    return is;
}

int main(){
    Person p;
    cin>>p;
    cout << "The person's info: " << endl;
    cout << p;
    return 0;
}
