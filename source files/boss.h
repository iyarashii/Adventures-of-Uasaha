#ifndef BOSS_H
#define BOSS_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>
#include <QList>
#include "hpbossa.h"

class Boss: public QObject, public QGraphicsPixmapItem //dziedziczymy z klas QObject oraz QGraphicsPixmapItem z op_wid public
{
    Q_OBJECT    // makro potrzebne do poprawnego dzialania sygnalow i slotow obiektow QObject
public:
    Boss();     // konstruktor
    void zmniejszHp(); // deklaracja metody zmniejszajacej wartosc hp bossa
    int pobierzHp();   // deklaracja metody pobierajacej obecna wartosc hp bossa
    void ustawHp(int); // deklaracja metody ktora ustala wartosc hp rowna parametrowi typu int
public slots:
       virtual void ruch() = 0;    // funkcja czysto abstrakcyjna
private:
    int zycie;    // prywatne pole przechowujace wartosc hp
};

#endif // BOSS_H
