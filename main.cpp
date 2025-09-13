#include "ascii_viewer.h"
#include <thread>
#include <chrono>

int main() {
    Screen window(40, 40);

    img::Image square(4, 4);
    img::drawShape(square, Rect);

    window.render();

    window.blit(square, 5, 8);

    int x = 0, y = 0;
    while (true) { 
        window.wipe();
        window.blit(square, x, y);
        window.render();

        x++;
        y++;
        if (x >= 40 || y >= 40)
            x = y = 0;

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    return 0;
}
