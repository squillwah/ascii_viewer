#include "ascii_viewer.h"
#include <stdlib.h>
#include <string.h>


// image (con/de)structors
void initImage(Image* img, int sx, int sy) {
    img->size_x = sx;
    img->size_y = sy;
    img->buffer = (char*)malloc(sizeof(char)*sx*sy);
    memset(img->buffer, ' ', sx*sy);
}

void destroyImage(Image* img) {
    free(img->buffer);
}

// screen (con/de)structors
void initScreen(Screen* scr, int sx, int sy) {
    scr->size_x = sx;
    scr->size_y = sy;
    // Each row is sx+1 to include newline character
    scr->surface = (char*)malloc(sizeof(char)*(sx+1)*sy);
    memset(scr->surface, '*', (sx+1)*sy);
    // Insert new line at end of each row until last
    for (int row = 0; row < sy-1; row++)
        scr->surface[(row*sx+1)+(sx+1)] = '\n';
    scr->surface[(sy*sx+1)] = '\0';
}

void destroyScreen(Screen* scr) {
    free(scr->surface);
}


// image functions
// sets a pixel in buffer, checks for out of bounds
void setPixel(Image* image, int x, int y, char c) {
    if (x > -1 && x < image->size_x && y > -1 && y < image->size_y)
        image->buffer[x+y*image->size_y] = c;
}
// clears every pixel in buffer
void wipeBuffer(Image* image) {
    for (int i = 0 ; i < image->size_x*image->size_y; i++) 
        image->buffer[i] = ' ';
}
// sets two pixels
void drawLine(Image* image, int from_x, int from_y, int to_x, int to_y) {
    setPixel(image, from_x, from_y, 'X');   
    setPixel(image, to_y, to_y, 'X');   
}
// sets every pixel in image to N
void drawShape(Image* image, enum Shape shape) {
    switch (shape) {
        case Rect:
        case Circle:
        case Triangle:
        default:
            for (int y = 0; y < image->size_y; y++)
                for (int x = 0; x < image->size_x; x++)
                    setPixel(image, x, y, 'N');
    }
}
// draws one image on top of another at given x/y (top left starts)
void impose(Image* image, const Image* overlay, int at_x, int at_y) {
    for (int line = 0; line < overlay->size_y; line++)
        for (int pixel = 0; pixel < overlay->size_x; pixel++) 
            setPixel(image, at_x+pixel, at_y+line, overlay->buffer[pixel+line*overlay->size_y]);
}

// screen function
// stiches an image to screen surface
void stitch(Screen* scr, const Image* img, int topLeftX, int topLeftY) {
    int row = topLeftY;
    int col = topLeftX;
}


//// screen class constructor
//Screen::Screen(int width, int height) : screenImage(width, height) {} 
//
//// wipes the screens buffer
//void Screen::wipe() {
//    img::wipeBuffer(screenImage);
//}
//// renders screen to terminal
//void Screen::render() {
//    char frameString[(screenImage.size_x*2+4)*(screenImage.size_y+2)];
//    int p = 0;
//    
//    frameString[p] = '/'; p++;
//    for (int i = 0; i < screenImage.size_x*2+1; i++) {
//        frameString[p] = '-'; p++;
//    }
//    frameString[p] = '\\'; p++;
//    frameString[p] = '\n'; p++;
//
//    for (int i = 0; i < screenImage.size_y; i++) {
//        frameString[p] = '|'; p++;
//        frameString[p] = ' '; p++;
//        for (int j = 0; j < screenImage.size_x; j++) {
//            frameString[p] = screenImage.buffer[i*screenImage.size_y+j]; p++; 
//            frameString[p] = ' '; p++;
//        }
//        frameString[p] = '|'; p++;
//        frameString[p] = '\n'; p++;
//    }
//   
//    
//    frameString[p] = '\\'; p++;
//    for (int i = 0; i < screenImage.size_x*2+1; i++) {
//        frameString[p] = '-'; p++;
//    }
//    frameString[p] = '/'; p++;
//    frameString[p] = '\0';
//    std::cout << frameString << std::endl;
//}
//// blits an image onto the screen at given x/y (top left)
//void Screen::blit(img::Image& image, int at_x, int at_y) {
//    img::impose(screenImage, image, at_x, at_y);
//}



