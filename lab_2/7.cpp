#include <iostream>

enum Color {
    RED,
    GREEN,
    BLUE
};

class Shape {
protected:
    Color color;

public:
    Shape(Color c) : color(c) {}

    virtual ~Shape() {}

    void WhereAmIVirtual() {
        std::cout << "Now I am in class Shape (virtual)" << std::endl;
    }
};

class Rect : public Shape {
public:
    Rect(Color c) : Shape(c) {}

    ~Rect() override {}

    void WhereAmIVirtual()  {
        std::cout << "Now I am in class Rect (virtual)" << std::endl;
    }
};

int main() {
    Rect r(GREEN);
    Shape* p = &r;

    p->WhereAmIVirtual(); // Now I am in class Shape (virtual)

    // Оператор разрешения области видимости для вызова WhereAmIVirtual() из класса Shape
    r.Shape::WhereAmIVirtual(); // Now I am in class Shape (virtual)

    return 0;
}
