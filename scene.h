#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>

class Scene: public QGraphicsScene
{
public:
    Scene(QObject* parent);
    void addBow();

    // QGraphicsScene interface
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

   private:
    QGraphicsPixmapItem* bow;
    float rotateAngle;
    bool StartFiring;
};

#endif // SCENE_H
