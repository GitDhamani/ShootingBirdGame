#ifndef BOW_H
#define BOW_H

#include <QGraphicsPixmapItem>

class Bow: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Bow(QObject* parent);
};

#endif // BOW_H
