#include "spotgraphicsitem.h"
#include "spot.h"
#include <QGraphicsEllipseItem>
#include <QGraphicsTextItem>

SpotGraphicsItem::SpotGraphicsItem(Spot * spot, QGraphicsItem *parent) :
    QGraphicsItem(parent)
{
    _spot = spot;
    _circle = 0;
    drawSpot();
}


QRectF SpotGraphicsItem::boundingRect () const
{
    if(_circle==0)
        return QRectF();
    return _circle->boundingRect();
}

void SpotGraphicsItem::paint ( QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget )
{
    return;
}

void SpotGraphicsItem::drawSpot()
{
    _circle = new QGraphicsEllipseItem(0,0,_spot->diameter(),_spot->diameter(),this);
    new QGraphicsTextItem(_spot->id(),this);
}
