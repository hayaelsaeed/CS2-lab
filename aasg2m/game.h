#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "MyRect.h"
#include "score.h"
#include "Health.h"


class Game: public QGraphicsView{
public:
    Game(QWidget * parent=0);

    QGraphicsScene * scene;
    MyRect*Myrect;
    Score*score;
    Health * health;

};

#endif // GAME_H
