#ifndef RYCERZ_H
#define RYCERZ_H

#include "boss.h"

class Rycerz : public Boss
{
    Q_OBJECT
public:
    Rycerz();   // konstruktor
public slots:
    void ruch();    // funkcja odp za bossa nr 2
private:
    bool prawo = false;     // prywatna zmienna pozwalajaca na zmiane kierunku ruchu lewo prawo
    bool szarza = false;    // prywatna zmienna informujaca o stanie bossa
    bool powrot = false;    // prywatna zmienna informujaca o stanie bossa
};

#endif // RYCERZ_H
