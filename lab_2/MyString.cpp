#include "MyString.h"
#include <cstring>

MyString::MyString(const char* s) {
    if (s != nullptr) {
        str = new char[std::strlen(s) + 1];
        std::strcpy(str, s);
    } else {
        str = nullptr;
    }
}

MyString::MyString(const MyString& other) {
    if (other.str != nullptr) {
        str = new char[std::strlen(other.str) + 1];
        std::strcpy(str, other.str);
    } else {
        str = nullptr;
    }
}

MyString::~MyString() {
    delete[] str;
}

const char* MyString::c_str() const {
    return str;
}

MyString& MyString::operator=(const MyString& other) {
    if (this != &other) {
        delete[] str;

        if (other.str != nullptr) {
            str = new char[std::strlen(other.str) + 1];
            std::strcpy(str, other.str);
        } else {
            str = nullptr;
        }
    }

    return *this;
}

MyString MyString::operator+(const MyString& other) const {
    if (other.str == nullptr) return *this;
    if (str == nullptr) return other;

    char* resultStr = new char[std::strlen(str) + std::strlen(other.str) + 1];
    std::strcpy(resultStr, str);
    std::strcat(resultStr, other.str);

    MyString result(resultStr);
    delete[] resultStr;

    return result;
}

std::ostream& operator<<(std::ostream& os, const MyString& myStr) {
    if (myStr.str != nullptr)
        os << myStr.str;
    return os;
}
