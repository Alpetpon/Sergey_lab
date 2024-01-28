#include <iostream>

class Point {
private:
    int x, y;

public:
    Point() : x(0), y(0) {}
    Point(int x, int y) : x(x), y(y) {}

    // Перегрузка унарного оператора +
    Point operator+() const {
        return *this;
    }

    // Перегрузка унарного оператора -
    Point operator-() const {
        Point result;
        result.x = -this->x;
        result.y = -this->y;
        return result;
    }

    // Перегрузка оператора вывода
    friend std::ostream& operator<<(std::ostream& os, const Point& point) {
        os << "x=" << point.x << ", y=" << point.y;
        return os;
    }
};

int main() {
    Point pt(10, 20);
    std::cout << pt << std::endl;

    return 0;
}
