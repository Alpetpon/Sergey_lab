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

    ~Shape() {
        std::cout << "Now I am in Shape's destructor!" << std::endl;
    }

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

    ~Rect() {
        std::cout << "Now I am in Rect's destructor!" << std::endl;
    }

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

    ~Circle() {
        std::cout << "Now I am in Circle's destructor!" << std::endl;
    }

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

    

    return 0;
}
