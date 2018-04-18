#include "pociskgracza.h"
#include "pocisk.h"
#include "wrog.h"
#include "gra.h"
#include "wrog_ranged.h"
#include "wrog_melee.h"

extern Gra * gra; // istnieje zewnetrzny obiekt globalny o nazwie gra

PociskGracza::PociskGracza()
{
    //rysujemy pocisk
    setPixmap(QPixmap(":/grafika/pocisk.png"));

    //laczymy slot z sygnalem
    connect(gra->ruchPociskowGracza, SIGNAL(timeout()), this, SLOT(ruch()), Qt::UniqueConnection);
}

void PociskGracza::ruch()
{
  //pocisk przy dotknieciu wroga niszczy go i sam tez znika
    QList<QGraphicsItem *> przedmioty_kolidujace = collidingItems();
    for(int i = 0, n = przedmioty_kolidujace.size(); i < n; ++i){
        if (typeid(*(przedmioty_kolidujace[i])) == typeid(Wrog_melee) || typeid(*(przedmioty_kolidujace[i])) == typeid(Wrog_ranged)){
            //zwiekszamy punkty
            gra->punkty->wzrostPkt();
            //usuwamy wroga i pocisk
            scene()->removeItem(przedmioty_kolidujace[i]);
            scene()->removeItem(this);
            // zwalniamy pamiec usuwajac obiekty
            delete przedmioty_kolidujace[i];
            delete this;
            return;
        }
    }
  // pocisk leci do gory jezeli wyleci poza ekran to zostaje usuniety
    setPos(x(),y()-1);
    if (pos().y() + pixmap().height() < 0){
        scene()->removeItem(this);
        delete this;
    }
}

void PociskGracza::move()
{

}
