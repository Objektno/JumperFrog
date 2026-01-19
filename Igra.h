#pragma once
#include <ctime>

#define HEIGHT 10
#define WIDTH 15

class Igra {
private:
    char ploca[HEIGHT][WIDTH];
    int zabaX, zabaY;
    int koraci;
    int vrijeme;
    int level;
    time_t start;


    void resetiraj();

public:
    Igra();
    void ucitajLevel(int lvl);
    void ispis();
    bool pauza();
    void pokreni();
};
