#include "color.h"

int main() {
    // Создание объектов иерархии
    Rect rect(RED);
    Circle circle(GREEN);
    // Вывод информации о фигурах
    rect.printInfo();
    std::cout << std::endl;
    circle.printInfo();

    return 0;
}
