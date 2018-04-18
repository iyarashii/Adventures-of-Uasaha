#ifndef MILLIONCHEERI_H
#define MILLIONCHEERI_H

#include "boss.h"

class MillionCheeri : public Boss   // dziedziczymy z klasy boss z op_wid public
{
    Q_OBJECT    //makro potrzebne do sygn i slot
public:
    MillionCheeri();    // konstruktor
public slots:
        void ruch();    // funkcja odpowiadajaca za ruch bossa
        void strzal();  // funkcja odpowiadajaca za strzelanie bossa
private:
    bool prawo = false; // prywatna zmienna pomocnicza pozwalajaca na zmiane kierunku ruchu

};

#endif // MILLIONCHEERI_H
