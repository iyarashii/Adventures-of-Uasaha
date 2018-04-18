#include "wrog.h"
#include "gra.h"

extern Gra * gra;

Wrog::Wrog(): QObject(), QGraphicsPixmapItem()
{
    //ustawiamy losowa pozycje spawnu wroga
    qreal losowa = rand() % 700;
    setPos(losowa, 0);
    connect(gra->ruchWrogow, SIGNAL(timeout()), this, SLOT(move()), Qt::UniqueConnection);
}

void Wrog::move()
{

}
