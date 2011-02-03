#include "block.h"

Block::Block(int block, const QString & data, GalFile * parent) :
    QObject(parent)
{

}

void Block::addSpot(Spot * spot)
{
    _spots.append(spot);
}

Spot * Block::spot(int column,int row)
{

}

SpotList * Block::spots()
{
    return &_spots;
}
