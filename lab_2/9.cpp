#include <iostream>
#include <cstring>

class MyString {
private:
    char* str;

public:
    MyString(const char* s) {
        if (s != nullptr) {
            str = new char[std::strlen(s) + 1];
            std::strcpy(str, s);
        } else {
            str = nullptr;
        }
    }

    MyString(const MyString& other) {
        if (other.str != nullptr) {
            str = new char[std::strlen(other.str) + 1];
            std::strcpy(str, other.str);
        } else {
            str = nullptr;
        }
    }

    ~MyString() {
        delete[] str;
    }

    const char* c_str() const {
        return str;
    }

    MyString& operator=(const MyString& other) {
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

    MyString operator+(const MyString& other) const {
        char* resultStr = new char[std::strlen(str) + std::strlen(other.str) + 1];
        std::strcpy(resultStr, str);
        std::strcat(resultStr, other.str);

        MyString result(resultStr);
        delete[] resultStr;

        return result;
    }

    friend std::ostream& operator<<(std::ostream& os, const MyString& myStr) {
        os << myStr.str;
        return os;
    }
};

int main() {
    const char* str1 = "Hello, ";
    const char* str2 = "world!";
    const char* str3 = " How are you?";
    
    MyString result = MyString(str1) + MyString(str2) + MyString(str3);
    
    std::cout << result << std::endl;

    return 0;
}
