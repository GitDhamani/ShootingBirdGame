#include "arrow.h"
#include <QTimer>
#include <QGraphicsScene>
#include "qmath.h"
#include <QDebug>

Arrow::Arrow()
{
    setPixmap(QPixmap(":/Images/Arrow1.png"));
    setScale(0.1);

    QTimer* timer = new QTimer;
    timer->setInterval(30);
    timer->start();

    connect(timer, &QTimer::timeout, [=](){

        int StepLength = 10;
        float dx = StepLength*cos(qDegreesToRadians(this->rotation()));
        float dy = StepLength*sin(qDegreesToRadians(this->rotation()));
        setPos(x() + dx, y() + dy);

        QLineF ln;
        ln.setLine(-260, 160, x(), y());
        if (ln.length() > maxRange)
        {
            scene()->removeItem(this);
            delete (timer);
            delete(this);
        }

    });

}
