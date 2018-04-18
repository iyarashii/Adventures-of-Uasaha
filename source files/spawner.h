#ifndef SPAWNER_H
#define SPAWNER_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include "hpbossa.h"
#include "poziom.h"
class Spawner: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Spawner();  // konstruktor
    HpBossa * hpBossa;  // wskaznik typu hpbossa
public slots:
    void spawnBoss1();  // funkcja odp za spawn bossa nr1
    void spawn();       // funkcja odp za spawn wrogow atakujacych z bliska
    void spawn2();      // funkcja odp za spawn wrogow zasiegowych
    void despawn();     // funkcja odp za usuniecie napisu hpbossa informujacego o ilosci pozostalych hp bossa
    void despawnNapis();    // funkcja odp za zanik napisu inf o poziomie na ktorym sie znajdujemy
    void spawnBoss2();      // funkcja odp za spawn bossa nr2
};

#endif // SPAWNER_H
