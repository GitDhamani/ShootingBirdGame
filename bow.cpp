#include "bow.h"

Bow::Bow(QObject* parent): QObject(parent)
{
    setPixmap(QPixmap(":/Images/Bow.png"));
    setScale(0.1);
    setPos(-306,115);
}
