
#include <iostream>

class Rect {
private:
    int m_left;
    int m_right;
    int m_top;
    int m_bottom;

public:
    Rect();  // Конструктор без параметров
    Rect(int left, int right, int top, int bottom);  // Конструктор с параметрами
    Rect(const Rect& other);  // Конструктор копирования
    void InflateRect(int xIncrement, int yIncrement);  // Метод увеличения размеров прямоугольника
    void InflateRect(int xIncrement, int yIncrement, int xIncrement2, int yIncrement2);  // Перегруженный метод для увеличения размеров прямоугольника
    void Normalize();  // Метод для проверки и коррекции "ненормализованного" прямоугольника
    void PrintRect() const;  // Метод для вывода прямоугольника в консоль
    void SetAll(int left, int right, int top, int bottom);  // Метод для установки значений private-переменных
    void GetAll(int& left, int& right, int& top, int& bottom) const;  // Метод для получения значений private-переменных
};

Rect::Rect()
    : m_left(0), m_right(0), m_top(0), m_bottom(0) {
}

Rect::Rect(int left, int right, int top, int bottom)
    : m_left(left), m_right(right), m_top(top), m_bottom(bottom) {
    Normalize();
}

Rect::Rect(const Rect& other)
    : m_left(other.m_left), m_right(other.m_right), m_top(other.m_top), m_bottom(other.m_bottom) {
}

void Rect::InflateRect(int xIncrement, int yIncrement) {
    m_left -= xIncrement;
    m_right += xIncrement;
    m_top -= yIncrement;
    m_bottom += yIncrement;
    Normalize();
}

void Rect::InflateRect(int xIncrement, int yIncrement, int xIncrement2, int yIncrement2) {
    m_left -= xIncrement;
    m_right += xIncrement2;
    m_top -= yIncrement;
    m_bottom += yIncrement2;
    Normalize();
}

void Rect::Normalize() {
    if (m_left > m_right) std::swap(m_left, m_right);
    if (m_top > m_bottom) std::swap(m_top, m_bottom);
}

void Rect::PrintRect() const {
    std::cout << "Rect: " << m_left << ", " << m_right << ", " << m_top << ", " << m_bottom << std::endl;
}

void Rect::SetAll(int left, int right, int top, int bottom) {
    m_left = left;
    m_right = right;
    m_top = top;
    m_bottom = bottom;
    Normalize();
}

void Rect::GetAll(int& left, int& right, int& top, int& bottom) const {
    left = m_left;
    right = m_right;
    top = m_top;
    bottom = m_bottom;
}

int main() {
    // 3. Спецификаторы доступа. Инкапсуляция.
    Rect r;
    // Раскомментируйте следующую строку. Объясните ошибку компилятора

    //int tmp = r.m_left;
    /*
    Данная строка int tmp = r.m_left; вызовет ошибку компиляции, так как m_left является членом класса Rect, объявленным с модификатором private.
    
    Спецификатор доступа private означает, что члены класса (переменные или функции) с этим модификатором доступа могут быть использованы только внутри самого класса, но не снаружи. Таким образом, попытка обращения к m_left вне класса приводит к ошибке компиляции, поскольку переменные с private доступом недоступны за пределами класса, где они объявлены.
    */

    // Вызовите методы SetAll и GetAll для проверки корректности
    r.SetAll(1, 2, 3, 4);
    int left, right, top, bottom;
    r.GetAll(left, right, top, bottom);

    // 2б. Метод InflateRect()
    r.InflateRect(1, 1);  // Вызывается метод для r
    r.PrintRect();

    return 0;
}
