#include "Board.h"
#include <iostream>

Board::Board(int level) {
    char level1[HEIGHT][WIDTH] = {
        {' ', ' ', ' ', ' ', 'X', ' ', ' ', ' ', ' ', 'F'},
        {'X', 'X', ' ', ' ', 'X', ' ', 'X', 'X', ' ', 'X'},
        {' ', ' ', ' ', 'X', ' ', ' ', ' ', 'X', ' ', ' '},
        {' ', 'X', ' ', ' ', ' ', 'X', ' ', ' ', 'X', ' '},
        {' ', ' ', ' ', 'X', ' ', ' ', ' ', ' ', ' ', ' '},
        {'X', ' ', 'X', ' ', ' ', 'X', ' ', 'X', ' ', ' '},
        {' ', ' ', ' ', ' ', 'X', ' ', ' ', ' ', 'X', ' '},
        {' ', 'X', ' ', ' ', ' ', ' ', 'X', ' ', ' ', ' '}
    };

    char level2[HEIGHT][WIDTH] = {
        {' ', 'X', ' ', ' ', 'X', ' ', ' ', 'X', ' ', 'F'},
        {' ', 'X', ' ', ' ', 'X', ' ', ' ', 'X', ' ', 'X'},
        {' ', ' ', ' ', 'X', ' ', 'X', ' ', ' ', ' ', ' '},
        {'X', 'X', ' ', 'X', ' ', 'X', ' ', 'X', 'X', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', ' '},
        {' ', 'X', 'X', 'X', 'X', 'X', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', ' ', ' '},
        {'X', ' ', 'X', ' ', 'X', ' ', ' ', ' ', ' ', ' '}
    };

    char level3[HEIGHT][WIDTH] = {
        {' ', 'X', ' ', 'X', ' ', 'X', ' ', 'X', ' ', 'F'},
        {' ', 'X', ' ', 'X', ' ', 'X', ' ', 'X', ' ', 'X'},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'X', 'X', 'X', 'X', ' ', 'X', 'X', 'X', 'X', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', 'X', 'X', 'X', 'X', 'X', 'X', 'X', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'X', ' ', 'X', ' ', 'X', ' ', 'X', ' ', 'X', ' '}
    };

    char (*src)[WIDTH] =
        (level == 1) ? level1 :
        (level == 2) ? level2 :
        level3;

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            map[y][x] = src[y][x];
            obstacles[y][x] = nullptr;
        }
    }

    obstacles[2][3] = new TimeObstacle();
    obstacles[4][5] = new ResetObstacle();
    obstacles[6][8] = new CounterObstacle();
}

void Board::draw(int frogX, int frogY) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (x == frogX && y == frogY) {
                std::cout << " Z ";
            }
            else if (obstacles[y][x]) {
                std::cout << " " << obstacles[y][x]->symbol() << " ";
            }
            else {
                if (map[y][x] == ' ')
                    std::cout << " . ";
                else
                    std::cout << " " << map[y][x] << " ";
            }
        }
        std::cout << '\n';
    }
}
