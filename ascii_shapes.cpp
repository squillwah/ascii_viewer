#include "ascii_shapes.h"

Shape::Shape(ShapeTypes t, int sX, int sY) { 
    sizeX = sX;
    sizeY = sY;
    image = new char[sizeX*sizeY];
    type = t;

    switch (type) {
        case Circle:
        case Square:
        default:
            for (int i = 0; i < sizeX*sizeY; i++)
                image[i] = 'N';
    }
}

Shape::~Shape() {
    delete[] image;
}

void drawShape(Window& screen, const Shape& shape, int x, int y) {
    for (int row = 0; row < shape.sizeY; row++)
        for (int col = 0; col < shape.sizeX; col++)
            setPixel(screen, shape.image[row*shape.sizeY+col], x+col, y+row);
}
