#ifndef SPOTGRAPHICSITEM_H
#define SPOTGRAPHICSITEM_H

#include <QGraphicsItem>
class Spot;

class SpotGraphicsItem : public QGraphicsItem
{

public:
    enum { Type = UserType+2 };

    explicit SpotGraphicsItem(Spot * spot, QGraphicsItem *parent = 0);
    QRectF boundingRect () const;
    void paint ( QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = 0 );
    static void setEmptyPen(QVector<qreal> dashPattern);
    int type() const;
    Spot * spot() const;

signals:

public slots:

private:
    void drawSpot();

    Spot * _spot;
    QGraphicsEllipseItem * _circle;
    static QPen s_emptyPen;
    QString _text;


};

#endif // SPOTGRAPHICSITEM_H
