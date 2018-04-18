#include "spawner.h"
#include "wrog.h"
#include "wrog_ranged.h"
#include <QGraphicsScene>
#include "wrog_melee.h"
#include "boss.h"
#include "millioncheeri.h"
#include "rycerz.h"
#include "gra.h"

extern Gra * gra;

Spawner::Spawner(): QGraphicsPixmapItem()
{

}

void Spawner::spawnBoss2()
{
    MillionCheeri * boss2 = new MillionCheeri();    // tworzymy nowy obiekt bossa
    hpBossa = new HpBossa(boss2->pobierzHp());      // tworzymy nowy obiekt hpbossa z parametrem hp obecnego bossa
    scene()->addItem(boss2);                        // dodajemy do sceny bossa
    scene()->addItem(hpBossa);                      // dodajemy do sceny jego hp
}

void Spawner::spawn()
{
    // tworzenie wroga
    Wrog_melee * wrog = new Wrog_melee();
    scene()->addItem(wrog);
}

void Spawner::spawn2()
{
    // tworzenie wroga zasiegowego
    Wrog_ranged * wrog = new Wrog_ranged();
    scene()->addItem(wrog);
}

void Spawner::despawn()
{
    // usuwanie napisu z hp bossa
    scene()->removeItem(hpBossa);
    delete hpBossa;
}

void Spawner::despawnNapis()
{
    // ukrycie napisu z nazwa obecnego poziomu
    gra->poziom->zanik();
}

void Spawner::spawnBoss1()
{
    // tworzenie bossa nr 1
    Rycerz * boss1 = new Rycerz();
    hpBossa = new HpBossa(boss1->pobierzHp());
    scene()->addItem(boss1);
    scene()->addItem(hpBossa);
}
