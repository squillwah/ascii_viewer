#ifndef ASCII_VIEWER
#define ASCII_VIEWER

typedef struct Image {
    int sizeX;          // Width of the char buffer
    int sizeY;          // Height of the char buffer
    char* buffer;
} Image;

typedef struct Screen {
    int width;        // Pixel resolution width
    int height;        // Pixel resolution height
    int lineSize;       // Length of each horizontal screen line
    int blockSize;      // Total size of the screen's surface
    char* surface;
} Screen;

enum Shape {
    Rect,
    Circle,
    Triangle
};

void initialize_Image(Image* img, int sx, int sy);
void initialize_Screen(Screen* scr, int sx, int sy);
void destroy_Image(Image* img);
void destroy_Screen(Screen* scr);

void image_set_pixel(Image* img, int x, int y, char c);                     // Set char at (x, y) to c
char image_get_pixel(const Image* img, int x, int y);                       // Get char at (x, y)
void image_wipe_buffer(Image* img);                                         // Set all chars in image to ' '
void image_draw_shape(Image* img, enum Shape shape);                        // Fill image with predefined shape
void image_draw_line(Image* img, int fromX, int fromY, int toX, int toY);   // Draw line from point to point
void image_impose_image(Image* img1, const Image* img2, int atX, int atY);  // Overlay an image ontop of another, top left of overlay at (x, y)

void screen_blit_image(Screen* scr, const Image* img, int atX, int atY);  // Copy chars from image buffer to screen surface, starting from top left
void screen_wipe_surface(Screen* scr);                                    // Set all pixels in screen to ' '
//void screen_print_surface(const Screen* scr);                             // Send screen surface string to printf

#endif
