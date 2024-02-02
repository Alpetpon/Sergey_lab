#include <cstring>
#include <iostream>

class MyString {
private:
    char* m_str;

public:
    MyString();
    MyString(const char* str);
    ~MyString();
    const char* GetString() const;

    MyString(const MyString& other);
    void SetNewString(const char* newStr);
    MyString& operator=(const MyString& other);
};

MyString::MyString() : m_str(nullptr) {
    std::cout << "Default constructor called" << std::endl;
}

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

MyString::MyString(const MyString& other) {
    m_str = new char[strlen(other.m_str) + 1];
    strcpy(m_str, other.m_str);
    std::cout << "Copy constructor called" << std::endl;
}

void MyString::SetNewString(const char* newStr) {
    delete[] m_str;
    m_str = new char[strlen(newStr) + 1];
    strcpy(m_str, newStr);
}

MyString& MyString::operator=(const MyString& other) {
    if (this != &other) {
        delete[] m_str;
        m_str = new char[strlen(other.m_str) + 1];
        strcpy(m_str, other.m_str);
    }
    return *this;
}

int main() {
    // Исходный размер массива
    const int N = 3;

    // Инициализация статического массива объектов MyString
    MyString str1[N] = {MyString("String1"), MyString("String2"), MyString("String3")};

    // Печать строк-членов класса
    for (int i = 0; i < N; ++i) {
        std::cout << "str1[" << i << "]: " << str1[i].GetString() << std::endl;
    }

    // Новый размер массива
    const int M = 5;

    // Изменение размера массива без явного создания нового
    MyString temp[M];
    for (int i = 0; i < N; ++i) {
        temp[i] = str1[i];
    }
    for (int i = N; i < M; ++i) {
        temp[i] = MyString(("String" + std::to_string(i + 1)).c_str());
    }

    // Печать строк-членов обновленного массива
    for (int i = 0; i < M; ++i) {
        std::cout << "temp[" << i << "]: " << temp[i].GetString() << std::endl;
    }

    return 0;
}
