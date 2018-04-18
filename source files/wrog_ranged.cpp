#include "wrog_ranged.h"
#include "wrog.h"
#include "gra.h"
#include "gracz.h"
#include "pociskwroga.h"

extern Gra * gra;

Wrog_ranged::Wrog_ranged()
{
    setPixmap(QPixmap(":/grafika/wrog_zasiegowy.PNG"));
    connect(gra->wrogieStrzaly, SIGNAL(timeout()), this, SLOT(strzal()), Qt::UniqueConnection);
}

void Wrog_ranged::move()
{
    //wrog przy dotknieciu gracza zabiera hp
    QList<QGraphicsItem *> zderzenie = collidingItems();
     for(int i = 0, n = zderzenie.size(); i < n; ++i){
        if(typeid(*(zderzenie[i])) == typeid(Gracz)){
             //zmniejszamy hp
             gra->hp->zmniejszHp();
             scene()->removeItem(this);
             delete this;
             return;
        }
     }
     if(prawo == false)
         {
          if(pos().x() > 0){
                    setPos(x()-1,y());} // ruch w lewo
          else {setPos(x(),y() + pixmap().height()); // ruch w dol o wysokosc postaci
                    prawo = true;}
         }//ruch w lewo
     else{ if(pos().x() + this->pixmap().width() < scene()->width()){
                    setPos(x()+1,y()); // ruch w prawo
            } else {setPos(x(),y() + pixmap().height()); // ruch w dol o wysokosc postaci
                    prawo = false;}
        }
      if (pos().y() + pixmap().height() > scene()->height()){
          scene()->removeItem(this);
          delete this;
          }
}

void Wrog_ranged::strzal()
{
    PociskWroga * pocisk = new PociskWroga();
    pocisk->setPos(x() + pixmap().width()/2 - pocisk->pixmap().width()/2,y() + pixmap().height()/2);
    scene()->addItem(pocisk);
}
