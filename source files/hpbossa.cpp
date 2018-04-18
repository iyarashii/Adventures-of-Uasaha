#include "hpbossa.h"

HpBossa::HpBossa(int ilosc)
{
    setPlainText(QString("Boss: ") + QString::number(ilosc));   // ustaw tekst wyswietlajacy ilosc hp bossa
    setPos(700,0);  // ustaw pozycje na prawy gorny rog sceny
    setDefaultTextColor(Qt::cyan);  // ustaw kolor tekstu
    setFont(QFont("times",16));     // ustaw czcionke i jej rozmiar
    setZValue(1);   // ustaw wartosc Z na 1
    wartoscHp = ilosc;  // zapisz wartosc hp przekazana w parametrze do zmiennej
}

void HpBossa::aktualizuj()
{
    --wartoscHp;    // predekrementacja zapisanej wartosci hp
    setPlainText(QString("Boss: ") + QString::number(wartoscHp));   // wyswietlenie zmniejszonej wartosci
}

