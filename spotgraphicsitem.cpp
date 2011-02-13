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
    setFlag(QGraphicsItem::ItemIsSelectable);
    _text = QString("%1,%2,%3\n%4\n%5").arg(_spot->blockNumber()).arg(_spot->column()).arg(_spot->row()).arg(_spot->id()).arg(_spot->name());
    setToolTip(_text);
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
    if (isSelected())
        painter->setPen(QColor("blue"));
    painter->drawEllipse(0,0,_spot->diameter(),_spot->diameter());
    if( lod >= 0.2 )
        painter->drawText(0,0,_spot->diameter(),_spot->diameter(),Qt::AlignCenter,_text);
    return;
}

void SpotGraphicsItem::setEmptyPen(QVector<qreal> dashPattern)
{
    s_emptyPen.setDashPattern(dashPattern);
}

int SpotGraphicsItem::type() const
{
    return Type;
}

Spot * SpotGraphicsItem::spot() const
{
    return _spot;
}




