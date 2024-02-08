#include "color.h"

int main() {
    Rect r(GREEN);
    
    Shape* ar[] = {&r, new Rect(r), new Circle(), new Circle() };
    

    for (int i = 0; i < 4; ++i) {
        ar[i]->WhereAmIVirtual();
    }
    
    
    return 0;
}
