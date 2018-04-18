#ifndef POCISKCHEERI_H
#define POCISKCHEERI_H

#include "pocisk.h"

class PociskCheeri : public Pocisk  // dziedziczymy z klasy pocisk
{
    Q_OBJECT    //makro do syg i slot
public:
    PociskCheeri(); //konstruktor
public slots:
    void move();    // funkcja odpowiadajaca za ruch  pociskow w dol
    void prawy();       // funkcja odp za ruch prawego pocisku
    void lewy();        // funkcja odp za ruch lewego pocisku

private:
    bool kierunek = false;  // prywatna zmienna pomocnicza pozwalajaca na odbijanie sie pociskow od lewej i prawej krawedzi
};

#endif // POCISKCHEERI_H
