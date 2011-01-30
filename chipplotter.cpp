#include "chipplotter.h"

#include<QGraphicsScene>
#include "galfile.h"

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
    GalFile::BlockList * blocks = _file->blocks();
    foreach (GalFile::Block * block, *blocks) {
        _scene->addRect(block->xOrigin,
                        block->yOrigin,
                        block->xCount*block->xSpacing,
                        block->yCount*block->ySpacing);
    }

    _scene->addRect(0,0,25000,76000);

}

QGraphicsScene * ChipPlotter::scene()
{
    return _scene;
}
