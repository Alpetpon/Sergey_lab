#include <iostream>


class Rect {
private:
    int left, top, right, bottom;

public:
    Rect() : left(0), top(0), right(0), bottom(0) {}

    Rect(int l, int t, int r, int b) : left(l), top(t), right(r), bottom(b) {}


    Rect(const Rect& other) : left(other.left), top(other.top), right(other.right), bottom(other.bottom) {}


    void InflateRect(int x = 1, int y = 1, int z = 1, int w = 1) {
        left -= x;
        top -= y;
        right += z;
        bottom += w;
    }

    void PrintRect() const {
        std::cout << "Left: " << left << ", Top: " << top << ", Right: " << right << ", Bottom: " << bottom << std::endl;
    }
};

int main() {
    Rect r1;
    Rect r2(1, 2, 3, 4);
    Rect r3 = r1;
    Rect r4(r2);


    std::cout << "r1: ";
    r1.PrintRect();

    std::cout << "r2: ";
    r2.PrintRect();

    std::cout << "r3: ";
    r3.PrintRect();

    std::cout << "r4: ";
    r4.PrintRect();


    r1.InflateRect(1, 1);
    r2.InflateRect(2, 2);


    std::cout << "r1 after InflateRect: ";
    r1.PrintRect();

    std::cout << "r2 after InflateRect: ";
    r2.PrintRect();

    r3.InflateRect(2, 2, 2, 2);
    r3.InflateRect(3, 3);
    r3.InflateRect(5);
    r3.InflateRect();

    std::cout << "r3 after multiple InflateRect calls: ";
    r3.PrintRect();

    return 0;
}
