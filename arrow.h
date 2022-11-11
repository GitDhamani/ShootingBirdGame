#ifndef ARROW_H
#define ARROW_H

#include <QGraphicsPixmapItem>

class Arrow: public QObject, public QGraphicsPixmapItem
{
public:
    Arrow();
    int maxRange = 650;
};

#endif // ARROW_H
