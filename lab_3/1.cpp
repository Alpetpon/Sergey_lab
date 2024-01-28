#include <iostream>

class Point {
private:
    int x;
    int y;

public:
    Point(int x, int y) : x(x), y(y) {}

    // Перегрузка оператора +=
    Point& operator+=(const Point& other) {
        this->x += other.x;
        this->y += other.y;
        return *this;
    }

    // Перегрузка оператора +=
    Point& operator+=(int value) {
        this->x += value;
        this->y += value;
        return *this;
    }

    // Перегрузка оператора -= (в виде глобальной функции)
    friend Point operator-=(Point& pt1, const Point& pt2) {
        pt1.x -= pt2.x;
        pt1.y -= pt2.y;
        return pt1;
    }

    // Перегрузка оператора -= (в виде глобальной функции)
    friend Point operator-=(Point& pt, int value) {
        pt.x -= value;
        pt.y -= value;
        return pt;
    }

    // Дополнительный метод для вывода координат точки
    void printCoordinates() const {
        std::cout << "X: " << x << ", Y: " << y << std::endl;
    }
};

int main() {
    {
        Point pt1(1, 1);
        Point pt2(2, 2);
        pt2 += pt1;
        pt2.printCoordinates();
        pt2 += 1;
        pt2.printCoordinates();

        Point pt3(3, 3);
        pt2 += pt1 += pt3;
        pt2.printCoordinates();
    }

    {
        Point pt1(1, 1);
        Point pt2(2, 2);
        pt2 -= pt1;
        pt2.printCoordinates();

        pt2 -= 1;
        pt2.printCoordinates();

        Point pt3(3, 3);
        pt2 -= pt1 -= pt3;
        pt2.printCoordinates();
    }

    return 0;
}
 