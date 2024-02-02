#include "color.h"

int main() {
    Rect r;
    Shape* p = &r;
    p->Inflate(5); 
    
    Circle c;
    p = &c;
    p->Inflate(5);
    return 0;
}
