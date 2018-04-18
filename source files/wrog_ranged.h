#ifndef WROG_RANGED_H
#define WROG_RANGED_H

#include "wrog.h"

class Wrog_ranged: public Wrog
{
    Q_OBJECT
public:
    Wrog_ranged();  // konstruktor
private:
    bool prawo = false;     // zmienna pozwalajaca na zmiane kierunku ruchu
public slots:
        void move(); // funkcja odp za ruch wrogow zasiegowych
        void strzal();  // funkcja odp za strzelanie wrogow zasiegowych
};

#endif // WROG_RANGED_H
