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

        
    virtual void Inflate(int factor) = 0; 
    
    virtual ~Shape() {
        std::cout << "Now I am in Shape's destructor!" << std::endl;
    }

    
};

class Rect : public Shape {
public:
    Rect(Color c = RED) : Shape(c) {}
    
    void WhereAmI() const {
        std::cout << "Now I am in class Rect" << std::endl;
    }

    void WhereAmIVirtual() const override {
        std::cout << "Now I am in class Rect (virtual)" << std::endl;
    }
    
    void Inflate(int factor) override {
        std::cout << "Rect is inflating by a factor of " << factor << std::endl;
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
    
    void Inflate(int factor) override {
        std::cout << "Circle is inflating by a factor of " << factor << std::endl;
    }

    ~Circle() {
        std::cout << "Now I am in Circle's destructor!" << std::endl;
    }
};

int main() {
    Rect r;
    Shape* p = &r;
    p->Inflate(5); 
    
    Circle c;
    p = &c;
    p->Inflate(5);
    return 0;
}
