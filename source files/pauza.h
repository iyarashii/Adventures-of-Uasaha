#ifndef PAUZA_H
#define PAUZA_H

#include <QGraphicsTextItem>
#include "wrog.h"
#include "pocisk.h"



class Pauza: public QGraphicsTextItem   // dziedziczymy z klasy z op_wid public
{
    Q_OBJECT    //makro do slotow i sygnalow
public:
    Pauza(); // konstruktor
};

#endif // PAUZA_H
