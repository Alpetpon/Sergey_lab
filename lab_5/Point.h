#ifndef POINT_H
#define POINT_H

class Point {
private:
    int x;
    int y;

public:
    Point(int x, int y) : x(x), y(y) {}

    int getX() const { return x; }
    int getY() const { return y; }
};

#endif