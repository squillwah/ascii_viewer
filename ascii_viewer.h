#ifndef ASCII_VIEWER
#define ASCII_VIEWER

enum Shape {
    Rect,
    Circle,
    Triangle
};

namespace img {
    struct Image {
        int size_x = 0;
        int size_y = 0;
        char* buffer;
    
        Image(int sx, int sy);
        ~Image();
    };
    
    void wipeBuffer(Image& image);
    void drawShape(Image& image, Shape shape);
    void drawLine(Image& image, int from_x, int from_y, int to_x, int to_y);
    void impose(Image& image, const Image& overlay, int at_x, int at_y);
}

class Screen {
  public:
    bool fl_boarder;

    Screen(int width, int height);
    
    void wipe();
    void render();
    void blit(img::Image& image, int at_x, int at_y);

  private:
    img::Image screenImage;
};

#endif
