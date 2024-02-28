#include "List.h"


List::List() : head(nullptr), tail(nullptr), size(0) {}

List::~List() {
    std::cout << "destruct" << std::endl;
    Node* current = head;
    while (current) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = tail = nullptr; // Установка указателей в nullptr для безопасности
    size = 0; // Сброс размера списка
}


void List::addToTail(const Circle& circle) {
    Node* newNode = new Node(circle);
    if (!head) {
        head = tail = newNode;
    }
    else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    size++;
}

void List::addToHead(const Circle& circle) {
    Node* newNode = new Node(circle);
    if (!head) {
        head = tail = newNode;
    }
    else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    size++;
}

void List::remove(const Circle& circle) {
    Node* current = head;
    while (current) {
        if (current->data == circle) {
            removeNode(current);
            return;
        }
        current = current->next;
    }
}

void List::removeAll(const Circle& circle) {
    Node* current = head;
    while (current) {
        Node* next = current->next;
        if (current->data == circle) {
            removeNode(current);
        }
        current = next;
    }
}

void List::removeNode(Node* node) {
    if (node == nullptr) {
        return; 
    }

    if (node == head && node == tail) {
        head = tail = nullptr;
    }
    else if (node == head) {
        head = head->next;
        if (head)
            head->prev = nullptr;
    }
    else if (node == tail) {
        tail = tail->prev;
        if (tail)
            tail->next = nullptr;
    }
    else {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    delete node;
    size--;
}



double List::calculateCircleArea(const Circle& circle) {
    return 3.14 * circle.getRadius() * circle.getRadius();
}

void List::sortList() {
    if (size <= 1) {
        return;
    }

    bool swapped;
    Node* current;
    Node* lastNode = nullptr;

    do {
        swapped = false;
        current = head->next;

        while (current->next != lastNode) {
            if (calculateCircleArea(current->data) > calculateCircleArea(current->next->data)) {
                Circle temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = true;
            }
            current = current->next;
        }
        lastNode = current;
    } while (swapped);
}


std::ostream& operator<<(std::ostream& os, const List& list) {
    Node* current = list.head;
    while (current) {
        os << current->data << " ";
        current = current->next;
    }
    os << std::endl;
    return os;
}

std::istream& operator>>(std::istream& is, List& list) {
    Circle circle;
    while (is >> circle) {
        list.addToTail(circle);
    }
    return is;
}