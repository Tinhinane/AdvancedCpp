#include <iostream>
#include <cstring>

class String{
private:
    char* m_Buffer;
    unsigned int m_Size;
public:
    String(const char* s){
        m_Size = std::strlen(s);
        m_Buffer = new char[m_Size+1];//because std::strlen the number of characters in a character array whose first element is pointed to by str up to and not including the first null character
        std::strcpy(m_Buffer, s);//Copies the character string pointed to by src, including the null terminator
    }
    //Copy constructor
    String(const String& other)
        :m_Size(other.m_Size)
    {
        m_Buffer = new char[m_Size+1];
        std::strcpy(m_Buffer, other.m_Buffer);
    }
    //move constructor to enable the resources owned by an rvalue object
    //to be moved into an lvalue without copying
    String(String&& other){
        //assign the class data members from the source object
        //to the object that is being constructed
        m_Size=other.m_Size;
        m_Buffer = new char[m_Size+1];
        std::strcpy(m_Buffer, other.m_Buffer);
        //Assign the data members of the source object to default values
        other.m_Buffer=nullptr;
        other.m_Size=0;
    }
    //Copy assignment operator
    String& operator=(const String& other){
        if (this != &other) { // protect against invalid self-assignment
        //deallocate old memory
        delete[] m_Buffer;
        //assign new memory and copy
        m_Buffer = new char[other.m_Size+1];
        std::strcpy(m_Buffer, other.m_Buffer);
        m_Size = other.m_Size;
        }
        // by convention, always return *this
        return *this;
    }
    //Move assignment operator
    String& operator=(String&& other){
        std::cout << "Move assignment operator" << std::endl;
        if (this != &other)
        {
            //free any resources from the object that is being assigned to
            delete[] m_Buffer;
            //transfer the data members from the source object
            //to the object that is being constructed
            m_Size=other.m_Size;
            m_Buffer = new char[m_Size+1];
            std::strcpy(m_Buffer, other.m_Buffer);
            // Release the data pointer from the source object so that
            // the destructor does not free the memory multiple times.
            other.m_Buffer=nullptr;
            other.m_Size=0;
        }
        return *this;//Return a reference to the current object
    }
    ~String(){
        if(m_Buffer!=nullptr)
            delete[] m_Buffer;
    }
    char& operator[](unsigned int pos){
        return m_Buffer[pos];
    }
    friend std::ostream& operator<<(std::ostream& stream, const String& string);
};

std::ostream& operator<<(std::ostream& stream, const String& string){
 stream << string.m_Buffer;
 return stream;
}

String f(String a){
    return a;
}

int main(){

    String first{"Testing"};
    String second = first;//will call copy constructor (a new object from an existing one)
    second[0]='B';
    std::cout << first << std::endl;
    std::cout << second << std::endl;
    first=second;//will call copy assignment operator (both objects exists already)
    std::cout << first << std::endl;
    std::cout << second << std::endl;
    second[0]='T';
    first[0]='H';
    std::cout << first << std::endl;
    std::cout << second << std::endl;
    std::cout << "trying out move semantics" << std::endl;
    String third = f(first);//will call move constructor
    std::cout << third << std::endl;
}
