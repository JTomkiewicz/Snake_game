#ifndef SNAKE_H
#define SNAKE_H

class Game {

    private:

    const int width = 20;
    const int height = 20;
    bool gameOver;
    int x, y;
    int pointX, pointY;
    enum direction {STOP = 0, LEFT, RIGHT, UP, DOWN};
    direction dir;
    int score;
    int tailX[100], tailY[100];
    int lengthTail;

    public:

    Game();
    void draw();
    void input();
    void logic();
    bool getGO() {return gameOver;}
};

#endif