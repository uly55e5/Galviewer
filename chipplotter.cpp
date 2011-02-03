#include "chipplotter.h"

#include<QGraphicsScene>
#include "galfile.h"
#include "blockgraphicsitem.h"
#include "spotgraphicsitem.h"
#include "block.h"
#include "spot.h"


ChipPlotter::ChipPlotter(QObject *parent) :
    QObject(parent)
{
}

ChipPlotter::ChipPlotter(GalFile *file, QObject *parent) :
    QObject(parent)
{
    _file=file;
    drawChip();
}

void ChipPlotter::drawChip()
{
    _scene=new QGraphicsScene(this);
    BlockList * blocks = _file->blocks();
    foreach (Block * block, *blocks) {
        drawBlock(block);

    }

    _scene->addRect(0,0,25000,76000);

}

void ChipPlotter::drawBlock(Block * block)
{
    BlockGraphicsItem * blockItem = new BlockGraphicsItem(block);
    _scene->addItem(blockItem);
    blockItem->setPos(block->xOrigin(),block->yOrigin());
    foreach(Spot * spot, *(block->spots()))
    {
        SpotGraphicsItem * spotItem= new SpotGraphicsItem(spot,blockItem);
        spotItem->setPos(spot->xPos(),spot->yPos());
    }
}

QGraphicsScene * ChipPlotter::scene()
{
    return _scene;
}
