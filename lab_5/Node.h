#ifndef NODE_H
#define NODE_H

#include "Circle.h" 

struct Node {
    Circle data; // Данные узла
    Node* next; // Указатель на следующий узел
    Node* prev; // Указатель на предыдущий узел

    // Конструктор узла
    Node(const Circle& circle);
};

#endif
