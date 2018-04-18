#include "pociskwroga.h"
#include "pocisk.h"
#include "gra.h"
#include "gracz.h"

extern Gra * gra;

PociskWroga::PociskWroga()
{
    //rysujemy pocisk
    setPixmap(QPixmap(":/grafika/light2.png"));
    //laczymy slot z sygnalem
    // connect(gra->ruchPociskow, SIGNAL(timeout()), this, SLOT(move()), Qt::UniqueConnection);
}


void PociskWroga::move()
{
  //pocisk przy dotknieciu gracza zabiera hp
  QList<QGraphicsItem *> zderzenie = collidingItems();
   for(int i = 0, n = zderzenie.size(); i < n; ++i){
      if (typeid(*(zderzenie[i])) == typeid(Gracz)){
           //zmniejszamy hp
           gra->hp->zmniejszHp();
           scene()->removeItem(this);
           delete this;
           return;
      }
   }
  // pocisk leci w dol
    setPos(x(),y()+2);
    if (pos().y() + pixmap().height() > scene()->height()){
        scene()->removeItem(this);
        delete this;


   }
}
