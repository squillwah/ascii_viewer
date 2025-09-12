#ifndef ASCII_VIEWER_H
#define ASCII_VIEWER_H

struct Window {
    static const int WIDTH = 40;
    static const int HEIGHT = 40;
    char buffer[HEIGHT][WIDTH];
};

void clearBuffer(Window&);
void renderBuffer(const Window&);

void setPixel(Window&, char, int, int);

//void initShape(Shape&, Shape_Types, int);
//void destroyShape(Shape&);

#endif
