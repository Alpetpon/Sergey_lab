#include <iostream>

class Rect {
public:
    int m_left;
    int m_right;
    int m_top;
    int m_bottom;

public:
    // 1a. Конструктор с параметрами для инициализации переменных класса
    Rect(int left, int right, int top, int bottom)
        : m_left(left), m_right(right), m_top(top), m_bottom(bottom) {
        // Здесь можно добавить проверки на "ненормализованный" прямоугольник
        // и выполнить коррекцию, если необходимо
        Normalize();
    }

    // 1б. Конструктор без параметров с инициализацией переменных класса, например, нулем
    Rect()
        : m_left(0), m_right(0), m_top(0), m_bottom(0) {
    }

    // 1в. Метод InflateRect(), увеличивающий размеры прямоугольника на заданные приращения
    void InflateRect(int xIncrement, int yIncrement) {
        m_left -= xIncrement;
        m_right += xIncrement;
        m_top -= yIncrement;
        m_bottom += yIncrement;
        // Здесь также можно добавить проверки на "ненормализованный" прямоугольник и коррекцию
        Normalize();
    }

    // Метод для проверки и коррекции "ненормализованного" прямоугольника
    void Normalize() {
        if (m_left > m_right) std::swap(m_left, m_right);
        if (m_top > m_bottom) std::swap(m_top, m_bottom);
    }

    // Дополнительные методы и функции класса могут быть добавлены по необходимости
};

int main() {
    // 1. Создание экземпляра класса Rect с использованием конструктора без параметров
    Rect rect1;
    std::cout << "Rect1: " << rect1.m_left << ", " << rect1.m_right << ", " << rect1.m_top << ", " << rect1.m_bottom << std::endl;

    // 1а. Создание экземпляра класса Rect с использованием конструктора с параметрами
    Rect rect2(4, 2, 3, 1);
    std::cout << "Rect2: " << rect2.m_left << ", " << rect2.m_right << ", " << rect2.m_top << ", " << rect2.m_bottom << std::endl;

    // 1в. Вызов метода InflateRect() для увеличения размеров прямоугольника
    rect2.InflateRect(1, 1);
    std::cout << "Rect2 after InflateRect: " << rect2.m_left << ", " << rect2.m_right << ", " << rect2.m_top << ", " << rect2.m_bottom << std::endl;

    return 0;
}
