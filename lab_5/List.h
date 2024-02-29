#ifndef LIST_H
#define LIST_H

#include "Node.h"
#include <cstddef> // Для size_t
#include <iostream>
#include <fstream> // Для ifstream

class List {
private:
    Node Head;     // фиктивный элемент, который является признаком начала списка
    Node Tail;     // фиктивный элемент, который является признаком конца списка
    size_t m_size; // количество элементов

public:
    List();
    ~List();

    // Конструктор копирования
    List(const List& other);

    // Оператор присваивания
    List& operator=(const List& other);

    // Конструктор перемещения
    List(List&& other) noexcept;

    // Оператор перемещения
    List& operator=(List&& other) noexcept;

    void addToTail(const Circle& circle);
    bool remove(const Circle& circle);
    size_t removeAll(const Circle& circle);
    void clear();
    void addToHead(const Circle& circle);
    void sortList();

    // перегрузка оператора вывода для класса List
    friend std::ostream& operator<<(std::ostream& os, const List& list);
    friend std::ifstream& operator>>(std::ifstream& ifs, List& list);
};

#endif
