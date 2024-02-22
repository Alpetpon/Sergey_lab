#ifndef CIRCLE_H
#define CIRCLE_H

#include "Point.h" 
#include <iostream>

class Circle {
private:
    Point center; // Центр круга, представленный объектом Point
    int radius;   // Радиус круга

public:
    // Конструктор для инициализации объекта Circle с заданным центром и радиусом
    Circle(const Point& center, int radius);

    // Перегрузка оператора << для удобного вывода объектов Circle
    friend std::ostream& operator<<(std::ostream& os, const Circle& circle);

    // Перегрузка оператора == для сравнения объектов Circle на равенство
    bool operator==(const Circle& other) const;

    // Перегрузка оператора >> для удобного ввода объектов Circle
    friend std::istream& operator>>(std::istream& is, Circle& circle);

    // Функция-геттер для получения радиуса круга
    int getRadius() const;
};

#endif
