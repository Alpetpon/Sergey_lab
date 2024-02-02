#ifndef COLOR_H
#define COLOR_H

#include <iostream>

enum Color { RED, GREEN, BLUE };

const char* colorToString(Color c);

class Shape {
protected:
    Color color;

public:
    Shape(Color c);
    
    Color getColor() const;

    void WhereAmI() const;

    virtual void WhereAmIVirtual() const;

    virtual void Inflate(int factor) {
        std::cout << "Inflating in Shape by factor: " << factor << std::endl;
    }

    virtual ~Shape();

    virtual void printInfo() const;
};

class Rect : public Shape {
private:
    int width;
    int height;
    int x;
    int y;
public:
    Rect(Color c = RED);
    
    int getWidth() const;
    
    int getHeight() const;
    
    int getX() const;
    
    int getY() const;

    void WhereAmI() const;

    void WhereAmIVirtual() const override;

    void printInfo() const override;

    void Inflate(int factor) override;

    ~Rect();
};

class Circle : public Shape {
private:
    int centerX;
    int centerY;
    int radius;
    
public:
    Circle(Color c);
    Circle(Color c, int centerX, int centerY, int radius);
    
    Circle();
    
    Circle(const Rect& rect);

    
    void WhereAmI() const;
    
    void WhereAmIVirtual() const override;
    
    void Inflate(int factor) override;
    
    void printInfo() const override;
    
    ~Circle();
};

#endif
