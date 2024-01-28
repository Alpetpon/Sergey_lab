#include <iostream>

class Point {
private:
    int x, y;

public:
    Point() : x(0), y(0) {}
    Point(int x, int y) : x(x), y(y) {}

    // Перегрузка унарного оператора +
    Point operator+() const {
        // Возвращаем текущий объект, т.к. оператор + не меняет значения
        return *this;
    }

    // Перегрузка унарного оператора -
    Point operator-() const {
        Point result;
        result.x = -this->x;
        result.y = -this->y;
        return result;
    }

    // Перегрузка оператора вывода для удобного вывода точек
    friend std::ostream& operator<<(std::ostream& os, const Point& point) {
        os << "(" << point.x << ", " << point.y << ")";
        return os;
    }
};

int main() {
    Point pt1(1, 1);
    Point pt3;

    // Перегрузка унарного оператора - с помощью глобальной функции
    pt3 = -pt1;
    std::cout << pt3 << std::endl;

    // Перегрузка унарного оператора + с помощью метода класса
    pt3 = +pt1;
    std::cout << pt3 << std::endl;

    return 0;
}
