#include <algorithm>
#include <iostream>

class Rect {
private:
    int m_left;
    int m_right;
    int m_top;
    int m_bottom;

public:
    Rect();
    Rect(int left, int right, int top, int bottom);
    Rect(const Rect& other);
    ~Rect();  
    void InflateRect(int xIncrement, int yIncrement);
    void InflateRect(int xIncrement, int yIncrement, int xIncrement2, int yIncrement2);
    void Normalize();
    void PrintRect() const;
    void SetAll(int left, int right, int top, int bottom);
    void GetAll(int& left, int& right, int& top, int& bottom) const;

    int GetLeft() const;
    int GetRight() const;
    int GetTop() const;
    int GetBottom() const;
};

Rect BoundingRect(const Rect& rect1, const Rect& rect2);
Rect BoundingRect2(const Rect& rect1, const Rect& rect2);

Rect::Rect()
    : m_left(0), m_right(0), m_top(0), m_bottom(0) {
    std::cout << "Constructor called" << std::endl;
}

Rect::Rect(int left, int right, int top, int bottom)
    : m_left(left), m_right(right), m_top(top), m_bottom(bottom) {
    Normalize();
    std::cout << "Parameterized constructor called" << std::endl;
}

Rect::Rect(const Rect& other)
    : m_left(other.m_left), m_right(other.m_right), m_top(other.m_top), m_bottom(other.m_bottom) {
    std::cout << "Copy constructor called" << std::endl;
}

Rect::~Rect() {
    std::cout << "Destructor called" << std::endl;
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

int Rect::GetLeft() const {
    return m_left;
}

int Rect::GetRight() const {
    return m_right;
}

int Rect::GetTop() const {
    return m_top;
}

int Rect::GetBottom() const {
    return m_bottom;
}

Rect BoundingRect(const Rect& rect1, const Rect& rect2) {
    int left = std::min(rect1.GetLeft(), rect2.GetLeft());
    int right = std::max(rect1.GetRight(), rect2.GetRight());
    int top = std::min(rect1.GetTop(), rect2.GetTop());
    int bottom = std::max(rect1.GetBottom(), rect2.GetBottom());

    return Rect(left, right, top, bottom);
}

Rect BoundingRect2(const Rect& rect1, const Rect& rect2) {
    int left = std::min(rect1.GetLeft(), rect2.GetLeft());
    int right = std::max(rect1.GetRight(), rect2.GetRight());
    int top = std::min(rect1.GetTop(), rect2.GetTop());
    int bottom = std::max(rect1.GetBottom(), rect2.GetBottom());

    return Rect(left, right, top, bottom);
}

int main() {
    Rect r1(1, 2, 3, 4), r2(5, 6, 7, 8), r3;

    // Глобальная функция BoundingRect
    r3 = BoundingRect(r1, r2);
    r3.PrintRect();

    // Глобальная функция BoundingRect2
    r3 = BoundingRect2(r1, r2);
    r3.PrintRect();

    return 0;
}
