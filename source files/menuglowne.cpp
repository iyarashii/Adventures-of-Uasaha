#include "menuglowne.h"
#include "ui_menuglowne.h"
#include "gra.h"

extern Gra * gra;
extern MenuGlowne * menuGlowne;

MenuGlowne::MenuGlowne() :
    QMainWindow(),
    ui(new Ui::MenuGlowne)
{
    ui->setupUi(this);  // ustawienie interfejsu uzytkownika
    QPixmap tlo(":/grafika/tlo_menu.png");  // ustawienie  grafiki tla menu glownego
    tlo = tlo.scaled(this->size(), Qt::IgnoreAspectRatio);  // ustawienie rozmiaru tla
    QPalette palette;   // ustawienie palety
    palette.setBrush(QPalette::Background, tlo);    //ustawienie pedzla z obrazem tla
    this->setPalette(palette);  // ustawienie powyzszej palety do rysowania tla
}

MenuGlowne::~MenuGlowne()
{
    delete ui;  // usuniecie interfejsu
}





void MenuGlowne::on_start_clicked()
{
    menuGlowne->hide(); // ukrycie menu glownego
    gra = new Gra();    // utworzenie nowego obiektu typu gra
    gra->show();        // pokazanie gry na ekran

}

void MenuGlowne::on_wyjscie_clicked()
{
    QApplication::quit();   // wyjscie z aplikacji
}

void MenuGlowne::on_opcje_clicked()
{
    okno = new Sterowanie(this);    // utworzenie nowego obiektu typu sterowanie z menuglowne ustawionym jako rodzic
    okno->show();               // wyswietlenie okna zawierajacego instrukcje sterowania gry
}
