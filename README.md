# Jumper Frog

Jumper Frog je konzolna igra napisana u C++ u kojoj igrač upravlja žabom kroz labirint prepreka do cilja.

---

## Kako pokrenuti projekt

1. Otvoriti projekt u Visual Studio Code
2. Provjeriti da je instaliran C++ compiler (MinGW / g++)
3. Kompajlirati projekt naredbom:

g++ *.cpp -o JumperFrog

4. Pokrenuti igru:

JumperFrog.exe

---

## Kontrole u igri

W - pomak gore  
A - pomak lijevo  
S - pomak dolje  
D - pomak desno  
ESC - pauza (Resume / Exit)

---

## Značenje simbola u igri

Z - Žaba (igrač)  
. - Prohodno polje  
X - Zid (neprohodno)  
F - Cilj (finish)

A - Prepreka: oduzima 50 sekundi  
B - Prepreka: vraća žabu na početak  
C - Prepreka: resetira brojač koraka  

---

## Ovisnosti

- Standardna C++ biblioteka
- conio.h (za unos tipki u konzoli, Windows)

---

## Mogući problemi i rješenja

- Ako program treperi:
  - To je normalno ponašanje konzolnih aplikacija zbog ponovnog iscrtavanja ekrana.

- Ako compiler ne prepoznaje conio.h:
  - Projekt je namijenjen za Windows okruženje.

---

## Autor

Projekt izrađen za kolegij Objektno orijentirano programiranje.
