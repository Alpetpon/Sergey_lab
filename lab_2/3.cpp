#include <iostream>

// Перечисление для цветов
enum Color { RED, GREEN, BLUE };

// Базовый класс Shape
class Shape {
protected:
    Color color;  // Цвет фигуры

public:
    // Конструктор базового класса с параметром-цветом
    Shape(Color c) : color(c) {
        std::cout << "Constructing Shape with color" << std::endl;
    }

    // Виртуальный деструктор
    virtual ~Shape() {
        std::cout << "Destructing Shape" << std::endl;
    }

    // Виртуальная функция для вывода информации о фигуре
    virtual void printInfo() const {
        std::cout << "Shape of color: " << color << std::endl;
    }
};

// Производный класс Rect
class Rect : public Shape {
public:
    // Конструктор производного класса с параметром-цветом
    Rect(Color c) : Shape(c) {
        std::cout << "Constructing Rect" << std::endl;
    }

    // Переопределение виртуальной функции базового класса
    void printInfo() const override {
        std::cout << "Rectangle of color: " << color << std::endl;
    }

    // Деструктор производного класса
    ~Rect() {
        std::cout << "Destructing Rect" << std::endl;
    }
};

// Производный класс Circle
class Circle : public Shape {
public:
    // Конструктор производного класса с параметром-цветом
    Circle(Color c) : Shape(c) {
        std::cout << "Constructing Circle" << std::endl;
    }

    // Переопределение виртуальной функции базового класса
    void printInfo() const override {
        std::cout << "Circle of color: " << color << std::endl;
    }

    // Деструктор производного класса
    ~Circle() {
        std::cout << "Destructing Circle" << std::endl;
    }
};

int main() {
    // Создание объектов иерархии
    Rect rect(RED);
    Circle circle(GREEN);
    // Вывод информации о фигурах
    rect.printInfo();
    std::cout << std::endl;
    circle.printInfo();

    return 0;
}
