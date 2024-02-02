#include "color.h"

int main() {
    Rect r(GREEN);
    Shape* p = &r;
    
    p->WhereAmIVirtual();
    r.Shape::WhereAmIVirtual();

    return 0;
}
