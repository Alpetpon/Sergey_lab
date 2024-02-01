#include <iostream>

class Rect {
public:
    int x, y, width, height;

    Rect() : x(0), y(0), width(0), height(0) {
        std::cout << "Default constructor called." << std::endl;
    }

    Rect(int x, int y, int width, int height) : x(x), y(y), width(width), height(height) {
        std::cout << "Parametrized constructor called." << std::endl;
    }

    Rect(const Rect& other) : x(other.x), y(other.y), width(other.width), height(other.height) {
        std::cout << "Copy constructor called." << std::endl;
    }

    void PrintRect() const {
        std::cout << "Rect: x=" << x << ", y=" << y << ", width=" << width << ", height=" << height << std::endl;
    }
    
    // Задание 4б. Передача объектов по ссылке.
    Rect BoundingRect3(const Rect& rect1, const Rect& rect2) {
        // Здесь объекты передаются по ссылке, и конструкторы копирования не вызываются
        int minX = std::min(rect1.x, rect2.x);
        int minY = std::min(rect1.y, rect2.y);
        int maxX = std::max(rect1.x + rect1.width, rect2.x + rect2.width);
        int maxY = std::max(rect1.y + rect1.height, rect2.y + rect2.height);
        
        return Rect(minX, minY, maxX - minX, maxY - minY);
    }

    
};

// Глобальная функция BoundingRect
Rect BoundingRect(Rect rect1, Rect rect2) {
    // Здесь вызывается конструктор копирования для rect1 и rect2
    int minX = std::min(rect1.x, rect2.x);
    int minY = std::min(rect1.y, rect2.y);
    int maxX = std::max(rect1.x + rect1.width, rect2.x + rect2.width);
    int maxY = std::max(rect1.y + rect1.height, rect2.y + rect2.height);

    return Rect(minX, minY, maxX - minX, maxY - minY);
}

// Задание 4а. Передача объектов по ссылке.
Rect BoundingRect2(const Rect& rect1, const Rect& rect2) {
    // Здесь объекты передаются по ссылке, и коныструкторы копирования не вызываются
    int minX = std::min(rect1.x, rect2.x);
    int minY = std::min(rect1.y, rect2.y);
    int maxX = std::max(rect1.x + rect1.width, rect2.x + rect2.width);
    int maxY = std::max(rect1.y + rect1.height, rect2.y + rect2.height);

    return Rect(minX, minY, maxX - minX, maxY - minY);
}

int main() {
    Rect r1(1, 2, 3, 4), r2(5, 6, 7, 8), r3;

    // Глобальная функция BoundingRect
    r3 = BoundingRect(r1, r2);
    r3.PrintRect();
    // Глобальная функция BoundingRect2
    r3 = BoundingRect2(r1, r2);
    r3.PrintRect();
    // функция BoundingRect3 как метод класса
    r3.BoundingRect3(r1, r2);
    r3.PrintRect();

    return 0;
}
