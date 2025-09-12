#include "ascii_viewer.h"
#include <iostream>

void clearBuffer(Window& screen) {
    for (int i = 0; i < screen.HEIGHT; i++) 
        for (int j = 0; j < screen.WIDTH; j++)
            screen.buffer[i][j] = ' ';
}

void renderBuffer(const Window& screen) {
    char frameString[(screen.WIDTH*2+4)*(screen.HEIGHT+2)];
    int p = 0;
    
    frameString[p] = '/'; p++;
    for (int i = 0; i < screen.WIDTH*2+1; i++) {
        frameString[p] = '-'; p++;
    }
    frameString[p] = '\\'; p++;
    frameString[p] = '\n'; p++;

    for (int i = 0; i < screen.HEIGHT; i++) {
        frameString[p] = '|'; p++;
        frameString[p] = ' '; p++;
        for (int j = 0; j < screen.WIDTH; j++) {
            frameString[p] = screen.buffer[i][j]; p++; 
            frameString[p] = ' '; p++;
        }
        frameString[p] = '|'; p++;
        frameString[p] = '\n'; p++;
    }
   
    
    frameString[p] = '\\'; p++;
    for (int i = 0; i < screen.WIDTH*2+1; i++) {
        frameString[p] = '-'; p++;
    }
    frameString[p] = '/'; p++;
    frameString[p] = '\0';
    std::cout << frameString << std::endl;
}

void setPixel(Window& screen, char c, int x, int y) {
    //x = std::min(abs(x), screen.WIDTH);
    //y = std::min(abs(y), screen.HEIGHT);
    screen.buffer[y][x] = c;
}

void drawShape(Window& screen, const Shape& sh, int x, int y) {
    for (int line = 0; line < sh.HEIGHT; line++) 
        for (int pixel = 0; pixel < sh.WIDTH; pixel++)
            setPixel(screen, sh.image[y+line][x+pixel], (x+pixel), (y+line));
}

void initCircle(Shape& sh) {
}

