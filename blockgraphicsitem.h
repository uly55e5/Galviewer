#ifndef BLOCKGRAPHICSITEM_H
#define BLOCKGRAPHICSITEM_H

#include <QGraphicsItem>
#include "galfile.h"

class QGraphicsRectItem;
class Block;

class BlockGraphicsItem : public QGraphicsItem
{

public:
    enum { Type = UserType+1 };

    explicit BlockGraphicsItem(Block * block, QGraphicsItem *parent = 0);
    QRectF boundingRect () const;
    void paint ( QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = 0 );
    int type() const;
signals:

public slots:

private:
    void drawBlock();
    Block * _block;
    QGraphicsRectItem * _rect;

};

#endif // BLOCKGRAPHICSITEM_H
