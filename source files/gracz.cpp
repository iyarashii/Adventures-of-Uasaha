#include "gracz.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "pociskgracza.h"
#include "wrog.h"
#include <QTimer>
#include "gra.h"
#include "pauza.h"
#include "menuglowne.h"

extern Gra * gra;   // slowo kluczowe extern informuje ze istnieje zewnetrzny obiekt globalny o nazwie gra
extern MenuGlowne * menuGlowne;

Gracz::Gracz(): QGraphicsPixmapItem(){
    dzwiekPocisku = new QMediaPlayer(); // tworzenie nowego obiektu qmediaplayer
    dzwiekPocisku->setMedia(QUrl("qrc:/dzwieki/strzal_pyon.mp3"));  // przypisanie mu dzwieku strzalu
    setPixmap(QPixmap(":/grafika/uasaha.png")); // ustawienie wygladu gracza
    timerStrzal = new QTimer(); // utworzenie timerow do ruchu oraz strzalu
    timerLewo = new QTimer();
    timerPrawo = new QTimer();
}

void Gracz::keyPressEvent(QKeyEvent *event)
{
    // switch ktory sprawdza jaki klawisz zostal nacisniety i wykonuje odpowiednie operacje zaleznie od klawisza
    switch(event->key()){
        case Qt::Key_Left:          // nacisniecie strzalki w lewo powoduje sprawdzenie czy gra jest zapauzowana oraz czy jest wcisniety to reszta opercji sie nie wykonuje
            if(gra->zapauzowane) return;
            if(event->isAutoRepeat()) return;
            QObject::connect(timerLewo,SIGNAL(timeout()),this,SLOT(lewo()),Qt::UniqueConnection);  // przypiecie do slotu lewo sygnalu timeout
            timerLewo->start(2);    // uruchomienie timera z opoznieniem 2ms
            break;
        case Qt::Key_Right:
            if(gra->zapauzowane) return;    // jezeli gra jest zapauzowana nacisniecie klawisz nic nie robi
            if(event->isAutoRepeat()) return;   // jezeli klaiwsz jest przytrzymany to connect i start timera nie wykonuja sie ponownie
            QObject::connect(timerPrawo,SIGNAL(timeout()),this,SLOT(prawo()),Qt::UniqueConnection); // przypiecie do slotu prawo sygnalu timeout
            timerPrawo->start(2);   // uruchomienie timera prawo z opoznieniem 2ms
            break;
        case Qt::Key_Space:
            if(gra->zapauzowane) return;
            if(event->isAutoRepeat()) return;
            QObject::connect(timerStrzal,SIGNAL(timeout()),this,SLOT(strzal()),Qt::UniqueConnection);   // przypiecie do slotu strzal sygnalu timeout
            timerStrzal->start();   // uruchomnienie timera stzalu
            break;
        case Qt::Key_Escape:
            if((gra->hp->pobierzHp() < 0) || gra->koniecGry == true) return;    // jezeli gracz stracil cale hp lub nastapil koniec gry poprzez wygrana klawisz esc nie dziala
                if(gra->zapauzowane){   // jezeli gra jest zapauzowana to
                    gra->scene->removeItem(pauza);  // usun napis pauzy z ekranu
                    delete pauza;       // usuniecie obiektu pauza
                    gra->zapauzowane = false;   // zmien stan zapauzowania na falsz
                    gra->pauzuj_gra();  // odpauzuj timery gry

                }else{              // jezeli gra nie jest zapauzowana
                    timerLewo->stop();  // zatrzymaj timery ruchu i strzalu
                    timerPrawo->stop();
                    timerStrzal->stop();
                    gra->zapauzowane = true;    // zmien stan gry na zapauzowana
                    pauza = new Pauza();        // utworz nowy obiekt typu pauza
                    // ustal pozycje pauzy na scenie
                    pauza->setPos(pauza->x() + gra->scene->width()/2 - this->pixmap().width()*3.2, pauza->y() + gra->height()/2 - this->pixmap().height()/2);
                    gra->scene->addItem(pauza); // dodaj do sceny
                    gra->pauzuj_gra();  // zapauzuj timery gry
                    }
            break;
        case Qt::Key_M:
            if(gra->zapauzowane){   // jezeli gra jest zapauzowana
                gra->scene->clear();    // wyczysc scene ze wszystkich obiektow
                gra->close();           // zamknij widget gra ktory po zamknieciu zostanie usuniety poprzez atrybut deleteonclose
                menuGlowne->show();     // wyswietl menu glowne
            }
            break;
    }
}

void Gracz::keyReleaseEvent(QKeyEvent *event){
    switch(event->key()){   // switch sprawdzajacy ktory klawisz zostal puszczony
        case Qt::Key_Left:
            if(event->isAutoRepeat()) return;   // jezeli klawisz jest w przytrzymany nic sie nie dzieje
            timerLewo->stop();  // gdy klawisz zostanie puszczony timer sie zatrzymuje
            break;
        case Qt::Key_Right:
            if(event->isAutoRepeat()) return;
            timerPrawo->stop(); // jezeli klawisz w prawo zostanie puszczony to timeru ruchu w prawo zostaje zatrzymany
            break;
        case Qt::Key_Space:
            if(event->isAutoRepeat()) return;
            timerStrzal->stop();    // jezeli klawisz spacja zostanie puszczony to gracz przestanie strzelac
            break;
    }
}

void Gracz::strzal(){
       if (dzwiekPocisku->state() == QMediaPlayer::PlayingState) return;    // sprawdza czy dzwiek pocisku nadal sie odtwarza jezeli tak to nie mozna wystrzelic kolejnego
        PociskGracza * pocisk = new PociskGracza(); // tworzymy nowy obiekt typu pociskgracza
        pocisk->setPos(x() + pixmap().width()/2 - pocisk->pixmap().width()/2,y() - pixmap().height()/2); // ustawiamy pozycje na tuz nad srodkiem postaci gracza
        scene()->addItem(pocisk);   // dodajemy pocisk do sceny
        dzwiekPocisku->play();  // odtwarzamy dzwiek pocisku
}

void Gracz::prawo()
{
    if (pos().x() + this->pixmap().width() < scene()->width())  //jezeli prawy koniec postaci gracza jest w pozycji x mniejszej niz prawa krawdz sceny
    setPos(x()+1,y());  // przesun postac gracza o 1 piksel w prawo
}

void Gracz::lewo()
{
    if (pos().x() > 0)  // jezeli lewy koniec postaci gracza jest w pozycji x wieszej niz 0
    setPos(x()-1,y()); // przesun postac gracza o 1 piksel w lewo
}
