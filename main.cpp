#include "snake.h"

int main() {

    Game g1;

    while( !g1.getGO()) {
        g1.draw();
        g1.input();
        g1.logic();
    }
    

    return 0;
}