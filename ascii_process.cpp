#include "ascii_process.h"
#include "ascii_viewer.h"
#include "ascii_shapes.h"
#include <thread>
#include <chrono>
//#include <cmath>

int ascii_process::run(Window& screen, const int REFRESH) {
    Shape circle(Circle, 5, 5);
    
    clearBuffer(screen);
    while (true) { 
        for (int i = 0; i < screen.WIDTH/2; i++) {
            std::this_thread::sleep_for(std::chrono::milliseconds(1000/REFRESH));
            //drawCircle(screen, 10+i, 15+std::sin(i)*10, 4);
            drawShape(screen, circle, 10+i, 10);

            /*int r = i/2;    
            for (int i = -r; i < r; i++) 
                for (int j = -r; j < r; j++) 
                    screen.buffer[10+i][10+j] = 'X';
*/
            renderBuffer(screen);
            clearBuffer(screen);
        }
    }

    return 0;
}
