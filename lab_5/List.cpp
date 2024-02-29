#include "List.h"

// Определения методов класса Point
Point::Point(double xCoord, double yCoord) : x(xCoord), y(yCoord) {}

// Определения методов класса Circle
Circle::Circle(const Point& centerPoint, double rad) : center(centerPoint), radius(rad) {}

// Определения методов класса Node
Node::Node() : pPrev(nullptr), pNext(nullptr) {}

Node::Node(const Circle& circle, Node* prevNode, Node* nextNode)
    : m_Data(circle), pPrev(prevNode), pNext(nextNode) {}

Node::~Node() {}

// Определения методов класса List
List::List() : m_size(0) {
    Head.pNext = &Tail;
    Tail.pPrev = &Head;
}

List::~List() {
    clear();
}

void List::addToTail(const Circle& circle) {
    Node* newNode = new Node(circle, Tail.pPrev, &Tail);
    Tail.pPrev->pNext = newNode;
    Tail.pPrev = newNode;
    ++m_size;
}

bool List::remove(const Circle& circle) {
    Node* current = Head.pNext;
    while (current != &Tail) {
        if (current->m_Data.center.x == circle.center.x &&
            current->m_Data.center.y == circle.center.y &&
            current->m_Data.radius == circle.radius) {
            current->pPrev->pNext = current->pNext;
            current->pNext->pPrev = current->pPrev;
            delete current;
            --m_size;
            return true;
        }
        current = current->pNext;
    }
    return false;
}

size_t List::removeAll(const Circle& circle) {
    size_t count = 0;
    Node* current = Head.pNext;
    while (current != &Tail) {
        if (current->m_Data.center.x == circle.center.x &&
            current->m_Data.center.y == circle.center.y &&
            current->m_Data.radius == circle.radius) {
            Node* temp = current;
            current = current->pNext;
            temp->pPrev->pNext = temp->pNext;
            temp->pNext->pPrev = temp->pPrev;
            delete temp;
            ++count;
            --m_size;
        }
        else {
            current = current->pNext;
        }
    }
    return count;
}

void List::clear() {
    Node* current = Head.pNext;
    while (current != &Tail) {
        Node* temp = current;
        current = current->pNext;
        delete temp;
    }
    Head.pNext = &Tail;
    Tail.pPrev = &Head;
    m_size = 0;
}

void List::addToHead(const Circle& circle) {
    Node* newNode = new Node(circle, &Head, Head.pNext);
    Head.pNext->pPrev = newNode;
    Head.pNext = newNode;
    ++m_size;
}

void List::sortList() {
    for (Node* i = Head.pNext; i != &Tail; i = i->pNext) {
        for (Node* j = i->pNext; j != &Tail; j = j->pNext) {
            if (i->m_Data.radius > j->m_Data.radius) {
                // Обмен значениями
                Circle temp = i->m_Data;
                i->m_Data = j->m_Data;
                j->m_Data = temp;
            }
        }
    }
}

std::ostream& operator<<(std::ostream& os, const List& list) {
    Node* current = list.Head.pNext;
    while (current != &list.Tail) {
        os << "Center: (" << current->m_Data.center.x << ", " << current->m_Data.center.y << "), Radius: " << current->m_Data.radius << std::endl;
        current = current->pNext;
    }
    return os;
}

std::ifstream& operator>>(std::ifstream& ifs, List& list) {
    list.clear();

    double x, y, radius;
    while (ifs >> x >> y >> radius) {
        Point center(x, y);
        Circle circle(center, radius);
        list.addToTail(circle);
    }

    return ifs;
}

// Конструктор копирования
List::List(const List& other) : m_size(0) {
    Head.pNext = &Tail;
    Tail.pPrev = &Head;
    Node* current = other.Head.pNext;
    while (current != &other.Tail) {
        addToTail(current->m_Data);
        current = current->pNext;
    }
}


//Оператор присваивания
List & List::operator=(const List & other) {
    if (this != &other) {
        clear(); // Очищаем текущий список

        Node* current = other.Head.pNext;
        while (current != &other.Tail) {
            addToTail(current->m_Data);
            current = current->pNext;
        }
    }
    return *this;
}

// Оператор перемещения
List::List(List&& other) noexcept : m_size(0) {
    // Переносим указатели на голову и хвост
    Head.pNext = other.Head.pNext;
    Tail.pPrev = other.Tail.pPrev;

    // Переносим размер
    m_size = other.m_size;

    // Устанавливаем указатели в другом списке в состояние по умолчанию
    other.Head.pNext = &other.Tail;
    other.Tail.pPrev = &other.Head;
    other.m_size = 0;
}

// Оператор перемещения
List& List::operator=(List&& other) noexcept {
    if (this != &other) {
        // Очищаем текущий список
        clear();

        // Переносим указатели на голову и хвост
        Head.pNext = other.Head.pNext;
        Tail.pPrev = other.Tail.pPrev;

        // Переносим размер
        m_size = other.m_size;

        // Устанавливаем указатели в другом списке в состояние по умолчанию
        other.Head.pNext = &other.Tail;
        other.Tail.pPrev = &other.Head;
        other.m_size = 0;
    }
    return *this;
}