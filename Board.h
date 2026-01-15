#ifndef BOARD_H
#define BOARD_H

#include "Obstacle.h"

class Board {
public:
    static const int WIDTH = 10;
    static const int HEIGHT = 8;

    char map[HEIGHT][WIDTH];
    Obstacle* obstacles[HEIGHT][WIDTH];

    Board(int level);
    void draw(int frogX, int frogY);
};

#endif
