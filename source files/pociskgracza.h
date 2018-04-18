#ifndef POCISKGRACZA_H
#define POCISKGRACZA_H

#include "pocisk.h"

class PociskGracza : public Pocisk
{
    Q_OBJECT
public:
    PociskGracza(); //konstruktor
public slots:
    void ruch();    // funkcja odpowiadajaca za ruch pocisku gracza
    void move();
};

#endif // POCISKGRACZA_H
