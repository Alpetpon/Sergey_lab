#include <iostream>
#include <string>

class MyString {
public:
    std::string str;

    // Конструктор класса MyString
    MyString(const std::string& s) : str(s) {}
};

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
        std::cout << "arPtr[" << i << "]: " << arPtr[i]->str << std::endl;
    }

    // Новый размер массива 
    const int M = 5;

    // Создание нового массива указателей с новым размером
    MyString** arPtrNew = new MyString*[M];
    for (int i = 0; i < M; ++i) {
        arPtrNew[i] = i < N ? arPtr[i] : new MyString("String" + std::to_string(i + 1));
    }

    // Печать строк-членов нового массива указателей
    for (int i = 0; i < M; ++i) {
        std::cout << "arPtrNew[" << i << "]: " << arPtrNew[i]->str << std::endl;
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
