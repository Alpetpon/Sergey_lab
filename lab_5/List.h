#ifndef LIST_H
#define LIST_H

#include "Circle.h"
#include "Node.h"
#include <iostream>


class List {
private:
    Node* head; // Указатель на начало списка
    Node* tail; // Указатель на конец списка
    size_t size; // Размер списка

    Node* partition(Node* start, Node* end);

    // Приватный метод для удаления узла из списка
    void removeNode(Node* node);

public:
    // Конструктор по умолчанию
    List();

    // Деструктор
    ~List();

    // Метод для добавления элемента в конец списка
    void addToTail(const Circle& circle);

    // Метод для добавления элемента в начало списка
    void addToHead(const Circle& circle);

    // Метод для удаления первого вхождения элемента из списка
    void remove(const Circle& circle);

    // Метод для удаления всех вхождений элемента из списка
    void removeAll(const Circle& circle);

    void quickSort(Node* start, Node* end);
    
    double calculateCircleArea(const Circle& circle);

    // Метод для сортировки списка
    void sortList();

    // Перегрузка оператора << для вывода списка в поток
    friend std::ostream& operator<<(std::ostream& os, const List& list);

    // Перегрузка оператора >> для чтения списка из потока
    friend std::istream& operator>>(std::istream& is, List& list);
};

#endif
