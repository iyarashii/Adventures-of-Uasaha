#include "wrog_melee.h"
#include "wrog.h"
#include "gra.h"
#include "gracz.h"


extern Gra * gra;

Wrog_melee::Wrog_melee()
{
   //rysujemy wroga
   setPixmap(QPixmap(":grafika/przeciwnik.png"));
}

void Wrog_melee::move()
{
  //wrog przy dotknieciu gracza zabiera hp
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
  // wrog leci w dol
    setPos(x(),y()+2);
    if (pos().y() > scene()->height()){
        scene()->removeItem(this);
        delete this;


   }
}
