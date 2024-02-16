#include "Circle.h"

Circle::Circle(const Point& center, int radius) : center(center), radius(radius) {}


std::ostream& operator<<(std::ostream& os, const Circle& circle) {
    os << "Circle(" << circle.center.getX() << ", " << circle.center.getY() << ", " << circle.radius << ")";
    return os;
}

bool Circle::operator==(const Circle& other) const {
    return center.getX() == other.center.getX() && center.getY() == other.center.getY() && radius == other.radius;
}

std::istream& operator>>(std::istream& is, Circle& circle) {
    int x, y, radius;
    is >> x >> y >> radius;
    circle = Circle(Point(x, y), radius);
    return is;
}

int Circle::getRadius() const {
    return radius;
}
