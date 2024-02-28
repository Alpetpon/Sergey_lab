#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>
#include "Counter.h"

// Класс MyString представляет строку с подсчетом ссылок.
class MyString {
private:
    char* m_str;         // Указатель на символьный массив (строку)
    Counter* m_counter;  // Указатель на экземпляр Counter для управления подсчетом ссылок

public:
    // Конструкторы и деструктор
    MyString();                              // Конструктор по умолчанию
    MyString(const char* str);               // Конструктор с параметром (создает строку из переданной строки)
    MyString(const MyString& other);         // Конструктор копирования
    ~MyString();                             // Деструктор

    // Методы доступа к данным
    const char* GetString() const;           // Получить строку
    void SetNewString(const char* newStr);   // Установить новую строку

    // Перегруженные операторы
    MyString& operator=(const MyString& other);               // Оператор присваивания
    friend std::ostream& operator<<(std::ostream& os, const MyString& myString);  // Оператор вывода
    MyString operator+(const MyString& other) const;          // Оператор сложения строк
    MyString& operator+=(const MyString& other);              // Оператор добавления строк
    MyString& operator++();                                   // Оператор инкремента
    MyString operator--(int);                                // Оператор декремента

    // Статические методы
    static void print();               // Вывести текущее количество строк и счетчиков
    static void changeCase();          // Изменить регистр всех символов во всех строках
    static void printAlph();           // Вывести все строки в алфавитном порядке
};

#endif
