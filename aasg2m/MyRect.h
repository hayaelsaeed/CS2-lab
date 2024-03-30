#ifndef MYRECT_H
#define MYRECT_H

#include <QGraphicsRectItem>
#include <QObject>
#include<QGraphicsRectItem>

class MyRect:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    MyRect(QGraphicsItem *parent = nullptr);
    void keyPressEvent(QKeyEvent * event);
public slots:
    void spawn();
};

#endif // MYRECT_H
