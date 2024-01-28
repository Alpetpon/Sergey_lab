#include <iostream>
#include <algorithm>

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

    int getLeft() const { return left; }
    int getTop() const { return top; }
    int getRight() const { return right; }
    int getBottom() const { return bottom; }

    // 4b. Метод класса для нахождения ограничивающего прямоугольника
    Rect BoundingRect(const Rect& other) const {
        int l_1 = std::min(getLeft(), other.getLeft());
        int t_1 = std::min(getTop(), other.getTop());
        int r_2 = std::max(getRight(), other.getRight());
        int b_2 = std::max(getBottom(), other.getBottom());

        return Rect(l_1, t_1, r_2, b_2);
    }
};

// 4а. Глобальная функция для нахождения ограничивающего прямоугольника
Rect BoundingRect2(const Rect& rect1, const Rect& rect2) {
    int l_1 = std::min(rect1.getLeft(), rect2.getLeft());
    int t_1 = std::min(rect1.getTop(), rect2.getTop());
    int r_2 = std::max(rect1.getRight(), rect2.getRight());
    int b_2 = std::max(rect1.getBottom(), rect2.getBottom());

    return Rect(l_1, t_1, r_2, b_2);
}

int main() {
    Rect r1(1, 2, 3, 4);
    Rect r2(3, 1, 5, 6);

    // 4а. Вызов глобальной функции BoundingRect2
    Rect r3 = BoundingRect2(r1, r2);
    std::cout << "BoundingRect2 result: ";
    r3.PrintRect();

    // 4b. Вызов метода BoundingRect для объекта r1
    Rect r4 = r1.BoundingRect(r2);
    std::cout << "BoundingRect method result: ";
    r4.PrintRect();

    return 0;
}
