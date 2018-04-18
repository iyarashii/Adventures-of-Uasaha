#include "boss.h"
#include "gra.h"

extern Gra * gra;

Boss::Boss(): QObject(), QGraphicsPixmapItem()
{
    connect(gra->ruchBossow, SIGNAL(timeout()), this, SLOT(ruch()), Qt::UniqueConnection); // polaczenie sygnalu timeout timera ruchbossow ze slotem ruch
}

void Boss::zmniejszHp()
{
    --zycie;    //predekrementacja wartosci hp bossa
}

int Boss::pobierzHp()
{
    return zycie;   // zwracanie wartosci obecnej wartosci hp bossa
}

void Boss::ustawHp(int hp)
{
    zycie = hp;     // ustawianie parametru przekazanego do funkcji jako hp bossa
}

void Boss::ruch()
{

}

