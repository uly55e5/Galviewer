#include "chipplotter.h"

#include<QGraphicsScene>
#include "galfile.h"
#include "blockgraphicsitem.h"
#include "block.h"


ChipPlotter::ChipPlotter(QObject *parent) :
    QObject(parent)
{
}

ChipPlotter::ChipPlotter(GalFile *file, QObject *parent)
{
    _file=file;
    drawChip();
}

void ChipPlotter::drawChip()
{
    _scene=new QGraphicsScene(this);
    BlockList * blocks = _file->blocks();
    foreach (Block * block, *blocks) {
        BlockGraphicsItem * blockItem = new BlockGraphicsItem(block);
        _scene->addItem(blockItem);
        blockItem->setPos(block->xOrigin,block->yOrigin);

    }

    _scene->addRect(0,0,25000,76000);

}

QGraphicsScene * ChipPlotter::scene()
{
    return _scene;
}
