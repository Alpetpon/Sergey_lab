#include <iostream>

#include "point.h"

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
 