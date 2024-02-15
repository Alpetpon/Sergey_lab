#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>

class MyString {
private:
    char* str;

public:
    MyString(const char* s);
    MyString(const MyString& other);
    ~MyString();
    const char* c_str() const;
    MyString& operator=(const MyString& other);
    MyString operator+(const MyString& other) const; // Добавляем декларацию для оператора +
    friend std::ostream& operator<<(std::ostream& os, const MyString& myStr);
};

#endif // MYSTRING_H
