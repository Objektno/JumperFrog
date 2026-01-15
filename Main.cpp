#include <iostream>
#include <conio.h>
#include "Game.h"
#include "Utils.h"

int main() {
    while (true) {
        clearScreen();

        std::cout << "        ======================\n";
        std::cout << "        |     JUMPER FROG     |\n";
        std::cout << "        ======================\n\n";

        std::cout << "        Choose level:\n\n";
        std::cout << "        [1] Level 1\n";
        std::cout << "        [2] Level 2\n";
        std::cout << "        [3] Level 3\n\n";
        std::cout << "        ESC - Exit\n";


        char c = _getch();

        if (c == 27)
            return 0;

        if (c >= '1' && c <= '3') {
            int level = c - '0';
            Game game(level);
            game.run();
        }
    }
}
