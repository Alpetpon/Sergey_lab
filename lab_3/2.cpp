#include <iostream>

class Point {
private:
    int x, y;

public:
    Point() : x(0), y(0) {}
    Point(int x, int y) : x(x), y(y) {}

    Point operator+(const Point& other) const {
        Point result;
        result.x = this->x + other.x;
        result.y = this->y + other.y;
        return result;
    }

    friend Point operator-(const Point& left, const Point& right) {
        Point result;
        result.x = left.x - right.x;
        result.y = left.y - right.y;
        return result;
    }

    Point operator+(int scalar) const {
        Point result;
        result.x = this->x + scalar;
        result.y = this->y + scalar;
        return result;
    }

    friend Point operator-(int scalar, const Point& point) {
        Point result;
        result.x = scalar - point.x;
        result.y = scalar - point.y;
        return result;
    }
    
    Point operator-(int scalar) const {
        Point result;
        result.x = this->x - scalar;
        result.y = this->y - scalar;
        return result;
    }



    friend std::ostream& operator<<(std::ostream& os, const Point& point) {
        os << "(" << point.x << ", " << point.y << ")";
        return os;
    }
};

int main() {
    Point pt1(1, 1);
    Point pt2(2, 2);
    Point pt3;

    pt3 = pt1 + 5;
    std::cout << pt3 << std::endl;

    pt3 = pt1 + pt2;
    std::cout << pt3 << std::endl;
    pt3 = pt1 - 5;
    std::cout << pt3 << std::endl;

    pt3 = 2 - pt1;
    std::cout << pt3 << std::endl;

    pt3 = pt1 - pt2;
    std::cout << pt3 << std::endl;

    return 0;
}
