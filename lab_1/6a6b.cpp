#include <cstring>
#include <iostream>

class MyString {
private:
    char* m_str;

public:
    MyString(const char* str);
    MyString(const MyString& other);
    ~MyString();
    const char* GetString() const;
    void SetNewString(const char* newStr);
    MyString& operator=(const MyString& other);
};

MyString::MyString(const char* str) {
    m_str = new char[strlen(str) + 1];
    strcpy(m_str, str);
    std::cout << "Constructor called" << std::endl;
}

MyString::MyString(const MyString& other) {
    m_str = new char[strlen(other.m_str) + 1];
    strcpy(m_str, other.m_str);
    std::cout << "Copy constructor called" << std::endl;
}

MyString::~MyString() {
    delete[] m_str;
    std::cout << "Destructor called" << std::endl;
}

const char* MyString::GetString() const {
    return m_str;
}

void MyString::SetNewString(const char* newStr) {
    delete[] m_str;
    m_str = new char[strlen(newStr) + 1];
    strcpy(m_str, newStr);
}


int main() {
    {
        MyString str1("The first string!");
        MyString str2 = str1;
    } // Деструкторы вызываются для str1 и str2

    MyString str3("Original String");
    std::cout << "Original String: " << str3.GetString() << std::endl;

    // Изменяем строку с помощью SetNewString
    str3.SetNewString("Updated String");
    std::cout << "Updated String: " << str3.GetString() << std::endl;

    return 0;
}
