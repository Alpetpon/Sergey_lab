#include <iostream>
#include "myString.h"

using namespace std;
int main(int argc, char *argv[]) {
	MyString str1("Hello World!!!");
	MyString str1_2 = str1--;
	
	MyString str2("Hello World!");
	MyString str2_2 = ++str2;
	
	std::cout << str1_2.GetString() << std::endl;
	std::cout << str2_2.GetString() << std::endl;

}