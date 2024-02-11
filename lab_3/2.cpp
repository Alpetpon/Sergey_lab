#include <iostream>

#include "point.h"

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
