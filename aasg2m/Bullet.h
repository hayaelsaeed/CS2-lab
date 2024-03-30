#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsRectItem>
#include <QObject>


extern int globalVariable;

class Bullet: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Bullet();
    static Bullet* getInstance(); //test
signals:
    void scoreUpdated(int score); //test
public slots:
    void move();
private:
    static Bullet* instance;

};

#endif // BULLET_H
