#include "color.h"


int main() {
    Rect r(GREEN);
    
    Shape* ar[] = {new Rect(GREEN), new Circle(RED), new Circle(), new Rect(BLUE)};
    
    for (int i = 0; i < 4; ++i) {
        ar[i]->WhereAmIVirtual();
    }
    
    for (int i = 0; i < 4; ++i) {
        delete ar[i];
    }
    
    return 0;
}
