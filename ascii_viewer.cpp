#include "ascii_viewer.h"
#include <iostream>


namespace img {
    // image (con/de)structors
    Image::Image(int sx, int sy) {
        size_x = sx;
        size_y = sy;
        buffer = new char[sx*sy];
        wipeBuffer(*this);
    }
    Image::~Image() {
        delete[] buffer;
    }
    
    // image functions
    // sets a pixel in buffer, checks for out of bounds
    void setPixel(Image& image, int x, int y, char c) {
        if (x > -1 && x < image.size_x && y > -1 && y < image.size_y)
            image.buffer[x+y*image.size_y] = c;
    }
    // clears every pixel in buffer
    void wipeBuffer(Image& image) {
        for (int i = 0 ; i < image.size_x*image.size_y; i++) 
            image.buffer[i] = ' ';
    }
    // sets two pixels
    void drawLine(Image& image, int from_x, int from_y, int to_x, int to_y) {
        setPixel(image, from_x, from_y, 'X');   
        setPixel(image, to_y, to_y, 'X');   
    }
    // sets every pixel in image to N
    void drawShape(Image& image, Shape shape) {
        switch (shape) {
            case Rect:
            case Circle:
            case Triangle:
            default:
                for (int y = 0; y < image.size_y; y++)
                    for (int x = 0; x < image.size_x; x++)
                        setPixel(image, x, y, 'N');
        }
    }
    // draws one image on top of another at given x/y (top left starts)
    void impose(Image& image, const Image& overlay, int at_x, int at_y) {
        for (int line = 0; line < overlay.size_y; line++)
            for (int pixel = 0; pixel < overlay.size_x; pixel++) 
                setPixel(image, at_x+pixel, at_y+line, overlay.buffer[pixel+line*overlay.size_y]);
    }
}


// screen class constructor
Screen::Screen(int width, int height) : screenImage(width, height) {} 

// wipes the screens buffer
void Screen::wipe() {
    img::wipeBuffer(screenImage);
}
// renders screen to terminal
void Screen::render() {
    char frameString[(screenImage.size_x*2+4)*(screenImage.size_y+2)];
    int p = 0;
    
    frameString[p] = '/'; p++;
    for (int i = 0; i < screenImage.size_x*2+1; i++) {
        frameString[p] = '-'; p++;
    }
    frameString[p] = '\\'; p++;
    frameString[p] = '\n'; p++;

    for (int i = 0; i < screenImage.size_y; i++) {
        frameString[p] = '|'; p++;
        frameString[p] = ' '; p++;
        for (int j = 0; j < screenImage.size_x; j++) {
            frameString[p] = screenImage.buffer[i*screenImage.size_y+j]; p++; 
            frameString[p] = ' '; p++;
        }
        frameString[p] = '|'; p++;
        frameString[p] = '\n'; p++;
    }
   
    
    frameString[p] = '\\'; p++;
    for (int i = 0; i < screenImage.size_x*2+1; i++) {
        frameString[p] = '-'; p++;
    }
    frameString[p] = '/'; p++;
    frameString[p] = '\0';
    std::cout << frameString << std::endl;
}
// blits an image onto the screen at given x/y (top left)
void Screen::blit(img::Image& image, int at_x, int at_y) {
    img::impose(screenImage, image, at_x, at_y);
}



