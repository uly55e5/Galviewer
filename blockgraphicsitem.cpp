#include "blockgraphicsitem.h"

#include <QGraphicsRectItem>
#include <QPainter>

#include "block.h"

BlockGraphicsItem::BlockGraphicsItem(Block * block,QGraphicsItem *parent) :
    QGraphicsItem(parent)
{
    _block = block;
    _rect = 0;
    drawBlock();
}

void BlockGraphicsItem::drawBlock()
{
    _rect = new QGraphicsRectItem(0,0,
                            _block->xCount()*_block->xSpacing(),
                            _block->yCount()*_block->ySpacing(),this);
}

QRectF BlockGraphicsItem::boundingRect () const
{
    if(_rect == 0)
        return QRectF();
    return _rect->boundingRect();
}

void BlockGraphicsItem::paint ( QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget )
{
    return;
}
