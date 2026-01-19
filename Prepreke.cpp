#include "Prepreke.h"

void MinusVrijeme::aktiviraj(int& vrijeme, int&, int&, int&) {
    vrijeme -= 50;
    if (vrijeme < 0) vrijeme = 0;
}
char MinusVrijeme::simbol() { return 'T'; }

void PovratakNaPocetak::aktiviraj(int&, int& x, int& y, int&) {
    x = 0; y = 0;
}
char PovratakNaPocetak::simbol() { return 'R'; }

void PlusKoraci::aktiviraj(int&, int&, int&, int& koraci) {
    koraci += 20;
}
char PlusKoraci::simbol() { return 'K'; }
