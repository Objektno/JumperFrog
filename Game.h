#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include "Frog.h"

class Game {
public:
    Frog frog;
    Board board;

    int steps;
    int level;
    int timeLeft;
    bool running;

    Game(int level);
    void run();
    void move(char input);
    void pauseMenu();
};

#endif
