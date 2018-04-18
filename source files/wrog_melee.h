#ifndef WROG_MELEE_H
#define WROG_MELEE_H

#include "wrog.h"

class Wrog_melee: public Wrog
{
    Q_OBJECT
public:
    Wrog_melee();   // konstruktor
public slots:
    void move();    // funkcja odpowiadajaca za ruch wroga
};

#endif // WROG_MELEE_H
