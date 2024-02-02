#include "color.h"

int main() {
    Rect r(GREEN);
    Circle c(BLUE);

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
