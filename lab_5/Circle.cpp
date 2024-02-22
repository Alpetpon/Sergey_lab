#include "Circle.h"

Circle::Circle(const Point& center, int radius) : center(center), radius(radius) {} // Определение конструктора класса Circle, инициализирующего центр и радиус круга

std::ostream& operator<<(std::ostream& os, const Circle& circle) {
    os << "Circle(" << circle.center.getX() << ", " << circle.center.getY() << ", " << circle.radius << ")"; // Вывод информации о круге в формате "Circle(x, y, radius)"
    return os; // Возвращаем поток вывода
}

bool Circle::operator==(const Circle& other) const {
    return center.getX() == other.center.getX() && center.getY() == other.center.getY() && radius == other.radius; // Проверка на равенство координат центров и радиусов двух кругов
}

std::istream& operator>>(std::istream& is, Circle& circle) {
    int x, y, radius;
    is >> x >> y >> radius; // Ввод координат центра и радиуса круга
    circle = Circle(Point(x, y), radius); // Создание временного объекта Circle и его присваивание объекту circle
    return is; // Возвращаем поток ввода
}

int Circle::getRadius() const {
    return radius; // Возвращаем значение радиуса круга
}
