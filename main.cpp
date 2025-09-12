#include <iostream>
#include "ascii_process.h"

int main() {
    Window scr;
    
    switch (ascii_process::run(scr, 30)) {
        case 0:
            std::cout << "quit" << std::endl;
            break;
        default:
            break;
    }
  
    return 0;
}

