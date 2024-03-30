#include "Game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>

Game::Game(QWidget *parent){
 QGraphicsScene * scene = new QGraphicsScene();


MyRect * player = new MyRect();
player->setPixmap(QPixmap(":/resource/ship.png"));


scene->addItem(player);


player->setFlag(QGraphicsItem::ItemIsFocusable);
player->setFocus();



score = new Score();
scene->addItem(score);
health = new Health();
health->setPos(health->x(),health->y()+25);
scene->addItem(health);

// create a view to visualize the scene
QGraphicsView * view = new QGraphicsView(scene);
view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


setScene(scene);
view->setFixedSize(800,600);
scene->setSceneRect(0,0,800,600);

player->setPos(view->width()/2,view->height() - player->boundingRect().height());


// spawn enemies
QTimer * timer = new QTimer();
QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
timer->start(2000);

}


