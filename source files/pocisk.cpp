#include "pocisk.h"
#include "gra.h"

extern Gra * gra;

Pocisk::Pocisk(): QObject(), QGraphicsPixmapItem(){

    connect(gra->ruchPociskow, SIGNAL(timeout()), this, SLOT(move()), Qt::UniqueConnection);
}


void Pocisk::move()
{

}

