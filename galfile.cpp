#include "galfile.h"

#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QRegExpValidator>
#include "block.h"
#include "spot.h"

GalFile::GalFile(QObject *parent) :
    QObject(parent)
{
}

GalFile::GalFile(const QString & fileName, QObject *parent) :
    QObject(parent)
{
    readFile(fileName);
}

void GalFile::readFile(const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

   QTextStream in(&file);
   QString line = in.readLine();
   if (line.toUpper().startsWith("ATF"))
       _metaData.insert("version",line.split(QRegExp("\\s+")).last());
   else
       throw("This is no Gal or GPR File");

   QStringList headndata = in.readLine().split(QRegExp("\\s+"));
   int headCount = headndata.first().toInt();
   _colCount = headndata.last().toInt();
   QRegExp blockRx("Block[0-9]+");
   QRegExpValidator blockV(blockRx, 0);
   int pos=0;
   while (!in.atEnd() && headCount > 0) {
        QStringList headline = in.readLine().split('=');
        if(blockV.validate(headline.first(),pos))
            newBlock(headline.first().mid(5).toInt(),headline.last());
        else
            _metaData.insert(headline.first(),headline.last());
        headCount--;
   }
   qDebug() << _blocks.count();
   setColumnHeader(in.readLine());
   while (!in.atEnd())
   {
       setSpotData(in.readLine());
   }
   emit fileRead();
}

void GalFile::newBlock(int block, const QString & data)
{
    Block * newBlock = new Block(block,data);
    _blocks.insert(block,newBlock);
}

void GalFile::setColumnHeader(const QString & data)
{
    _columnNames = data.split(QRegExp("\\s"));
    if( _columnNames.count() != _colCount)
        throw("Column number does not match!");

}

void GalFile::setSpotData(const QString & data)
{
    QStringList dataL = data.split(QRegExp("\\s"));
    int blockCol = _columnNames.indexOf("Block");
    Block * block = _blocks.value(dataL[blockCol].toInt());
    Spot * spot = new Spot(dataL,block);
    block->addSpot(spot);
}

BlockList * GalFile::blocks()
{
    return &_blocks;
}

SpotList * GalFile::spots()
{
    SpotList * allSpots = new SpotList;
    foreach (Block * block, _blocks) {
        allSpots->append(*(block->spots()));
    }
    return allSpots;
}
