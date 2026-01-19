#pragma once
#include "Prepreka.h"

class MinusVrijeme : public Prepreka {
public:
    void aktiviraj(int& vrijeme, int& x, int& y, int& koraci) override;
    char simbol() override;
};

class PovratakNaPocetak : public Prepreka {
public:
    void aktiviraj(int& vrijeme, int& x, int& y, int& koraci) override;
    char simbol() override;
};

class PlusKoraci : public Prepreka {
public:
    void aktiviraj(int& vrijeme, int& x, int& y, int& koraci) override;
    char simbol() override;
};
