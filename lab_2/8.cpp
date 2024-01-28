#include <iostream>

class Shape {
public:
    virtual ~Shape() {}

    // Чисто виртуальная функция
    virtual void Inflate(int factor) = 0;
};

class Rect : public Shape {
public:
    // Реализация виртуальной функции для класса Rect
    void Inflate(int factor) override {
        std::cout << "Inflating Rect by factor: " << factor << std::endl;
    }
};

class Circle : public Shape {
public:
    // Реализация виртуальной функции для класса Circle
    void Inflate(int factor) override {
        std::cout << "Inflating Circle by factor: " << factor << std::endl;
        
    }
};

int main() {
    Rect r;
    Shape* p = &r;
    p->Inflate(5);  // Вызовется метод Inflate() класса Rect

    Circle c;
    p = &c;
    p->Inflate(5);  // Вызовется метод Inflate() класса Circle

    return 0;
}
