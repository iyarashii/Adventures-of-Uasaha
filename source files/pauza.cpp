#include "pauza.h"
#include <QFont>
#include "gra.h"
#include "wrog.h"
#include "pocisk.h"
//#include <QTimer>

Pauza::Pauza(): QGraphicsTextItem()
{
    setPlainText(QString("                                  PAUSE\n            press M key to return to main menu")); // ustaw tekst pauzy
    setDefaultTextColor(Qt::blue);      // ustaw kolor tekstu
    setFont(QFont("times",20));         // ustaw czcionke i rozmiar
    setZValue(1);   // ustaw wartosc Z na 1
}


