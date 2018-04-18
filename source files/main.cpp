#include <QApplication>
#include "gra.h"
#include "menuglowne.h"

Gra * gra;      // globalny obiekt  gra
MenuGlowne * menuGlowne;    // globalny obiekt menuglowne

int main(int argc, char *argv[])
{
    QApplication a(argc, argv); // utworzone automatycznie prze Qt do dzialania aplikacji

    menuGlowne = new MenuGlowne();  // utworzenie nowego obiektu menuglowne
    menuGlowne->show(); // wyswietlenie menu glownego

    return a.exec();    // utworzone automatycznie przez Qt do dzialania aplikacji
}
