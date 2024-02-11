#include <iostream>

#include "point.h"

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
