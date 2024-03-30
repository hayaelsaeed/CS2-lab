#include "Health.h"
#include <QFont>
#include <QMessageBox>
#include <score.h>
Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent){

    health = 3;


    setPlainText(QString("Health: ") + QString::number(health));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}

void Health::decrease(){
    if(health>0){
    health--;
    setPlainText(QString("Health: ") + QString::number(health));
    }else{

        QMessageBox::about(nullptr, "GAME OVER", "Game Over!");
    }}

int Health::getHealth(){
    return health;
}

