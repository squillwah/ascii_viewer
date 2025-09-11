#include <iostream>
#include <thread>
#include <chrono>

struct Screen {
    static const int WIDTH = 48*2;
    static const int HEIGHT = 27*2;
    static const int REFRESH = 30;
    char buffer[HEIGHT][WIDTH];
} screen;

void clearBuffer(Screen& scr);
void renderFrame(const Screen& scr);
void drawCircle(Screen& scr, int x, int y, int r);

int main() {
    clearBuffer(screen);
  
    while (true) { 
        for (int i = 0; i < screen.WIDTH/2; i++) {
            std::this_thread::sleep_for(std::chrono::milliseconds(1000/screen.REFRESH));
            drawCircle(screen, 10+i, 15, 4);
            renderFrame(screen);
            clearBuffer(screen);
        }
    }
    
    return 0;
}

void drawCircle(Screen& scr, int x, int y, int r) {
    for (int i = 0; i < r; i++) {
        scr.buffer[y+i][x] = 'X';
        scr.buffer[y-i][x] = 'X';
        
        scr.buffer[y][x+i] = 'X';
        scr.buffer[y][x-i] = 'X';
    }
}


void clearBuffer(Screen& scr) {
    for (int i = 0; i < scr.HEIGHT; i++) 
        for (int j = 0; j < scr.WIDTH; j++)
            scr.buffer[i][j] = ' ';
}

void renderFrame(const Screen& scr) {
    std::cout << '/';
    for (int i = 0; i < scr.WIDTH*2+1; i++)
        std::cout << '-'; 
    std::cout << '\\';
    std::cout << '\n';

    for (int i = 0; i < scr.HEIGHT; i++) {
        std::cout << '|' << ' ';
        for (int j = 0; j < scr.WIDTH; j++) 
            std::cout << scr.buffer[i][j] << ' ';
        std::cout << '|' << '\n';
    }
   
    
    std::cout << '\\';
    for (int i = 0; i < scr.WIDTH*2+1; i++)
        std::cout << '-'; 
    std::cout << '/';
    std::cout << std::endl;
}
