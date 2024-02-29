#ifndef CIRCLE_H
#define CIRCLE_H

#include "Point.h"

class Circle {
public:
    Point center;
    double radius;
    Circle(const Point& centerPoint = Point(), double rad = 0);
};

#endif
