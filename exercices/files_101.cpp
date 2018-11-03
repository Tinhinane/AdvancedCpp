#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

class ifcharstream
{
public:
    ifcharstream(const char* filename);
    void close();
    bool is_open();
    //Const function in order to make changes on data members illegal
    //Accessor operator[]---> used for reading characters from a text file
    char operator[](streampos pos);
private:
    ifstream _file; //file to read from
    bool _open;
};

ifcharstream::ifcharstream(const char* filename){
    _file.open(filename, ios::in);
    if (!_file)
    {
       throw invalid_argument("Could not open file! Boo :(");
    }
    _open = true;
}

bool ifcharstream::is_open(){
    return _open;
}

void ifcharstream::close(){
    _file.close();
    _open = false;
}

char ifcharstream::operator[](streampos pos){
    if (!_open) return '\0';
    char c;
    _file.seekg(pos);//istream&  seekg ( streampos position );
    c = _file.get();
    return c;
}

int main(){
    ofstream st;//create an object of ofstream class Name
    st.open("temp.txt"); //create a new file
    if(!st){
        cout << "file creation failed" << endl;
    }
    else{
        cout << "file created." << endl;
        cout << "Give file content: " << endl;
        char text[200];
        //cin.getline(string_name, string_size) allows a string which has white spaces
        cin.getline(text, sizeof(text));
        // Writing on file
        st << text << endl;
        //Test class
        ifcharstream ob{"temp.txt"};
        cout << "is it open?" << ob.is_open() << endl;
        cout << "Give a random file position between 0 and " << strlen(text)-1 << endl;
        unsigned pos;
        cin >> pos;
        cout << "Result: " << ob[pos] << endl;
        ob.close();
        cout << "is it open?" << ob.is_open() << endl;
        remove("temp.txt");
    }

    return 0;
}
