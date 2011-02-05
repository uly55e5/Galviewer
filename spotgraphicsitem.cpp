#include "spotgraphicsitem.h"
#include "spot.h"
#include <QGraphicsEllipseItem>
#include <QGraphicsTextItem>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QDebug>

QPen SpotGraphicsItem::s_emptyPen;

SpotGraphicsItem::SpotGraphicsItem(Spot * spot, QGraphicsItem *parent) :
    QGraphicsItem(parent)
{
    _spot = spot;
    _text = QString("%1,%2,%3\n%4\n%5").arg(_spot->blockNumber()).arg(_spot->column()).arg(_spot->row()).arg(_spot->id()).arg(_spot->name());
//    _text = _spot->blockNumber() + "," + _spot->row() + "," + _spot->row() + "\n" + _spot->id() + "\n" + _spot->name();
}


QRectF SpotGraphicsItem::boundingRect () const
{
    return QRectF(0,0,_spot->diameter(),_spot->diameter());
}

void SpotGraphicsItem::paint ( QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget )
{
    qreal lod = option->levelOfDetailFromTransform(painter->worldTransform());
    if(_spot->isEmpty())
    {
        painter->setPen(s_emptyPen);
    }
    painter->drawEllipse(0,0,_spot->diameter(),_spot->diameter());
    if( lod >= 0.2 )
        painter->drawText(0,0,_spot->diameter(),_spot->diameter(),Qt::AlignCenter,_text);
    return;
}

void SpotGraphicsItem::setEmptyPen(QVector<qreal> dashPattern)
{
    s_emptyPen.setDashPattern(dashPattern);
}






