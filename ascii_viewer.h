#ifndef ASCII_VIEWER
#define ASCII_VIEWER

enum Shape {
    Rect,
    Circle,
    Triangle
};

typedef struct Image {
    int size_x;
    int size_y;
    char* buffer;
} Image;
void initImage(Image* img, int sx, int sy);
void destroyImage(Image* img);

typedef struct Screen {
    int size_x;
    int size_y;
    char* surface;
} Screen;
void initScreen(Screen* scr, int sx, int sy);
void destroyScreen(Screen* scr);

void setPixel(Image* image, int x, int y, char c);   
void wipeBuffer(Image* image);
void drawShape(Image* image, enum Shape shape);
void drawLine(Image* image, int from_x, int from_y, int to_x, int to_y);
void impose(Image* image, const Image* overlay, int at_x, int at_y);

void stitch(Screen* scr, const Image* img, int topLeftX, int topLeftY);


//class Screen {
//  public:
//    bool fl_boarder;
//
//    Screen(int width, int height);
//    
//    void wipe();
//    void render();
//    void blit(const Image* image, int at_x, int at_y);
//
//  private:
//    Image screenImage;
//};

#endif
