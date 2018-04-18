#ifndef GRA_H       // straznik naglowka zabezpieczajacy przed wielokrotnym dolaczaniem do pliku
#define GRA_H       // dodawany automatycznie przez Qt przy tworzeniu nowej klasy w pliku nagłówkowym

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QMediaPlayer>
#include "gracz.h"
#include "punkty.h"
#include "hp.h"
#include "wrog.h"
#include "spawner.h"
#include "poziom.h"


class Gra: public QGraphicsView // klasa gra dziedziczy  z klasy QGraphicView z operatorem widocznosci public
{
public:
    Gra(); // konstruktor klasy gra z parametrem rodzica który przyspiesza usuwanie obiektów QObject w Qt
    QGraphicsScene * scene; // wskaznik do obiektu scene typu QGraphicsScene
    Gracz * gracz;          // wskaznik do obiektu gracz typu Gracz
    Punkty * punkty;        // wskaznik do obiektu punkty typu Punkty
    Hp * hp;
    Spawner * spawner;
    Poziom * poziom;
    QTimer * timer;         // wskaznik do obiektu timer typu QTimer
    QTimer * ruchWrogow;
    QTimer * ruchPociskow;
    QTimer * wrogieStrzaly;
    QTimer * timerBoss;
    QTimer * zanikPoziomu;
    QTimer * ruchBossow;
    QTimer * ruchPociskowGracza;
    bool zapauzowane = false; // pole typu  bool ktore informuje o stanie gry domyslnie false
    void pauzuj_gra();        // deklaracja metody pauzuj_gra ktora pauzuje/odpauzowuje wszystkie timery znajdujace sie w klasie gra
    void boss1();             // deklaracja metody boss1 ktora aktywuje walke z bossem nr 1
    void poziom2();           // deklaracja metody poziom2 ktora aktywuje poziom drugi ktory jest po walce z bossem nr 1
    void boss2();             // deklaracja metody boss2 ktora aktywuje walke z bossem nr 2
    void koniec();            // deklaracja metody koniec ktora aktywuje zakonczenie gry i informuje o tym gracza
    bool koniecGry = false;   // zmienna typu bool ktora informuje przejsciu gry
private:
    QMediaPlayer * zwyciestwo; // prywatny wskaznik do obiektu zwyciestwo typu QMediaPlayer
    int timerDelay;            // pole typu int zawierajace czas opoznienia timera timer w ms
    int ruchWrogowDelay;       // pole typu int zawierajace czas opoznienia timera ruchWrogow w ms
    int ruchPociskowDelay;
    int wrogieStrzalyDelay;
    int ruchBossowDelay;

};

#endif // GRA_H
