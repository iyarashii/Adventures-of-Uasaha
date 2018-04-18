#include "pociskcheeri.h"
#include "pocisk.h"
#include "gra.h"
#include "gracz.h"

extern Gra * gra;

PociskCheeri::PociskCheeri()
{

}

void PociskCheeri::move()
{
    //pocisk przy dotknieciu gracza zabiera hp
    QList<QGraphicsItem *> zderzenie = collidingItems();
     for(int i = 0, n = zderzenie.size(); i < n; ++i){
        if (typeid(*(zderzenie[i])) == typeid(Gracz)){
             //zmniejszamy hp gracza przy zderzeniu
             gra->hp->zmniejszHp();
             scene()->removeItem(this);
             delete this;
             return;
        }
     }
    // pocisk leci w dol
      setPos(x(),y()+1);
      if (pos().y() + pixmap().height() > scene()->height()){
          scene()->removeItem(this);
          delete this;
        }
}

void PociskCheeri::prawy()
{
    // pocisk leci w dol odbijajac sie od lewej i prawej krawedzi okna gry
     if(kierunek == false){
            if(pos().x() + this->pixmap().width() < scene()->width()){
                setPos(x()+1,y());
                }
            else{ kierunek = true;
                setPos(x()-1,y());}

     }
     else{
            if(pos().x() > 0){
                setPos(x()-1,y());
            }else {
                kierunek = false;
                setPos(x()+1,y());
            }
        }
}

void PociskCheeri::lewy()
{
    // pocisk leci w dol odbijajac sie od lewej i prawej krawedzi okna gry
     if(kierunek == false){
            if(pos().x() > 0){
                setPos(x()-1,y());
                }
            else{ kierunek = true;
                setPos(x()+1,y());}

     }
     else{
            if(pos().x() + this->pixmap().width() < scene()->width()){
                setPos(x()+1,y());
            }else {
                kierunek = false;
                setPos(x()-1,y());
            }
        }
}

