#ifndef SPOTGRAPHICSITEM_H
#define SPOTGRAPHICSITEM_H

#include <QGraphicsItem>
class Spot;

class SpotGraphicsItem : public QGraphicsItem
{
public:
    explicit SpotGraphicsItem(Spot * spot, QGraphicsItem *parent = 0);
    QRectF boundingRect () const;
    void paint ( QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = 0 );


signals:

public slots:

private:
    void drawSpot();

    Spot * _spot;
    QGraphicsEllipseItem * _circle;

};

#endif // SPOTGRAPHICSITEM_H
