#ifndef BASE_H
#define BASE_H

#include "Pair.h"

class Base {
private:
    Pair* pBase; // Указатель на массив пар (сотрудников)
    size_t count; // Количество элементов в базе
    size_t capacity; // Емкость базы

public:
    // Конструктор по умолчанию
    Base();
    
    // Деструктор
    ~Base();
    
    // Конструктор копирования
    Base(const Base& other);
    
    // Оператор присваивания
    Base& operator=(const Base& other);
    
    // Конструктор перемещения
    Base(Base&& other);
    
    // Оператор перемещения
    Base& operator=(Base&& other);
    
    // Оператор индексирования для доступа к данным сотрудника по ключу
    MyData& operator[](const char* key);
    
    // Метод удаления пары сотрудника из базы по ключу
    int deletePair(const char* key);
    
    // Метод для сортировки базы данных
    void sort();
    
    // Перегруженный оператор вывода для класса Base
    friend std::ostream& operator<<(std::ostream& os, const Base& bd);
};

#endif
