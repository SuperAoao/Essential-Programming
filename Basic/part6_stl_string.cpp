#include <iostream>
#include <string>

class MyString
{
public:
    MyString();
    MyString(const char* s);
    MyString(const MyString& other);
    // Now consider the case where we are instead moving an object. 
    // A move operation transfers ownership of a given resource from the source to the destination object. 
    // If the move operation is interrupted by an exception after the transfer of ownership occurs, then our source object will be left in a modified state.
    // This isn’t a problem if the source object is a temporary object and going to be discarded after the move anyway -- but for non-temporary objects, we’ve now damaged the source object.
    // To comply with the strong exception guarantee, we’d need to move the resource back to the source object, but if the move failed the first time, there’s no guarantee the move back will succeed either.
    MyString(MyString&& other) noexcept;
    ~MyString();

    size_t length();
    size_t size();
    
    void append(const char* s);
    void append(const MyString& str);
    MyString& operator=(const char*s);
    MyString& operator=(const MyString& str);
    
 
    friend std::ostream& operator<<(std::ostream& os, const MyString& str);
    // operator <<
private:
    char* m_buffer;
    size_t m_len;
};

MyString::MyString() : m_buffer(nullptr), m_len(0) 
{

};

MyString::MyString(const char* s)
{
    m_len = std::strlen(s);
    m_buffer = new char[m_len+1];
    std::strcpy(m_buffer, s);
};

MyString::MyString(const MyString& other)
{
    m_len = other.m_len;
    m_buffer = new char[m_len+1];
    std::strcpy(m_buffer, other.m_buffer);
};

MyString::MyString(MyString&& other) noexcept
{
    m_len = other.m_len;
    m_buffer = other.m_buffer;
    other.m_buffer = nullptr;
    other.m_len = 0;
};

MyString::~MyString()
{
    delete []m_buffer;
}

void MyString::append(const char* s)
{
    m_len += std::strlen(s);
    char* new_buffer = new char[m_len+1];
    std::strcpy(new_buffer, m_buffer);
    std::strcat(new_buffer, s);
    delete []m_buffer;
    m_buffer = new_buffer;
}

size_t MyString::length()
{
    return m_len;
}

size_t MyString::size()
{
    return m_len;
}

std::ostream& operator<<(std::ostream& os, const MyString& str)
{
    os << str.m_buffer;
    return os;
}
int main()
{
    std::string s1("Hello");
    s1 + " World";
    std::string s2 = s1 + " World";
    std::cout << s1 + " World" << std::endl;
    std::cout << s1 << std::endl;
    std::cout << s2 << std::endl;
    std::string s3("s3");
    std::string s4 = s1 + s2 + s3;
    std::cout << s4 << std::endl;

    MyString mys1("Ao Str");
    std::cout << mys1 << std::endl;
    MyString mys2(mys1);
    std::cout << mys2 << std::endl;
    MyString mys3(std::move(mys2));  
    std::cout << mys3 << std::endl;
    mys3.append("123");
    std::cout << mys3 << std::endl;
    return 0;
}