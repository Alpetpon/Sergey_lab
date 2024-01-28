#include <iostream>
#include "myString.h"

using namespace std;
int main(int argc, char *argv[]) {
	MyString s1("QWERTY"), s2("AAA"), s3, s4("BBB");
	s3 = s1 + s2;
	s4 += s1;
	
	std::cout << s3.GetString() << std::endl;
	std::cout << s4.GetString() << std::endl;

}