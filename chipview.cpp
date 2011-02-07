#include "chipview.h"
#include <QWheelEvent>
#include <QDebug>
#include <cmath>

ChipView::ChipView(QWidget *parent) :
    QGraphicsView(parent)
{
}

void ChipView::wheelEvent ( QWheelEvent * event )
{
    setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    int  delta = event->delta();
    qDebug() << delta;
    qreal zoom = 1.15;
    if(delta < 0)
        zoom = 1./zoom;
    scale(zoom,zoom);
    event->accept();

}

void ChipView::zoomIn(int speed)
{
    qreal zoom=pow(1.15,speed);
    scale(zoom,zoom);
}

void ChipView::zoomOut(int speed)
{
    qreal zoom=pow(0.9,speed);
    scale(zoom,zoom);
}

void ChipView::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::RightButton)
        _moveStartPos=event->posF();
}

void ChipView::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons() & Qt::RightButton)
    {
        qreal dx = event->x()-_moveStartPos.x();
        qreal dy = event->y()-_moveStartPos.y();
        translate(dx,dy);
        _moveStartPos = event->pos();
    }
}
