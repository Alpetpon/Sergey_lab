#include "color.h"

int main() {
    Rect r(Color::GREEN, 0, 10, 0, 10);
    Circle c(Color::BLUE, 5);

    r.WhereAmI();
    c.WhereAmI();

    Shape* pRect = &r;
    Shape* pCircle = &c;

    pRect->WhereAmI();
    pCircle->WhereAmI();


    Shape& rRect = r;
    Shape& rCircle = c;


    rRect.WhereAmI();
    rCircle.WhereAmI();


    r.WhereAmIVirtual();
    c.WhereAmIVirtual();


    pRect->WhereAmIVirtual();
    pCircle->WhereAmIVirtual();


    rRect.WhereAmIVirtual();
    rCircle.WhereAmIVirtual();

    return 0;
}
