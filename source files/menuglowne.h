#ifndef MENUGLOWNE_H
#define MENUGLOWNE_H

#include <QMainWindow>
#include "sterowanie.h"

namespace Ui {      // uzywamy przestrzeni nazw Ui
class MenuGlowne;
}

class MenuGlowne : public QMainWindow //dziedziczymy z klasy qmainwindow z operatorem widocznosci public
{
    Q_OBJECT    // makro potrzebne do poprawnego dzialania sygnalow i slotow obiektow QObject

public:
    explicit MenuGlowne();   //  jawny konstruktor
    ~MenuGlowne();  // destruktor

private slots:

    void on_start_clicked();        // slot ktory uruchamia gre po nacisnieciu przycisku start

    void on_wyjscie_clicked();      // slot ktory zamyka aplikacje po nacisnieciu przycisku wyjscie

    void on_opcje_clicked();        // slot ktory wyswietla sterowanie po nacisnieciu przycisku sterowanie

private:
    Ui::MenuGlowne *ui;         // prywatny wskaznik typu menuglowne
    Sterowanie *okno;           // prywatny wskaznik do okna sterowanie
};

#endif // MENUGLOWNE_H
