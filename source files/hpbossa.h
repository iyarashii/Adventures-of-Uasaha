#ifndef HPBOSSA_H
#define HPBOSSA_H

#include <QGraphicsTextItem>
#include <QFont>

class HpBossa: public QGraphicsTextItem // dziedziczymy z klasy qgraphicstextitem z operatorem widocznosci public
{
public:
    HpBossa(int ilosc); //konstruktor z parametrem pobirajacym ilosc hp bossa
    void aktualizuj();  // funkcja aktualizujaca wyswietlana ilosc hp w prawym gornym rogu
    int wartoscHp;  // zmienna do ktorej zapisujemy ilosc pobrana parametrem konstruktora
};

#endif // HPBOSSA_H
