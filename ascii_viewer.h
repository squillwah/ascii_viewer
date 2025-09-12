#ifndef ASCII_VIEWER_H
#define ASCII_VIEWER_H

struct Window {
    static const int WIDTH = 40;
    static const int HEIGHT = 40;
    char buffer[HEIGHT][WIDTH];
};

struct Shape {
    static const int WIDTH = 5;
    static const int HEIGHT = 5;
    char image[5][5] = {{' ', ' ', 'X', ' ', ' '},
                        {' ', 'X', 'X', 'X', ' '},
                        {'X', 'X', 'X', 'X', 'X'},
                        {' ', 'X', 'X', 'X', ' '},
                        {' ', ' ', 'X', ' ', ' '}};
};

void clearBuffer(Window&);
void renderBuffer(const Window&);

void setPixel(Window&, char, int, int);
void drawShape(Window&, const Shape&, int, int);

void initCircle(Shape&);

#endif
