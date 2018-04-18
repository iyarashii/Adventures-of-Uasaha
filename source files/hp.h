#ifndef HP_H
#define HP_H


#include <QGraphicsTextItem>
#include <QMediaPlayer>

class Hp: public QGraphicsTextItem  // dziedziczymy z klasy z operatorem widocznosci public
{
public:
    Hp();   // konstruktor
    void zmniejszHp();  // funkcja zmniejszajaca wartosc prywatnej zmiennej hp oraz sprawdzajaca czy hp spadlo ponizej 0 wtedy informuje o przegranej
    int pobierzHp();    // funkcja pobiera wartosc obecnego hp
private:
    int hp; // prywatne pole/zmienna zawierajaca obecna ilosc zycia gracza
    QMediaPlayer * dzwiekPrzegranej; // prywatny wskaznik do dzwieku przegranej
};

#endif // HP_H
