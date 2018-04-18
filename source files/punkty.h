#ifndef PUNKTY_H
#define PUNKTY_H

#include <QGraphicsTextItem>

class Punkty: public QGraphicsTextItem
{
public:
    Punkty();   // konstruktor
    void wzrostPkt();   // funkcja odp za zwiekszenie ilosc punktow
    int pkt();  // funkcja odp za pobranie wartosic pkt
private:
    int punkty; // prywatna zmienna przechowujaca obecna wartosc pkt
};

#endif // PUNKTY_H
