#include <iostream>

struct Screen {
    static const int WIDTH = 10;
    static const int HEIGHT = 10;
    char buffer[HEIGHT][WIDTH];
} screen;

void renderFrame(const Screen& buffer);

int main() {
    renderFrame(screen); 

    return 0;
}

void renderFrame() {
    std::ostream* frame; 
    *frame << '-';
    std::cout << frame;

    //std::cout << "-----------" << std::endl;
    //for (int i = 0;
}
