#include "spot.h"

#include "block.h"

Spot::Spot(const QStringList & data, Block *parent) :
    QObject(parent)
{
    _data = data;
    _block = parent;
    if(id() == "empty")
        _isEmpty=TRUE;
    else
        _isEmpty=FALSE;
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

bool Spot::isEmpty()
{
    return _isEmpty;
}

int Spot::row()
{
    return value("Row").toInt();
}

int Spot::column()
{
    return value("Column").toInt();
}

int Spot::blockNumber()
{
    return value("Block").toInt();
}

QString Spot::name()
{
    return value("Name");
}
