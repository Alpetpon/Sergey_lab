#include <cstring>
#include <iostream>

class MyString {
private:
    char* m_str;

public:
    MyString(const char* str);
    ~MyString();

    const char* GetString() const;
};

MyString::MyString(const char* str) {
    m_str = new char[strlen(str) + 1];
    strcpy(m_str, str);
    std::cout << "Constructor called" << std::endl;
}

MyString::~MyString() {
    delete[] m_str;
    std::cout << "Destructor called" << std::endl;
}

const char* MyString::GetString() const {
    return m_str;
}

int main() {
    MyString str1("It's my string1!");
    
    // Выводим строку с помощью метода GetString()
    std::cout << str1.GetString() << std::endl;

    // Попытка изменения строки не должна компилироваться
    // str1.GetString()[1] = 'W'; // ошибка, так как GetString() возвращает const char*

    const MyString str2("It's my string2!");
    // Выводим строку с помощью метода GetString()
    std::cout << str2.GetString() << std::endl;

    return 0;
}
