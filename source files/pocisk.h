#ifndef POCISK_H
#define POCISK_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>
#include <QTimer>
#include <QGraphicsScene>
#include <QList>

//aby klasa obslugiwala sygnaly i sloty musi dziedziczyc i miec makro qobject
class Pocisk: public QObject, public QGraphicsPixmapItem //dziedziczymy z klas qobject i qgraphicspixmapitem z op_wid public
{
    Q_OBJECT    //makro do sygn i slotow
public:
    Pocisk();
public slots:
    virtual void move() = 0; // funkcja czysto abstrakcyjna

};

#endif // POCISK_H
