#ifndef WROG_H
#define WROG_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>
#include <QList>

//aby klasa obslugiwala sygnaly i sloty musi dziedziczyc i miec makro qobject
class Wrog : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Wrog(); // konstruktor
public slots:
    virtual void move() = 0; // funkcja czysto abstrakcyjna
};


#endif // WROG_H
