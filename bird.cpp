#include "bird.h"
#include <QTimer>
#include <QRandomGenerator>
#include <QGraphicsScene>
#include <arrow.h>
#include <QDebug>

Bird::Bird()
{
    setPixmap(QPixmap(":/Images/bird1up.png"));
    setScale(0.125);
    wingstate = 1;
    onlyOnce = 1;

    //Timer to Flap Wings
    QTimer* flapwings = new QTimer(this);
    flapwings->setInterval(250);
    flapwings->start();

    //Flap the Wings
    connect(flapwings, &QTimer::timeout, [=](){
        if (wingstate)
        {
            setPixmap(QPixmap(":/Images/bird1down.png"));
            wingstate = 0;
            setPos(x(), y() - 4);
        }
        else
        {
            setPixmap(QPixmap(":/Images/bird1up.png"));
            wingstate = 1;
            setPos(x(), y() + 4);
        }
    });

    //Generate Random Y position to Have the Bird Fly at
    int RandHeight = QRandomGenerator::global()->bounded(-200,-50);

    //Timer to Fly Across Screen
    QTimer* FlyAcross = new QTimer(this);
    FlyAcross->setInterval(15);
    FlyAcross->start();

    //Set Bird's initial position
    setPos(-320, RandHeight);

    connect(FlyAcross, &QTimer::timeout, [=](){

        //Move Bird across the screen
        setPos(x() + 2, y());

        //If bird has reached past the screen, delete it
        if (x() > 300)
        {
            scene()->removeItem(this);
            delete this;
        }

        //Collisions
        QList<QGraphicsItem*> list = collidingItems();
        if (list.count()!=0)
        foreach(QGraphicsItem* element, list)
        {
            if (typeid(*element) == typeid(Arrow))
            {
              //qDebug() << "COLLISION DETECTED!";
              flapwings->stop();
              setPixmap(QPixmap(":/Images/Puff.png"));
              if (onlyOnce)
              {
              emit collisionDetected();
              onlyOnce = 0;
              }
            }
        }
    });



}
