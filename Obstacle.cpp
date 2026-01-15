#include "Obstacle.h"
#include "Game.h"

void TimeObstacle::activate(Game& game) {
    game.timeLeft -= 50;
    if (game.timeLeft < 0)
        game.timeLeft = 0;
}

char TimeObstacle::symbol() {
    return 'A';
}

void ResetObstacle::activate(Game& game) {
    game.frog.reset();
}

char ResetObstacle::symbol() {
    return 'B';
}

void CounterObstacle::activate(Game& game) {
    game.steps = 0;
}

char CounterObstacle::symbol() {
    return 'C';
}
