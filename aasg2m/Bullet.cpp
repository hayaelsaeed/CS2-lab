#include "Bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "Enemy.h"
#include "score.h"
#include "game.h"

extern Game * game;


Bullet* Bullet::instance = nullptr; //test
#include <QDebug>
Bullet::Bullet(): QObject(), QGraphicsPixmapItem(){

    setPixmap(QPixmap(":/resource/red_laser.png"));

//connect
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

/* Bullet* Bullet::getInstance() {
    if (!instance) {
        instance = new Bullet();
    }
    return instance;
} */

void Bullet::move(){


    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Enemy)){

            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);

             game->score->increase();

            delete colliding_items[i];
            delete this;
            return;
        }
    }


    setPos(x(),y()-10);
    if (pos().y() + boundingRect().height() < 0){
        scene()->removeItem(this);
        delete this;
    }
}
