#include "Game.h"
#include "Utils.h"
#include <iostream>
#include <conio.h>
#include <ctime>

Game::Game(int lvl)
    : frog(0, 0), board(lvl) {
    level = lvl;
    steps = 0;
    timeLeft = 120;
    running = true;
}

void Game::run() {
    time_t last = time(nullptr);

    while (running) {
        clearScreen();
        std::cout << "        ============================\n";
        std::cout << "        ==  JUMPER FROG - LEVEL "
            << level << "  ==\n";
        std::cout << "        ============================\n\n";



        std::cout << "Time: " << timeLeft;
        std::cout << "        Steps: " << steps << "\n\n";
        std::cout << "LEVEL\n\n";

        board.draw(frog.x, frog.y);
        std::cout << "\nLegend:\n";
        std::cout << "Z - Frog (player)\n";
        std::cout << "F - Finish\n";
        std::cout << "X - Wall (cannot pass)\n";
        std::cout << "A - Time trap (-50 seconds)\n";
        std::cout << "B - Reset trap (back to start)\n";
        std::cout << "C - Counter trap (steps reset)\n\n";

        std::cout << "Controls: W A S D - Move | ESC - Pause\n";


        std::cout << "\nESC - Pause\n";

        if (_kbhit()) {
            char c = _getch();
            if (c == 27)
                pauseMenu();
            else
                move(c);
        }

        if (time(nullptr) != last) {
            timeLeft--;
            last = time(nullptr);
        }

        if (timeLeft <= 0)
            running = false;
    }
}

void Game::move(char c) {
    int nx = frog.x;
    int ny = frog.y;
    // Ako je cilj
    if (board.map[ny][nx] == 'F') {
        running = false;
        return;
    }


    if (c == 'w') ny--;
    if (c == 's') ny++;
    if (c == 'a') nx--;
    if (c == 'd') nx++;

    if (nx < 0 || ny < 0 ||
        nx >= Board::WIDTH || ny >= Board::HEIGHT)
        return;

    // ZID – nema prolaska
    if (board.map[ny][nx] == 'X')
        return;

    frog.x = nx;
    frog.y = ny;
    steps++;

    if (board.obstacles[ny][nx])
        board.obstacles[ny][nx]->activate(*this);
}

void Game::pauseMenu() {
    clearScreen();

    std::cout << "\n\n\n";
    std::cout << "        ========================\n";
    std::cout << "        ==        PAUSED       ==\n";
    std::cout << "        ========================\n\n";

    std::cout << "        == 1 - Resume Game    ==\n";
    std::cout << "        == 2 - Exit to Menu  ==\n\n";
    std::cout << "        ========================\n";

    char c = _getch();

    if (c == '2')
        running = false;

}
