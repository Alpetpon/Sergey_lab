#include "color.h"


int main() {
    Rect r(GREEN);
    Shape s(RED);
    
    Shape* ar[]={new Shape(r), new Rect(r), new Circle(r), new Circle() };
    
    for (int i = 0; i < 4; ++i) {
        ar[i]->WhereAmIVirtual();
    }
    
    for (int i = 0; i < 4; ++i) {
        delete ar[i];
    }
    
    return 0;
}
