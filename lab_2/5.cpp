#include <iostream>

enum Color { RED, GREEN, BLUE };

class Shape {
protected:
    Color color;

public:
    Shape(Color c) : color(c) {}

    Color getColor() const {
        return color;
    }

    void WhereAmI() const {
        std::cout << "Now I am in class Shape" << std::endl;
    }

    virtual void WhereAmIVirtual() const {
        std::cout << "Now I am in class Shape (virtual)" << std::endl;
    }

    virtual ~Shape() {
        std::cout << "Now I am in Shape's destructor!" << std::endl;
    }
};

class Rect : public Shape {
public:
    Rect(Color c) : Shape(c) {}

    void WhereAmI() const {
        std::cout << "Now I am in class Rect" << std::endl;
    }

    void WhereAmIVirtual() const override {
        std::cout << "Now I am in class Rect (virtual)" << std::endl;
    }

    ~Rect() {
        std::cout << "Now I am in Rect's destructor!" << std::endl;
    }
};

class Circle : public Shape {
public:
    Circle() : Shape(RED) {}

    Circle(const Rect& rect) : Shape(rect.getColor()) {}

    void WhereAmI() const {
        std::cout << "Now I am in class Circle" << std::endl;
    }

    void WhereAmIVirtual() const override {
        std::cout << "Now I am in class Circle (virtual)" << std::endl;
    }

    ~Circle() {
        std::cout << "Now I am in Circle's destructor!" << std::endl;
    }
};

int main() {
    Rect r(GREEN);
    Shape* ar[] = {new Shape(r), new Rect(r), new Circle(r), new Circle() };

    for (int i = 0; i < 4; ++i) {
        ar[i]->WhereAmIVirtual();
    }

    for (int i = 0; i < 4; ++i) {
        delete ar[i];
    }

    return 0;
}
