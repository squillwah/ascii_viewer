#include "ascii_viewer.h"
#include <stdlib.h>
#include <string.h>

// -----------------------------------------
// INITIALIZERS + DESTRUCTORS
// -----------------------------------------
void initialize_Image(Image* img, int sx, int sy) 
{
    img->sizeX = sx;
    img->sizeY = sy;
    img->buffer = (char*)malloc(sizeof(char)*sx*sy);
    
    memset(img->buffer, 'I', sx*sy);
}
void initialize_Screen(Screen* scr, int sx, int sy) 
{
    scr->width = sx;
    scr->height = sy;
    scr->lineSize = sx*2;   // Each row include subpixel spaces & newline/null characters
    scr->blockSize = scr->lineSize*sy; 
    scr->surface = (char*)malloc(sizeof(char)*scr->blockSize);

    for (int row = 0; row < sy; row++) {
        int pixel = 1;
        int col;
        for (col = 0; col < sx*2 - 1; col++) {
            scr->surface[((sx*2) * row) + col] = pixel*'S' + !pixel*' ';
            pixel = !pixel;
        }
        scr->surface[sx*2*row+col] = '\n';
    }
    scr->surface[scr->blockSize-1] = '\0';
}
void destroy_Image(Image* img) 
{
    free(img->buffer);
}
void destroy_Screen(Screen* scr) 
{
    free(scr->surface);
}

// -----------------------------------------
// IMAGE PROCEDURES
// -----------------------------------------
void image_set_pixel(Image* img, int x, int y, char c) {                    // Safely sets character at (x,y) in image buffer
    int inBounds = (x > -1 && y > -1 && x < img->sizeX && y < img->sizeY);  // Sets top left character if coordinates overflow
    int index = (img->sizeX * y) + x;
    img->buffer[index * inBounds] = c;
}
char image_get_pixel(const Image* img, int x, int y) {                      // Safely returns character at (x,y) in image buffer
    return img->buffer[x*y+x] * (x < img->sizeX && y < img->sizeY);         // Returns null character if out of bounds
}

void image_wipe_buffer(Image* img) {                                        // Sets every character in buffer to ' '
    memset(img->buffer, ' ', img->sizeX*img->sizeY);  
}
void image_draw_line(Image* img, int fromX, int fromY, int toX, int toY) {
    image_set_pixel(img, fromX, fromY, 'X');   
    image_set_pixel(img, toX, toY, 'X');   
}
void image_draw_shape(Image* img, enum Shape shape) {
    switch (shape) {
        case Rect:
        case Circle:
        case Triangle:
        default:
            for (int y = 0; y < img->sizeY; y++)
                for (int x = 0; x < img->sizeX; x++)
                    image_set_pixel(img, x, y, 'N');
    }
}
void image_impose_image(Image* img1, const Image* img2, int atX, int atY) {
    for (int line = 0; line < img2->sizeY; line++)
        for (int pixel = 0; pixel < img2->sizeX; pixel++) 
            image_set_pixel(img1, atX+pixel, atY+line, image_get_pixel(img2, pixel, line));
                   // img2->buffer[pixel+line*overlay->sizeY]);
}

// -----------------------------------------
// SCREEN PROCEDURES
// -----------------------------------------

// Safely set a screen surface pixel
// If a pixel overflows, the top left char will be set
static void screen_set_pixel(Screen* scr, int x, int y, char c) {
    int inBounds = (x > -1 && y > -1 && x < scr->width && y < scr->height);
    int index = (scr->lineSize * y) + (x * 2);
    scr->surface[index * inBounds] = c;         
}

// Copy chars Image buffer to Screen surface
void screen_blit_image(Screen* scr, const Image* img, int atX, int atY) {
    for (int y = 0; y < img->sizeY; y++) 
        for (int x = 0; x < img->sizeX; x++)
            screen_set_pixel(scr, atX+x, atY+y, image_get_pixel(img, x, y));
                    //img->buffer[img->sizeY*y+x]);
}

// Clears every pixel
void screen_wipe_surface(Screen* scr) {
    char* linePtr = scr->surface;
    for (int line = 0; line < scr->height; line++) {
        memset(linePtr, ' ', scr->lineSize-1);       // Wipe line, excluding final newline/nullterm
        linePtr += scr->lineSize;                    // Advance linePtr to next line
    }
    //for (int y = 0; y < scr->pixelsY; y++) 
    //    for (int x = 0; x < scr->pixelsX; x++) 
    //        scr_setPixel(scr, x, y, ' ');
}



            


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



