#include "color.h"

int main() {
    Rect rect(Color::RED, 0, 10, 0, 10);
    Circle circle(Color::BLUE, 5);

    rect.DisplayInfo();
    circle.DisplayInfo();

    return 0;
}
