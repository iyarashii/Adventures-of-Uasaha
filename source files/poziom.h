#ifndef POZIOM_H
#define POZIOM_H

#include <QGraphicsTextItem>
#include "punkty.h"

class Poziom: public QGraphicsTextItem
{
public:
    Poziom();   // konstruktor
    void poziom1(); // funkcja odpowiadajaca za wyswietlenie inf na temat poziomu 1
    void zanik();   // funkcja odpowiadajca za znikniecie info na temat poziomu
    void boss1();   // funkcja odp za napis podczas walki z bossem nr 1
    void poziom2(); // funkcja odp za napis poziom 2
    void boss2();   // funkcja odp za napis podczas walki z bossem nr 2
    void koniec();  // funkcja odp za inf o ukonczeniu gry
};

#endif // POZIOM_H
