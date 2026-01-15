#ifndef OBSTACLE_H
#define OBSTACLE_H

class Game;

class Obstacle {
public:
    virtual void activate(Game& game) = 0;
    virtual char symbol() = 0;
    virtual ~Obstacle() {}
};

class TimeObstacle : public Obstacle {
public:
    void activate(Game& game);
    char symbol();
};

class ResetObstacle : public Obstacle {
public:
    void activate(Game& game);
    char symbol();
};

class CounterObstacle : public Obstacle {
public:
    void activate(Game& game);
    char symbol();
};

#endif
