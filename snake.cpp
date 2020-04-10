#include "snake.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

Game::Game() {
    srand(time(NULL));
    gameOver = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    pointX = rand() % width-1 + 1;
    pointY = rand() % height-1 + 1;
    score = 0;
    lengthTail = 0;
}

void Game::draw() {

    system("clear");
    for(int i = 0; i < width; i++) cout << "#"; //top
    cout << endl;

    for(int i = 0; i < height; i++) {

        for(int j = 0; j < width; j++) {
            if(j == 0 || j == width-1) cout << "#";

            else if(j == y && i == x) cout << "O";

            else if(j == pointY && i == pointX) cout << "*";

            else {
                bool print = false;
                for(int k = 0; k < lengthTail; k++) {
                    if(tailX[k] == i && tailY[k] == j) {
                        cout << "o";
                        print = true;
                    }
                }
                if(!print)cout << " ";
            }

        }
        cout << endl;

    }

    for(int i = 0; i < width; i++) cout << "#"; //bottom
    cout << endl << "SCORE: " << score << "\nPress Q to quit" << endl;

}

void Game::input() {

    system("stty raw");

    char key;
	key = getchar();

    switch (key)
    {
    case 'a':
        dir = UP;
        break;
    case 'w':
        dir = LEFT;
        break;
    case 's':
        dir = RIGHT;
        break;
    case 'd':
        dir = DOWN;
        break;
    case 'q':
        gameOver = true;
        break;
    }
}

void Game::logic() {

    
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    
    for(int i = 1; i <= lengthTail; i++) {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (dir)
	{
		case LEFT:
			x--;
			break;
		case UP:
			y--;
			break;
		case RIGHT:
			x++;
			break;
		case DOWN:
			y++;
			break;	
        default:
            break;	  
	}

    if(x < 0 || x >= width || y < 0 || y >= height) gameOver = true;

    for(int i = 0; i < lengthTail; i++) if(tailX[i] == x && tailY[i] == y) gameOver = true;

    if(x == pointX && y == pointY) {
        score += 10;
        pointX = rand() % width-2 + 1;
        pointY = rand() % height-2 + 1;
        lengthTail++;
    }

	system("stty cooked");
}