#ifndef GSCENE_H
#define GSCENE_H

#include <QObject>
#include <QWidget>
#include <QGraphicsScene>
#include <QDebug>

class gscene : public QGraphicsScene
{
    Q_OBJECT
public:
     explicit gscene(QObject *parent = 0);
     virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void drowspl();

    int i;
    QVector<QPointF> v;


};

#endif // GSCENE_H
