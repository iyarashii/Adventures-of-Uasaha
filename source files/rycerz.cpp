#include "rycerz.h"
#include "gra.h"
#include "spawner.h"
#include "pociskgracza.h"
#include "gracz.h"

extern Gra * gra;

Rycerz::Rycerz()
{
    ustawHp(10);     //ustawienie hp przy pomocy funkcji klasy boss
    setPixmap(QPixmap(":/grafika/boss2.PNG"));  // ustawienei wygladu bossa nr1
    setPos(1000, 0);    // ustawienie pozycji poza ekranem dlatego boss wjezdza z prawej strony
}

void Rycerz::ruch()
{
    //pocisk po zderzeniu z bossem znika i zabiera bossowi hp tylko gdy boss jest w stanie powrotu
      QList<QGraphicsItem *> przedmioty_kolidujace = collidingItems();
      for(int i = 0, n = przedmioty_kolidujace.size(); i < n; ++i){
          if (typeid(*(przedmioty_kolidujace[i])) == typeid(PociskGracza)){
              //usuwamy  pocisk
              scene()->removeItem(przedmioty_kolidujace[i]);
              // zwalniamy pamiec usuwajac obiekty
              delete przedmioty_kolidujace[i];
              if(powrot == true){       // jezeli boss cofa sie do gory to traci hp w przeciwnym wypadku pociski nic mu nie robia tylko znikaja po zderzeniu
                    zmniejszHp();
                    gra->spawner->hpBossa->aktualizuj();}
              if(pobierzHp() == 0){     // gdy boss padnie to usuwamy go ze sceny i rozpoczyna sie poziom nr 2
                  scene()->removeItem(this);
                  delete this;
                  gra->spawner->despawn();
                  gra->poziom2();
                }
              return;
           }
          if (typeid(*(przedmioty_kolidujace[i])) == typeid(Gracz) && !powrot){ // jezeli boss zetknie sie z graczem i nie bylo to w momencie gdy wracal do gory to gracz traci hp
               //zmniejszamy hp
               gra->hp->zmniejszHp();
               powrot = true;
           }
      }
      if(powrot == true){   // jezeli powrot jest true to boss wraca powoli na gore gdy wroci na gore to powrot = false
        setPos(x(),y()-1);  // predkosc powrotu bossa
        if(pos().y() <= 0) powrot = false;
        return;
      }

      //jezeli lewy kraniec bossa lub prawy  bedzie mial ta sama pozycje x co gracz to boss zacznie szarzowac
      if( ((pos().x() + this->pixmap().width()) > gra->gracz->pos().x() && (pos().x() + this->pixmap().width()) < gra->gracz->pos().x() + gra->gracz->pixmap().width()) || (pos().x() >= gra->gracz->pos().x() && pos().x() < gra->gracz->pos().x() + gra->gracz->pixmap().width())){
        szarza = true;
      }

        if(szarza == true)  // boss szarzuje az zetknie sie z dolnym koncem sceny lub graczem wtedy nastepuje powrot
            {
            if(pos().y() + pixmap().height() >= scene()->height()){
                szarza = false;
                powrot = true;
                return;
                }
            setPos(x(),y()+3); // predkosc z jaka szarzuje boss
            }
        else{           // gdy boss nie szarzuje to porusza sie w lewo i prawo szukajac gracza
                if(prawo == false)
                {
                     if (pos().x() > 0){
                    setPos(x()-1,y());} // ruch w lewo
                else {
                    prawo = true;}
                    }
                else {if (pos().x() + this->pixmap().width() < scene()->width()){
                setPos(x()+1,y()); // ruch w prawo
                 }else{
                     prawo = false;}
                }
        }
}
