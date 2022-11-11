#ifndef BIRD_H
#define BIRD_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Bird: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Bird();

private:
    bool wingstate; //0 means down, 1 means up.
    bool onlyOnce;

signals:
    void collisionDetected();
};

#endif // BIRD_H
