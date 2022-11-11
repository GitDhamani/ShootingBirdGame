#include "scene.h"
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsScene>
#include "bow.h"
#include <QGraphicsRectItem>
#include "arrow.h"
#include <QTimer>

Scene::Scene(QObject* parent): QGraphicsScene(parent)
{
    //Add Bow
    bow = new QGraphicsPixmapItem;
    bow->setPixmap(QPixmap(":/Images/Bow.png"));
    bow->setScale(0.1);
    bow->setPos(-306,115);
    rotateAngle = 0;
    StartFiring = 0;

    QTimer* FireArrows = new QTimer(this);
    FireArrows->setInterval(100);
    FireArrows->start();

    connect(FireArrows, &QTimer::timeout, [=](){
        if (StartFiring)
        {
        Arrow* arrow = new Arrow;
        this->addItem(arrow);
        arrow->setPos(bow->pos().x()+bow->boundingRect().center().x()*0.1,
                      bow->pos().y()+bow->boundingRect().center().y()*0.1);
        arrow->setRotation(360 - rotateAngle);
        }
    });
}

void Scene::addBow()
{
    this->addItem(bow);
}

void Scene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

   StartFiring = 1;
   Arrow* arrow = new Arrow;
   this->addItem(arrow);
   arrow->setPos(bow->pos().x()+bow->boundingRect().center().x()*0.1,
                 bow->pos().y()+bow->boundingRect().center().y()*0.1);
   arrow->setRotation(360 - rotateAngle);
    QGraphicsScene::mousePressEvent(event);
}

void Scene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QLineF ln(bow->pos().x()+bow->boundingRect().center().x()*0.1,
              bow->pos().y()+bow->boundingRect().center().y()*0.1,
              event->scenePos().x(), event->scenePos().y());

    QTransform tf = bow->transform();
    tf.translate(bow->boundingRect().center().x()*0.1,bow->boundingRect().center().y()*0.1);
    bow->setTransform(tf);
    tf.rotate(360 - (ln.angle() - rotateAngle));
    rotateAngle +=(ln.angle() - rotateAngle);
    tf.translate(-bow->boundingRect().center().x()*0.1,-bow->boundingRect().center().y()*0.1);
    bow->setTransform(tf);
    QGraphicsScene::mouseMoveEvent(event);
}

void Scene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    StartFiring = 0;
    QGraphicsScene::mouseReleaseEvent(event);
}
