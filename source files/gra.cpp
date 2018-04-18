#include "gra.h"
#include <QTimer>
#include <QBrush>
#include <QImage>
#include <QIcon>

Gra::Gra()
{
    // ustawiam atrybut ktory powoduje usuniecie obiektu po wywolaniu funkcji close()
    Gra::setAttribute(Qt::WA_DeleteOnClose, true);
    // tworzenie sceny
    scene = new QGraphicsScene();
    setWindowTitle("Adventures of Uasaha");;
    setWindowIcon(QIcon(":/grafika/uasaha_ikonka.png"));
    scene->setSceneRect(0,0,800,900);
    setBackgroundBrush(QBrush(QImage(":/grafika/tlo.png")));
    //ustawiamy utworzona scene jako widoczna i wylaczamy paski przesuwania
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    // ustawiamy blokade rozmiaru sceny na 800x900 pikseli
    setFixedSize(800,900);

    // tworzymy nowy obiekt qmediaplayer i przypisujemy mu plik dzwiekowy
    zwyciestwo = new QMediaPlayer();
    zwyciestwo->setMedia(QUrl("qrc:/dzwieki/sorewa_short.mp3"));
    //tworzymy gracza
    gracz = new Gracz();
    //ustawiamy pozycje gracza na scenie
    gracz->setPos(scene->width()/2 - gracz->pixmap().width()/2, scene->height() - gracz->pixmap().height());

    //dodajemy obiekt gracz do sceny
    scene->addItem(gracz);
    //ustalamy aby gracz przechwytywal sygnaly z klawiatury
    gracz->grabKeyboard();

    // tworzymy punkty i hp oraz dodajemy je do sceny w lewym gornym  rogu
    punkty = new Punkty();
    scene->addItem(punkty);
    hp = new Hp();
    hp->setPos(hp->x(),hp->y()+25);
    scene->addItem(hp);

    // tworzymy i dodajemy do sceny niewidoczne na ekranie obiekty spawner i poziom ktore sluza do dodawania innych obiektow do sceny
    spawner = new Spawner();
    poziom = new Poziom();
    scene->addItem(poziom);
    scene->addItem(spawner);
    // wykonujemy funkcje poziom1 ktora wyswietla napis poziom 1
    poziom->poziom1();
    // tworzymy obiekty wszystkich timerow zadeklarowanych w pliku naglowkowym
    timer = new QTimer();
    timerBoss = new QTimer();
    timerBoss->setSingleShot(true); // ustawiamy aby dany timer wykonywal funkcje z przypisanego mu slotu tylko raz
    zanikPoziomu = new QTimer();
    zanikPoziomu->setSingleShot(true);
    wrogieStrzaly = new QTimer();
    ruchPociskow = new QTimer();
    ruchWrogow = new QTimer();
    ruchBossow = new QTimer();
    ruchPociskowGracza = new QTimer();

    // polaczenie slotu despawnNapis obiektu spawner z sygnalem timout timera zanikpoziomu
    QObject::connect(zanikPoziomu, SIGNAL(timeout()),spawner,SLOT(despawnNapis()));
    //polaczenie slotu spawn z obiektu spawner z sygnalem timout timera timer
    QObject::connect(timer,SIGNAL(timeout()),spawner,SLOT(spawn()));

    ruchPociskowGracza->start(1);   // uruchomienie timera ruchpociskowgracza z opoznieniem 1ms
    zanikPoziomu->start(1000);  // uruchomienie timera zanikpoziomu z opoznieniem 1s
    // inicjalizacja zmiennych zawierajacych opoznienie dla poszczegolnych timerow
    timerDelay = 700;
    ruchWrogowDelay = 3;
    wrogieStrzalyDelay = 900;
    ruchPociskowDelay = 2;
    ruchBossowDelay = 2;
    //uruchomienie timerow z ustalonymi wyzej opoznieniami
    timer->start(timerDelay);
    ruchWrogow->start(ruchWrogowDelay);
    ruchPociskow->start(ruchPociskowDelay);


    /*  bgm
    QMediaPlayer * muzyka = new QMediaPlayer();
    muzyka->setMedia(QUrl("qrc:/dzwieki/test.mp3"));
    muzyka->play();
*/


}

void Gra::pauzuj_gra()  // funkcja sprawdzajaca czy timery sa aktywne jesli tak to zatrzymuje wszyskie jesli nie to startuje je
{                       // z odpowiednim delayem
    if(ruchPociskow->isActive()){
        timer->stop();
        ruchWrogow->stop();
        ruchPociskow->stop();
        wrogieStrzaly->stop();
        gracz->timerStrzal->stop();
        ruchBossow->stop();
        ruchPociskowGracza->stop();
    } else {
        timer->start(timerDelay);
        ruchWrogow->start(ruchWrogowDelay);
        ruchPociskow->start(ruchPociskowDelay);
        wrogieStrzaly->start(wrogieStrzalyDelay);
        ruchBossow->start(ruchBossowDelay);
        ruchPociskowGracza->start(1);
    }
}

void Gra::boss1()   //funkcja spawnuje bossa oraz uruchamia timer ruchbossow oraz zatrzymuje timer spawnu zwyklych przeciwnikow
{                   // nastepnie wyswietla napis z nazwa i numerem bossa ktory znika po 1s
    ruchBossow->start(ruchBossowDelay);
    timer->stop();
    timer->disconnect();
    scene->addItem(poziom);
    poziom->boss1();
    zanikPoziomu->start(1000);
    connect(timerBoss,SIGNAL(timeout()),spawner,SLOT(spawnBoss1()));
    timerBoss->start(1000);
}

void Gra::poziom2()
{
    // funkcja zmienia zatrzymuje timer ruchbossow nastepnie zmienia predkosc ruchu wrogow oraz dodaje wrogow strzelajacych i wyswietla napisa poziom2
    ruchBossow->stop();
    ruchWrogow->stop();
    ruchWrogowDelay = 3;
    wrogieStrzalyDelay = 1000;
    ruchPociskow->start(ruchPociskowDelay);
    ruchWrogow->start(ruchWrogowDelay);
    wrogieStrzaly->start(wrogieStrzalyDelay);
    scene->addItem(poziom);
    poziom->poziom2();
    zanikPoziomu->start(1000);
    connect(timer,SIGNAL(timeout()),spawner,SLOT(spawn2()));
    timer->start(1000);
}

void Gra::boss2()   // funkcja zmienia predkosc pociskow oraz spawnuje 2giego bossa i wyswietla jego info
{
    ruchPociskowDelay = 3;
    ruchBossowDelay = 3;
    ruchBossow->start(ruchBossowDelay);
    timer->stop();
    timer->disconnect();
    timerBoss->disconnect();
    scene->addItem(poziom);
    poziom->boss2();
    zanikPoziomu->start(1000);
    connect(timerBoss,SIGNAL(timeout()),spawner,SLOT(spawnBoss2()));
    timerBoss->start(1000);
    ruchPociskow->start(ruchPociskowDelay);
}

void Gra::koniec()  //funkcja odtwarza dzwiek wygranej zmienia wartosc zmiennej bool koniecgry na prawde oraz pauzuje stan gry i wyswietla informajce o ukonczeniu gry
{
    zwyciestwo->play();
    koniecGry = true;
    pauzuj_gra();
    zapauzowane = true;
    scene->addItem(poziom);
    poziom->koniec();

}







