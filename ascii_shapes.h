#ifndef ASCII_SHAPES_H
#define ASCII_SHAPES_H

#include "ascii_viewer.h"

enum ShapeTypes {
    Square,
    Circle
};

struct Shape {
    int sizeX;
    int sizeY;
    char* image;
    ShapeTypes type;

    Shape(ShapeTypes, int, int);
    ~Shape();
};

void drawShape(Window&, const Shape&, int, int);

#endif
