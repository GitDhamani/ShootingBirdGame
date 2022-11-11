#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include "bird.h"
#include <QTimer>
#include "scene.h"
#include <QDebug>
#include <QGraphicsSimpleTextItem>
#include <QGraphicsScene>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(632,457);
    setWindowTitle("Shoot Bird Game");
    startgame = false;
    score = 0;

    //Set up the Scene
    scene = new Scene(this);
    scene->setSceneRect(-306,-204, 612, 408);

    //Create the Background Pixmap
    QGraphicsPixmapItem* background = new QGraphicsPixmapItem;
    background->setPixmap(QPixmap(":/Images/Background1.jpg"));
    background->setPos(-background->boundingRect().width()/2, -background->boundingRect().height()/2);
    scene->addItem(background);

    //Timer to Birds
    QTimer* AddingBirds = new QTimer;
    AddingBirds->setInterval(1500);
    AddingBirds->start();

    //Adding Birds
    connect(AddingBirds, &QTimer::timeout, [=](){

        if (startgame)
        {
        Bird* bird = new Bird;
        scene->addItem(bird);

        //Catch Collision to increment score
        connect(bird, &Bird::collisionDetected, [=](){
            score++;
            UpdateScore();
        });

        }

    });

    //Handle Start Button
    connect(ui->pushButton, &QPushButton::clicked, [=](){
        startgame = true;
        ui->pushButton->setDisabled(true);
    });

    //Add Bow
    scene->addBow();

    scoreText = new QGraphicsSimpleTextItem;
    scoreText->setText("Score: 0");
    QFont font("Arial", 30);
    scoreText->setFont(font);
    scoreText->setPen(QPen(Qt::blue));
    scene->addItem(scoreText);
    scoreText->setPos(100,160);

    QGraphicsView* view = new QGraphicsView(this);
    view->setScene(scene);
    view->setMouseTracking(true);
    view->setRenderHint(QPainter::Antialiasing);
    ui->verticalLayout->addWidget(view);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::UpdateScore()
{
    scoreText->setText(QString("Score: " + QString::number(score)));
}

