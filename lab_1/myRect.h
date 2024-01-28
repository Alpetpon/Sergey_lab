//Задание 1
#ifndef MYRECT_H
#define MYRECT_H

#include <iostream>

class Rect {
public:
    int m_left;
    int m_right;
    int m_top;
    int m_bottom;

public:
    Rect();  // Конструктор без параметров
    Rect(int left, int right, int top, int bottom);  // Конструктор с параметрами
    void InflateRect(int xIncrement, int yIncrement);  // Метод увеличения размеров прямоугольника
    void Normalize();  // Метод для проверки и коррекции "ненормализованного" прямоугольника
    void PrintRect() const;  // Метод для вывода прямоугольника в консоль
};

#endif 


// Задание 2

#ifndef RECT_H
#define RECT_H

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
    void InflateRect(int xIncrement, int yIncrement);
    void InflateRect(int xIncrement, int yIncrement, int xIncrement2, int yIncrement2);
    void InflateRect(int increment);
    void InflateRect();
    void Normalize();
    void PrintRect() const;
};

#endif


//Задание 3

#ifndef MYRECT_H
#define MYRECT_H

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

#endif

//4 задание
#ifndef RECT_H
#define RECT_H

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

#endif 

//задание 5
#ifndef RECT_H
#define RECT_H

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

#endif 
