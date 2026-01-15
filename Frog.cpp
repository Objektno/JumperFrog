#include "Frog.h"

Frog::Frog(int sx, int sy) {
    startX = sx;
    startY = sy;
    reset();
}

void Frog::reset() {
    x = startX;
    y = startY;
}
