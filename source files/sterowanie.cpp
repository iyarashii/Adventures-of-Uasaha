#include "sterowanie.h"
#include "ui_sterowanie.h"

// plik automatycznie utworzony przez qt poprzed dodanie  okienka  z Qt designer form class
Sterowanie::Sterowanie(QWidget *parent) :       // konstruktor z parameterem rodzica pozwala na zamkniecie wszystkich okien tej klasu przy zamknieciu ich rodzica
    QDialog(parent),
    ui(new Ui::Sterowanie)
{
    ui->setupUi(this);
}

Sterowanie::~Sterowanie()
{
    delete ui;
}
