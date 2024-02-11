#include "color.h"

int main() {
    Rect rect(Color::RED, 10, 20, 5, 5); // Создаем прямоугольник с заданными параметрами
    Circle circle(rect); // Создаем круг, используя прямоугольник

    rect.printInfo(); // Вывод информации о прямоугольнике
    circle.printInfo(); // Вывод информации о круге, созданном из прямоугольника

    return 0;
}
ы