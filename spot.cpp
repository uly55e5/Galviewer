#include "spot.h"

#include "block.h"

Spot::Spot(const QStringList & data, Block *parent) :
    QObject(parent)
{
    _data = data;
    _block = parent;
}

int Spot::diameter()
{
    return _block->diameter();
}

int Spot::xPos()
{
    return (value("Column").toInt()-1)*_block->xSpacing();
}

int Spot::yPos()
{
    return (value("Row").toInt()-1)*_block->ySpacing();

}

QString Spot::value(QString column)
{
    return _data[_block->columnNames().indexOf(column)];
}

QString Spot::id()
{
    return value("ID");
}
