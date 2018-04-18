#include "millioncheeri.h"
#include "gra.h"
#include "pociskcheeri.h"
#include "boss.h"
#include "spawner.h"
#include "pociskgracza.h"

extern Gra * gra;

MillionCheeri::MillionCheeri()
{
    ustawHp(10);        // ustawienie hp przy pomocy funkcji klasy boss
    setPixmap(QPixmap(":/grafika/boss1_mc.PNG"));   // ustawienie wygladu bossa nr2
    setPos(350, 0); // ustawienie pozycji spawnu na x = 350 pikseli
    connect(gra->wrogieStrzaly, SIGNAL(timeout()), this, SLOT(strzal()), Qt::UniqueConnection); // polaczenie sygnalu timeout timera wrogiestrzaly ze slotem strzal
}
void MillionCheeri::ruch()
{
    //pocisk po zderzeniu z bossem znika i zabiera bossowi hp
      QList<QGraphicsItem *> przedmioty_kolidujace = collidingItems();  // utworzenie listy przedmiotow stykajacych sie z bossem
      for(int i = 0, n = przedmioty_kolidujace.size(); i < n; ++i){ //sprawdza wszystkie stykajace sie obiekty
          if (typeid(*(przedmioty_kolidujace[i])) == typeid(PociskGracza)){ //jezeli obiektem jest pocisk gracza
              //usuwamy  pocisk
              scene()->removeItem(przedmioty_kolidujace[i]);
              // zwalniamy pamiec usuwajac obiekty
              delete przedmioty_kolidujace[i];
              zmniejszHp(); // zmniejszamy hp bossa
              gra->spawner->hpBossa->aktualizuj();  //aktualizujemy wyswietlane hp bossa
              if(pobierzHp() == 0){             // jezeli hp bossa spadlo do 0
                  scene()->removeItem(this);    // usun bossa ze sceny
                  delete this;                  // usun obiekt bossa z pamieci
                  gra->spawner->despawn();      // usun napis z hp bossa ze sceny
                  gra->koniec();    // wyswietl informacje o ukonczeniu gry
                  }
           return;
           }
      }
         if(prawo == false)         //jezeli zmienna prawo jest false to  boss rusza sie w lewo
         {
             if (pos().x() > 0){
                    setPos(x()-1,y()); // ruch w lewo
                 }
             else{              // gdy boss zetknie sie z lewo krawedzia to zmienia kierunek ruchu
                  prawo = true;}
         }
         else {
             if (pos().x() + this->pixmap().width() < scene()->width()){
                    setPos(x()+1,y()); // ruch w prawo
            }else{
                 prawo = false;}
        }
}

void MillionCheeri::strzal()    // funkcja wystrzeliwuje 3 pociski jeden leci w prawo drugi w dol trzeci w lewo
{
    PociskCheeri * pocisk1 = new PociskCheeri();        // utworz nowy pocisk
    pocisk1->setPixmap(QPixmap(":/grafika/red.png"));   // ustaw kolor pocisku na czerwony
    pocisk1->setPos(x(),y() + pixmap().height());       // ustaw pozycje pocisku na lewy dolny rog bossa
    scene()->addItem(pocisk1);                          // dodaj pocisk do sceny
    connect(gra->ruchPociskow, SIGNAL(timeout()), pocisk1, SLOT(lewy()), Qt::UniqueConnection); // podepnij do pocisku ruch w lewo
    PociskCheeri * pocisk2 = new PociskCheeri();        // utworz srodkowy pocisk
    pocisk2->setPixmap(QPixmap(":/grafika/green.png")); // ustaw zielony kolor
    pocisk2->setPos(x() + pixmap().width()/2,y() + pixmap().height());  // ustaw pozycje na srodku pod bossem
    scene()->addItem(pocisk2);                                          // dodaj pocisk do sceny
    PociskCheeri * pocisk3 = new PociskCheeri();        //utworz pocisk nr 3
    pocisk3->setPixmap(QPixmap(":/grafika/niebieski.png")); // ustaw kolor na niebieski
    pocisk3->setPos(x() + pixmap().width(),y() + pixmap().height());    // ustaw pozycje na prawy dolny rog bossa
    scene()->addItem(pocisk3);                                          // dodaj pocisk do sceny
    connect(gra->ruchPociskow, SIGNAL(timeout()), pocisk3, SLOT(prawy()), Qt::UniqueConnection);    // podepnij do pocisku ruch w prawo
}
