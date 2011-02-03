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
