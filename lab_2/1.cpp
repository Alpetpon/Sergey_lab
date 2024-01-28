#include <iostream>
#include <string>

class MyString {
public:
    std::string str;
    MyString() : str("") {}

    MyString(const std::string& s) : str(s) {}
};

int main() {
    // Исходный размер массива
    const int N = 3;

    // Инициализация массива объектов MyString
    MyString* str1 = new MyString[N]{MyString("String1"), MyString("String2"), MyString("String3")};

    // Печать строк-членов класса
    for (int i = 0; i < N; ++i) {
        std::cout << "str1[" << i << "]: " << str1[i].str << std::endl;
    }

    // Новый размер массива 
    const int M = 5;

    // Изменение размера массива без явного создания нового
    MyString* temp = new MyString[M];
    for (int i = 0; i < N; ++i) {
        temp[i] = str1[i];
    }
    for (int i = N; i < M; ++i) {
        temp[i] = MyString("String" + std::to_string(i + 1));
    }

    // Освобождение памяти старого массива и присвоение нового
    delete[] str1;
    str1 = temp;

    // Печать строк-членов обновленного массива
    for (int i = 0; i < M; ++i) {
        std::cout << "str1[" << i << "]: " << str1[i].str << std::endl;
    }

    // Освобождение памяти нового массива
    delete[] str1;

    return 0;
}
