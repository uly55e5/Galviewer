#include "spot.h"

#include "block.h"

Spot::Spot(const QStringList & data, Block *parent) :
    QObject(parent)
{
    _data = data;
}
