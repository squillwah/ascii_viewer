#include "ascii_viewer.h"
//#include <thread>
//#include <chrono>
//#include <ncurses.h>
//#include <stdlib.h>
#include <stdio.h>


int main() {

    char test[] = {'0','0','0','0','0','\n',
                   '0','0','0','0','0','\n',
                   '0','0','0','0','0','\n',
                   '0','0','0','0','0','\n',   
                   '0','0','0','0','0','\0'};
    printf("%s\n\n\n", test);

    Screen s;
    initialize_Screen(&s, 50, 50);

    printf("%s\n\n", s.surface);
    //scr_wipe(&s);
    //printf("%s\n\n", s.surface);

    //scr_setPixel(&s, 1, 2, 'X');
    //printf("%s\n\n", s.surface);

    //for (int i = 0; i < s.blockSize; i++)
    //    printf("%c", s.surface[i]);

    //for (int y = 0; y < s.pixelsY; y++)
    //    for (int x = 0; x < s.pixelsX; x++) {
    //        scr_setPixel(&s, x, y, 'X');
    //        printf("%s\n\n", s.surface);
    //    }
    
    Image i;
    initialize_Image(&i, 10, 10);

    image_draw_shape(&i, Rect);
    
    Image j;
    initialize_Image(&j, 5, 3);

    
    screen_blit_image(&s, &i, 3, 3);

    printf("%s\n\n", s.surface);

    
    image_impose_image(&i, &j, 2, 2);
    
    screen_blit_image(&s, &i, 3, 3);

    printf("%s\n\n", s.surface);

    destroy_Image(&i);
    destroy_Image(&j);
    destroy_Screen(&s);

    return 0;
}













//int main() {
//    Screen window(40, 40);
//
//    img::Image square(4, 4);
//    img::drawShape(square, Rect);
//
//    window.render();
//
//    window.blit(square, 5, 8);
//
//
//    img::Image eye(5,5);
//    img::Image iris(3,1);
//
//    img::drawShape(eye, Rect);
//    img::impose(eye, iris, 1, 2);
//
//    window.blit(eye, 5, 16);
//
//    window.blit(eye, 15, 16);
//
//    window.render();
//
////    initscr();
////    raw();
////    noecho();
//
//    int x = 0, y = 0;
//    bool openclose = false;
//    while (true) { 
//        window.wipe();
//        window.blit(square, x, y);
//        window.blit(eye, 5, 16);
//        window.blit(eye, 15, 16);
//        window.render();
//
//        x++;
//        y++;
//        if (x >= 40 || y >= 40)
//            x = y = 0;
//
//        if ((x % 10) == 0) {
//            if (openclose) 
//                img::drawShape(eye, Rect); 
//            else
//                img::impose(eye, iris, 1, 2);
//            openclose = !openclose;
//        }
//
//        std::this_thread::sleep_for(std::chrono::milliseconds(100));
////        refresh();
//    }
//
////    endwin();
//
//    return 0;
//}
