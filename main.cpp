#include <iostream>
#include <thread>
#include <chrono>
#include <cmath>

struct Screen {
    static const int WIDTH = 48*2;
    static const int HEIGHT = 27*2;
    static const int REFRESH = 10;
    char buffer[HEIGHT][WIDTH];
};

int run(Screen& screen);
void clearBuffer(Screen& scr);
void renderFrame(const Screen& scr);
void drawCircle(Screen& scr, int x, int y, int r);

int main() {
    Screen scr;
    clearBuffer(scr);
    
    switch (run(scr)) {
        case 0:
            std::cout << "quit" << std::endl;
            break;
        default:
            break;
    }
  
    return 0;
}

int run(Screen& screen) {
    while (true) { 
        for (int i = 0; i < screen.WIDTH/2; i++) {
            std::this_thread::sleep_for(std::chrono::milliseconds(1000/screen.REFRESH));
            drawCircle(screen, 10+i, 15+std::sin(i)*10, 4);
            renderFrame(screen);
            clearBuffer(screen);
        }
    }

    return 0;
}

void drawCircle(Screen& scr, int x, int y, int r) {

/*          
 *        XXXXXXX
 *      XXXXXXXXXXX
 *     XXXXXXXXXXXXX
 *     XXXXXXXXXXXXX
 *     XXXXXXXXXXXXX
 *      XXXXXXXXXXX
 *        XXXXXXX
 *
 *         X X X X
 *       X X X X X X
 *       X X X X X X
 *       X X X X X X
 *         X X X X X
 *         
 */


//    for (int i = 0; i < r; i++) {
//        for (int i = 0; i < 
//

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
    char frameString[(scr.WIDTH*2+4)*(scr.HEIGHT+2)];
    int p = 0;
    
    frameString[p] = '/'; p++;
    for (int i = 0; i < scr.WIDTH*2+1; i++) {
        frameString[p] = '-'; p++;
    }
    frameString[p] = '\\'; p++;
    frameString[p] = '\n'; p++;

    for (int i = 0; i < scr.HEIGHT; i++) {
        frameString[p] = '|'; p++;
        frameString[p] = ' '; p++;
        for (int j = 0; j < scr.WIDTH; j++) {
            frameString[p] = scr.buffer[i][j]; p++; 
            frameString[p] = ' '; p++;
        }
        frameString[p] = '|'; p++;
        frameString[p] = '\n'; p++;
    }
   
    
    frameString[p] = '\\'; p++;
    for (int i = 0; i < scr.WIDTH*2+1; i++) {
        frameString[p] = '-'; p++;
    }
    frameString[p] = '/'; p++;
    frameString[p] = '\0';
    std::cout << frameString << std::endl;
}

