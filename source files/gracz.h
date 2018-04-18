#ifndef GRACZ_H
#define GRACZ_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QMediaPlayer>
#include "pauza.h"

class Gracz: public QObject, public QGraphicsPixmapItem{    //dziedziczymy z klas QObject oraz QGraphicsPixmapItem z op_wid public
    Q_OBJECT    // makro potrzebne do poprawnego dzialania sygnalow i slotow obiektow QObject
public:
    Gracz();    //konstruktor
    void keyPressEvent(QKeyEvent * event);  //funkcja klasy QWidget pozwalajaca na reagowanie na wciskane klawisze z klawiatury
    void keyReleaseEvent(QKeyEvent *event); // funkcja klasy qwidget pozwalajaca na reagowanie na puszczenia klawiszy z klawiatury
    Pauza * pauza;      // wskaznik typu Pauza potrzebny do wysiwetlenia pauzy po nacisniesciu klawiwsz esc
    // wskazniki do obiektow typu QTimer
    QTimer * timerStrzal;
    QTimer * timerLewo;
    QTimer * timerPrawo;
public slots:       //funkcje bedace slotami dzialaja tak jak normalne z ta roznica ze mozna im przypinac jakis sygnal
    void strzal();
    void prawo();
    void lewo();
private:
    QMediaPlayer * dzwiekPocisku;   // prywatny wskaznik do dzwieku pocisku

};

#endif // GRACZ_H
