#include "gscene.h"
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsPathItem>
#include <QTimer>
#include <QThread>
#include <QTimeLine>
#include <QGraphicsItemAnimation>
#include <QPropertyAnimation>


gscene::gscene(QObject *parent): QGraphicsScene(parent)
{
   // this->setBackgroundBrush(Qt::darkCyan);
    i=-1;

}

void gscene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug()<<"click!";
    QPen pen(Qt::red, 3, Qt::SolidLine);
    QPointF p = event->buttonDownScenePos(Qt::LeftButton);
    addEllipse(p.x(), p.y(), 3, 3,pen);
    if(i!=-1){
        i++;
        v.append(p);
        if(i==3){
            drowspl();
        }
    }


}

void gscene::drowspl()
{
     QPen pen(Qt::white, 1, Qt::SolidLine);

    // QTimeLine *timer = new QTimeLine(5000);
      //timer->setFrameRange(0, 100);

    //  QGraphicsItemAnimation *animation = new QGraphicsItemAnimation;
    //animation->setTimeLine(timer);

    for(int j=50;j<500;j++){
    QPainterPath myPath1;
    QPropertyAnimation ani;
    ani.setTargetObject(this);

    ani.setDuration(1000);
    ani.start();

    myPath1.moveTo(v.at(0).x(),v.at(0).y()+j);
    myPath1.cubicTo(QPointF(v.at(0).x(),v.at(0).y()+j),v.at(1), v.at(2));
    //myPath1.cubicTo(QPointF(v.at(0).x()+j,v.at(0).y()+j),QPointF(v.at(1).x()+j,v.at(1).y()+j),QPointF(v.at(2).x()+j,v.at(2).y()+j));

    //QGraphicsPathItem gp;
    //gp.setPath(myPath1);
    //animation->setItem(&gp);
    this->addPath(myPath1,pen);

    j=j+10;
    ani.stop();
    }

    i=-1;
    v.clear();
}
