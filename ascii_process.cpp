#include "ascii_process.h"
#include "ascii_viewer.h"
#include <thread>
#include <chrono>
//#include <cmath>

int ascii_process::run(Window& screen, const int REFRESH) {
    Shape circle;
    
    clearBuffer(screen);
    while (true) { 
        for (int i = 0; i < screen.WIDTH/2; i++) {
            std::this_thread::sleep_for(std::chrono::milliseconds(1000/REFRESH));
            //drawCircle(screen, 10+i, 15+std::sin(i)*10, 4);
            drawShape(screen, circle, 10, 10);
            renderBuffer(screen);
            clearBuffer(screen);
        }
    }

    return 0;
}
