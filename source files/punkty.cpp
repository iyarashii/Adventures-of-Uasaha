#include "punkty.h"
#include <QFont>
#include "gra.h"
extern Gra * gra;

Punkty::Punkty(): QGraphicsTextItem()
{
    // wartosc poczatkowa punktow = 0
    punkty = 0;
    // wyswietl tekst
    setPlainText(QString("Points: ") + QString::number(punkty));
    setDefaultTextColor(Qt::green);
    setFont(QFont("times",16));
    setZValue(1);

}

void Punkty::wzrostPkt()
{
    ++punkty; //    preinkrementacja punktow
    setPlainText(QString("Points: ") + QString::number(punkty)); // wyswietl zwiekszona ilosc punktow
    if(punkty == 10){   // jezeli ilosc punktow osiagnela 10 przejscie do walki z bossem nr 1
        gra->boss1();
      }
    if(punkty == 20){   // jezeli ilosc punktow osiagnela 20 przejscie do walki z bossem nr 2
        gra->boss2();
      }
}

int Punkty::pkt()
{
    return punkty;      // zwroc obecna ilosc punktow
}
