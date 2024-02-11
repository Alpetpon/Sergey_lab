#include "color.h"

int main() {
    Rect r(Color::GREEN, 10, 20, 5, 5); // Создаем прямоугольник с зеленым цветом и заданными параметрами
    
    Shape* ar[] = {&r, new Rect(r), new Circle(r), new Circle(r) }; // Создаем массив указателей на Shape

    // Выводим информацию о том, где находятся объекты до преобразования
    for (int i = 0; i < 4; ++i) {
        ar[i]->WhereAmIVirtual();
    }

    // Преобразуем каждый объект круга и выводим информацию о новом местоположении
    for (int i = 1; i < 4; ++i) {
        Circle* circlePtr = dynamic_cast<Circle*>(ar[i]); // Приводим указатель к типу Circle
        if (circlePtr) { // Проверяем, удалось ли преобразование
            *circlePtr = Circle(*dynamic_cast<Rect*>(ar[0])); // Конструируем круг из прямоугольника
            ar[i]->WhereAmIVirtual(); // Выводим информацию о новом местоположении
        }
    }

    // Удаляем динамически созданные объекты, чтобы избежать утечек памяти
    for (int i = 1; i < 4; ++i) {
        delete ar[i];
    }

    return 0;
}
