#include <cstring>
#include <iostream>

class MyString {
private:
    char* m_str;

public:
    MyString(const char* str);
    ~MyString();
    const char* GetString() const;

    MyString(const MyString& other);
    void SetNewString(const char* newStr);
    MyString& operator=(const MyString& other);

    const char* GetStr() const;
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

const char* MyString::GetStr() const {
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
    // Исходный размер массива указателей
    const int N = 3;

    // Инициализация массива указателей на объекты MyString
    MyString* arPtr[N];
    arPtr[0] = new MyString("String1");
    arPtr[1] = new MyString("String2");
    arPtr[2] = new MyString("String3");

    // Печать строк-членов класса через указатели
    for (int i = 0; i < N; ++i) {
        std::cout << "arPtr[" << i << "]: " << arPtr[i]->GetStr() << std::endl;
    }

    // Новый размер массива 
    const int M = 5;

    // Создание нового массива указателей с новым размером
    MyString** arPtrNew = new MyString*[M];
    for (int i = 0; i < M; ++i) {
        arPtrNew[i] = i < N ? arPtr[i] : new MyString(("String" + std::to_string(i + 1)).c_str());
    }

    // Печать строк-членов нового массива указателей
    for (int i = 0; i < M; ++i) {
        std::cout << "arPtrNew[" << i << "]: " << arPtrNew[i]->GetStr() << std::endl;
    }

    // Освобождение памяти для каждого созданного объекта старого массива
    for (int i = 0; i < N; ++i) {
        delete arPtr[i];
    }

    // Освобождение памяти для каждого созданного объекта нового массива 
    for (int i = N; i < M; ++i) {
        delete arPtrNew[i];
    }

    // Освобождение памяти для нового массива указателей
    delete[] arPtrNew;

    return 0;
}
