#include <iostream>
#include <conio.h>
#include "Igra.h"
#include "Utils.h"

using namespace std;

int main() {
    Igra igra;

    while (true) {
        clearScreen();
        cout << "\n   ==== JUMPER FROG ====\n";
        cout << "   1 - Level 1\n";
        cout << "   2 - Level 2\n";
        cout << "   3 - Level 3\n";
        cout << "   0 - Izlaz\n";

        char izbor = _getch();

        if (izbor == '0') break;
        if (izbor == '1') { igra.ucitajLevel(1); igra.pokreni(); }
        if (izbor == '2') { igra.ucitajLevel(2); igra.pokreni(); }
        if (izbor == '3') { igra.ucitajLevel(3); igra.pokreni(); }
    }

    return 0;
}
