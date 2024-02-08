#include "color.h"

int main() {
    Rect r(GREEN); 
    Shape* p = &r;
    p->Inflate(5);
    
    Circle c(BLUE, 10);
    p = &c;
    p->Inflate(5);
    
    return 0;
}
