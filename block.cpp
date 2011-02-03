#include "block.h"

Block::Block(int block, const QString & data, GalFile * parent) :
    QObject(parent)
{
    _file = parent;
    _blockNumber = block;
    setData(data);
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

const QStringList & Block::columnNames()
{
    return _file->columnnames();
}

void Block::setData(const QString &data)
{
    QStringList dataL = data.split(",");
    _xOrigin = dataL[0].toInt();
    _yOrigin= dataL[1].toInt();
    _diameter = dataL[2].toInt();
    _xCount = dataL[3].toInt();
    _xSpacing = dataL[4].toInt();
    _yCount = dataL[5].toInt();
    _ySpacing = dataL[6].toInt();
}


int Block::blockNumber()
{
    return _blockNumber;
}

int Block::xOrigin()
{
    return _xOrigin;
}

int Block::yOrigin()
{
    return _yOrigin;
}

int Block::diameter()
{
    return _diameter;
}

int Block::xCount()
{
    return _xCount;
}

int Block::yCount()
{
    return _yCount;
}

int Block::xSpacing()
{
    return _xSpacing;
}

int Block::ySpacing()
{
    return _ySpacing;
}
