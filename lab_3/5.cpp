#include "myString.h"
#include <iostream>

int main() {
    MyString s1("AAA"), s2;


    s2 = s1;
    std::cout << "s2 after assignment: " << s2.GetString() << std::endl;

    s1 = "CCC";
    std::cout << "s1 after assignment: " << s1.GetString() << std::endl;


    s2 = MyString("tmp");
    std::cout << "s2 after assignment with temporary: " << s2.GetString() << std::endl;


    s1 = s1;
    return 0;
}
