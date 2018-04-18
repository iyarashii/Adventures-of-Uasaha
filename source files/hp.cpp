#include "hp.h"
#include <QFont>
#include "gra.h"
#include "wrog.h"
#include "gracz.h"

extern Gra * gra; // slowo kluczowe extern informuje ze istnieje zewnetrzny obiekt globalny o nazwie gra


Hp::Hp(): QGraphicsTextItem()
{
    dzwiekPrzegranej = new QMediaPlayer();  // tworzenie nowego obiektu typu qmediaplayer
    dzwiekPrzegranej->setMedia(QUrl("qrc:/dzwieki/yowai no desu.mp3")); // ustawienie dzwieku odtwarzanego podczas smierci
    // wartosc poczatkowa zyc
    hp = 5;
    // wyswietl tekst
    setPlainText(QString("Lives: ") + QString::number(hp));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
    setZValue(1);   // ustawienie wartosci Z ktora odpowiada za widocznosc obiekt z wartoscia 1 znajduje sie nad obiektami z wartosciami mniejszymi

}

void Hp::zmniejszHp()
{
    if(hp == 0){    //jezeli hp gracza jest rowne 0 i zostanie wywolane zmniejszeniehp
        dzwiekPrzegranej->play();   // odtworz dzwiek przegranej
        --hp;// zmniejsz hp do -1
        gra->zapauzowane = true;    // zmien stan gry na zapauzowana
        gra->pauzuj_gra();  // zapauzuj timery gry
        gra->gracz->setOpacity(0);  // ustaw nieprzezroczystosc na 0 czyli zrob obiekt przezroczystym
        gra->hp->setPlainText(QString("                         Game over!"
                                                  "\n           press M key to return to main menu"));   // zmien tekst informujacy o ilosci hp na tekst przegranej
        gra->hp->setPos(gra->scene->width()/5,gra->scene->height()/3);  // ustaw pozycje tekstu
    }else{
        --hp;   // zmniejsz hp
    setPlainText(QString("Lives: ") + QString::number(hp));}    // wyswietl zmniejszona ilosc hp
}

int Hp::pobierzHp()
{
    return hp;  // zwroc obecna wartosc hp
}
