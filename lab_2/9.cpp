#include "MyString.h"

int main() {
    const char* str1 = "Hello, ";
    const char* str2 = "world!";
    const char* str3 = " How are you?";
    
    MyString result = MyString(str1) + MyString(str2) + MyString(str3);
    
    std::cout << result << std::endl;

    return 0;
}
