#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>
#include "game.h"
#include <QDebug>
extern Game * game;

Enemy::Enemy(): QObject(),  QGraphicsPixmapItem(){
//set random position
    int random_number = rand() % 700;
    setPos(random_number,0);
//set chicken
    setPixmap(QPixmap(":/resource/chicken.png").scaled(100, 100));

// connect
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void Enemy::move(){
    // move enemy down
    setPos(x(),y()+5);
    if (pos().y() + boundingRect().height() < 0){
        scene()->removeItem(this);
        delete this;
    }
}

