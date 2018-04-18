#ifndef STEROWANIE_H
#define STEROWANIE_H

#include <QDialog>

namespace Ui {
class Sterowanie;
}

class Sterowanie : public QDialog
{
    Q_OBJECT

public:
    explicit Sterowanie(QWidget *parent = 0); // jawny konstrukor z parametrem rodzica pozwalajacy na automatyczne usuniecie okna gdy usuniety jest rodzic
    ~Sterowanie();  // destruktor

private:
    Ui::Sterowanie *ui; // prywaty wskaznik typu sterowanie
};

#endif // STEROWANIE_H
