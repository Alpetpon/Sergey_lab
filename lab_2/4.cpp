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

    void WhereAmI() {
        std::cout << "Now I am in class Shape" << std::endl;
    }

    virtual void WhereAmIVirtual() {
        std::cout << "Now I am in class Shape (virtual)" << std::endl;
    }
};

class Rect : public Shape {
public:
    Rect(Color c) : Shape(c) {}

    void WhereAmI() {
        std::cout << "Now I am in class Rect" << std::endl;
    }

    void WhereAmIVirtual() override {
        std::cout << "Now I am in class Rect (virtual)" << std::endl;
    }
};

class Circle : public Shape {
public:
    Circle(Color c) : Shape(c) {}

    void WhereAmI() {
        std::cout << "Now I am in class Circle" << std::endl;
    }

    void WhereAmIVirtual() override {
        std::cout << "Now I am in class Circle (virtual)" << std::endl;
    }
};

int main() {
    Shape s(RED);
    Rect r(GREEN);
    Circle c(BLUE);

    s.WhereAmI();  // Now I am in class Shape
    r.WhereAmI();  // Now I am in class Rect
    c.WhereAmI();  // Now I am in class Circle

    Shape* pShape = &s;
    Shape* pRect = &r;
    Shape* pCircle = &c;
    pShape->WhereAmI();  // Now I am in class Shape
    pRect->WhereAmI();   // Now I am in class Shape
    pCircle->WhereAmI(); // Now I am in class Shape

    Shape& rShape = s;
    Shape& rRect = r;
    Shape& rCircle = c;
    rShape.WhereAmI();  // Now I am in class Shape
    rRect.WhereAmI();   // Now I am in class Shape
    rCircle.WhereAmI(); // Now I am in class Shape



    //пунктб
    s.WhereAmIVirtual();   // Now I am in class Shape (virtual)
    r.WhereAmIVirtual();   // Now I am in class Rect (virtual)
    c.WhereAmIVirtual();   // Now I am in class Circle (virtual)
    
    pShape->WhereAmIVirtual();  // Now I am in class Shape (virtual)
    pRect->WhereAmIVirtual();   // Now I am in class Rect (virtual)
    pCircle->WhereAmIVirtual(); // Now I am in class Circle (virtual)
    
    rShape.WhereAmIVirtual();  // Now I am in class Shape (virtual)
    rRect.WhereAmIVirtual();   // Now I am in class Rect (virtual)
    rCircle.WhereAmIVirtual(); // Now I am in class Circle (virtual)
    return 0;
}
