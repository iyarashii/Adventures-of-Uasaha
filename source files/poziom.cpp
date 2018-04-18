#include "poziom.h"
#include <QGraphicsScene>
#include<QTime>


Poziom::Poziom()
{
    setDefaultTextColor(Qt::green); // ustawiamy kolor tekstu
    setFont(QFont("Arial",20));     // ustawiamy czcionke i rozmiar
    setZValue(1);   // wartosc Z = 1
}

void Poziom::poziom1()
{
    setPlainText(QString("LEVEL 1"));  // ustawiamy napis
    setPos(350, scene()->height()/2);   // ustawiamy pozycje
}

void Poziom::zanik()
{
    scene()->removeItem(this);      // usuwamy napis ze sceny
}

void Poziom::boss1()
{
    setPlainText(QString("BOSS no 1: Bone Doll"));
    setPos(300, scene()->height()/2);
}

void Poziom::poziom2()
{
    setPlainText(QString("LEVEL 2"));
    setPos(350, scene()->height()/2);
}

void Poziom::boss2()
{
    setPlainText(QString("Boss no 2: Million Cheeri"));
    setPos(300, scene()->height()/2);
}

void Poziom::koniec()
{
    setPlainText(QString("Congratulations you have completed this game!\nPress M to return to main menu"));
    setPos(150, scene()->height()/2);
}

