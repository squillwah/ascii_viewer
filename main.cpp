#include "ascii_viewer.h"

int main() {
    Screen window(40, 40);

    img::Image square(4, 4);
    drawShape(square, Rect);

    window.render();

    window.blit(square, 5, 8);
    
    window.render();

    return 0;
}
