#ifndef LIST_H
#define LIST_H

#include <cstddef> // Для size_t
#include <iostream>
#include <fstream> // Для ifstream

// Класс для представления точки
class Point {
public:
    double x;
    double y;
    Point(double xCoord = 0, double yCoord = 0);
};

// Класс для представления круга
class Circle {
public:
    Point center;
    double radius;
    Circle(const Point& centerPoint = Point(), double rad = 0);
};

// Класс для представления узла списка
class Node {
public:
    Node* pPrev; // указатель на предыдущий элемент
    Node* pNext; // указатель на следующий элемент
    Circle m_Data;

    Node();
    Node(const Circle& circle, Node* prevNode = nullptr, Node* nextNode = nullptr);
    ~Node();
};

// Класс для представления списка
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

#endif // LIST_H
