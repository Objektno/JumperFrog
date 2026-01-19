#pragma once

class Prepreka {
public:
    virtual void aktiviraj(int& vrijeme, int& x, int& y, int& koraci) = 0;
    virtual char simbol() = 0;
    virtual ~Prepreka() {}
};
