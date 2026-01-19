#include "Igra.h"
#include "Utils.h"
#include <iostream>
#include <conio.h>

using namespace std;

/* ===== LEVELI ===== */

char level1[HEIGHT][WIDTH] = {
 {'.','.','T','#','.','.','.','R','#','.','.','.','.','.','F'},
 {'#','#','.','#','.','#','#','.','#','.','#','#','#','.','#'},
 {'.','.','.','.','.','.','#','.','.','T','.','.','#','.','.'},
 {'.','#','#','#','#','.','#','#','#','#','#','.','#','#','.'},
 {'.','.','.','.','#','.','.','.','R','.','#','.','.','.','.'},
 {'#','#','#','.','#','#','#','#','#','.','#','#','#','#','.'},
 {'.','.','.','.','.','.','.','.','#','.','.','.','T','#','.'},
 {'.','#','#','#','#','#','.','#','#','#','#','#','.','#','.'},
 {'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
 {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','.'}
};

char level2[HEIGHT][WIDTH] = {
 {'.','.','#','#','.','.','T','#','.','.','#','.','.','.','F'},
 {'#','.','.','#','.','#','.','#','.','#','#','.','#','.','#'},
 {'#','.','#','#','.','#','.','.','.','.','.','.','.','#','.'},
 {'.','.','.','.','.','#','#','#','#','#','.','.','#','#','.'},
 {'.','#','#','#','.','.','R','.','.','#','.','#','#','.','.'},
 {'.','.','.','#','.','#','#','#','.','#','.','.','.','T','.'},
 {'#','#','.','#','.','.','.','#','.','#','#','#','#','#','.'},
 {'.','.','.','.','.','#','.','.','.','.','.','.','.','#','.'},
 {'.','#','#','#','.','#','#','#','#','#','#','#','.','#','.'},
 {'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'}
};

char level3[HEIGHT][WIDTH] = {
 {'.','#','#','#','.','.','T','.','#','#','#','.','.','.','F'},
 {'.','.','.','#','.','#','#','.','.','.','#','.','#','#','#'},
 {'#','#','.','#','.','.','.','.','#','.','.','T','.','.','.'},
 {'.','#','.','#','#','#','#','.','#','#','#','#','#','.','#'},
 {'.','#','.','.','.','.','#','.','.','R','.','.','#','.','.'},
 {'.','#','#','#','#','.','#','#','#','#','#','.','#','#','.'},
 {'.','.','.','.','#','.','.','.','T','.','#','.','.','.','.'},
 {'#','#','#','.','#','#','#','#','#','.','#','#','#','#','.'},
 {'.','.','.','.','.','.','.','.','#','.','.','.','.','.','.'},
 {'#','#','#','#','#','#','#','.','#','#','#','#','#','#','.'}
};

/* ===== IGRA ===== */

Igra::Igra() {
    koraci = 0;
    vrijeme = 120;
    level = 1;
    zabaX = 0;
    zabaY = 0;
    start = time(0);
}

void Igra::resetiraj() {
    zabaX = 0;
    zabaY = 0;
    koraci = 0;
    vrijeme = 120;
    start = time(0);
}

void Igra::ucitajLevel(int lvl) {
    level = lvl;
    char (*src)[WIDTH] = nullptr;

    if (lvl == 1) src = level1;
    else if (lvl == 2) src = level2;
    else if (lvl == 3) src = level3;
    else src = level1;

    for (int i = 0; i < HEIGHT; i++)
        for (int j = 0; j < WIDTH; j++)
            ploca[i][j] = src[i][j];

    // ===== PREPREKE =====
    auto staviAkoPrazno = [&](int x, int y, char znak) {
        if (x >= 0 && x < HEIGHT && y >= 0 && y < WIDTH) {
            if (ploca[x][y] == ' ') ploca[x][y] = znak;
        }
        };

    if (lvl == 1) {
        staviAkoPrazno(2, 3, 'T');
        staviAkoPrazno(4, 12, 'R');
    }
    else if (lvl == 2) {
        staviAkoPrazno(1, 2, 'T');
        staviAkoPrazno(6, 4, 'R');
    }
    else if (lvl == 3) {
        staviAkoPrazno(2, 10, 'T');
        staviAkoPrazno(8, 1, 'R');
    }

    resetiraj();
}

void Igra::ispis() {
    clearScreen();

    cout << "   ==== JUMPER FROG ====\n";
    cout << "   Level: " << level
        << "   Vrijeme: " << vrijeme
        << "   Koraci: " << koraci << "\n\n";

    for (int i = 0; i < HEIGHT; i++) {
        cout << "   ";
        for (int j = 0; j < WIDTH; j++) {

            if (i == zabaX && j == zabaY) {
                cout << 'Z' << ' ';
                continue;
            }

            char c = ploca[i][j];
            if (c == ' ') c = '.';

            cout << c << ' ';
        }
        cout << '\n';
    }

    cout << "\n   LEGENDA:\n";
    cout << "   Z - Zaba\n";
    cout << "   . - Polje za kretanje\n";
    cout << "   # - Zid (blokada)\n";
    cout << "   T - -50 sekundi (kazna)\n";
    cout << "   R - Povratak na pocetak (kazna)\n";
    cout << "   F - Cilj\n";
    cout << "   W A S D - Kretanje | ESC - Pauza\n";
}

bool Igra::pauza() {
    while (true) {
        clearScreen();
        cout << "   ==== PAUZA ====\n";
        cout << "   1 - Nastavi\n";
        cout << "   2 - Reset level\n";
        cout << "   3 - Izlaz u izbornik\n";

        char izbor = _getch();

        if (izbor == '1') return true;
        if (izbor == '2') { resetiraj(); return true; }
        if (izbor == '3') return false;
    }
}

void Igra::pokreni() {
    while (true) {
        vrijeme = 120 - (int)difftime(time(0), start);

        if (vrijeme <= 0) {
            clearScreen();
            cout << "\n   Vrijeme je isteklo! (Reset level)\n";
            cout << "   Pritisni bilo koju tipku...\n";
            _getch();
            resetiraj();
            continue;
        }

        ispis();

        // Pobjeda
        if (ploca[zabaX][zabaY] == 'F') {
            clearScreen();
            cout << "\n   POBJEDA! Bravo!\n";
            cout << "   Pritisni bilo koju tipku...\n";
            _getch();
            return;
        }

        char t = _getch();

        // Pauza
        if (t == 27) {
            bool nastavi = pauza();
            if (!nastavi) return;
            continue;
        }

        int nx = zabaX, ny = zabaY;
        if (t == 'w' || t == 'W') nx--;
        if (t == 's' || t == 'S') nx++;
        if (t == 'a' || t == 'A') ny--;
        if (t == 'd' || t == 'D') ny++;

        if (nx < 0 || nx >= HEIGHT || ny < 0 || ny >= WIDTH) continue;

        // zid
        if (ploca[nx][ny] == '#') continue;

        // pomak
        zabaX = nx;
        zabaY = ny;
        koraci++;

        // ===== AKTIVACIJA PREPREKA =====
        if (ploca[zabaX][zabaY] == 'T') {
            vrijeme -= 50;
            if (vrijeme < 0) vrijeme = 0;
        }
        else if (ploca[zabaX][zabaY] == 'R') {
            zabaX = 0;
            zabaY = 0;
        }
    }
}
