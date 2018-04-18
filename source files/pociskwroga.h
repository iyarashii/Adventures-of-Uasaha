#ifndef POCISKWROGA_H
#define POCISKWROGA_H

#include "pocisk.h"

class PociskWroga : public Pocisk
{
    Q_OBJECT
public:
    PociskWroga();  // konstruktor
public slots:
    void move();    // funkcja odpowiadajca za ruch pocisku wrogow zasiegowych z poziomu nr 2
};

#endif // POCISKWROGA_H
