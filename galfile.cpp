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
    _fileName = fileName;
    readFile(fileName);
}

void GalFile::readFile(const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

   QTextStream in(&file);
   QString line = in.readLine().simplified();
   if (line.toUpper().startsWith("ATF"))
       _metaData.insert("version",line.split(QRegExp("[,\\s+]")).last());
   else
       qDebug() << "no Gal file";

   QStringList headndata = in.readLine().simplified().split(QRegExp("\\s+"));
   int headCount = headndata.first().toInt();
   _colCount = headndata.last().toInt();
   QRegExp blockRx("Block[0-9]+");
   QRegExpValidator blockV(blockRx, 0);
   int pos=0;
   while (!in.atEnd() && headCount > 0) {
        QStringList headline = in.readLine().simplified().split('=');
        if(blockV.validate(headline.first(),pos))
            newBlock(headline.first().mid(5).toInt(),headline.last());
        else
            _metaData.insert(headline.first(),headline.last());
        headCount--;
   }
   qDebug() << _blocks.count();
   setColumnHeader(in.readLine().simplified());
   while (!in.atEnd())
   {
       setSpotData(in.readLine().simplified().remove("\""));
   }
   emit fileRead();
}

void GalFile::newBlock(int block, const QString & data)
{
    Block * newBlock = new Block(block,data,this);
    _blocks.insert(block,newBlock);
}

void GalFile::setColumnHeader(const QString & data)
{
    if(data.contains("\""))
        _columnNames = data.split(QRegExp("\"\\s\""));
    else
        _columnNames = data.split(QRegExp("\\s"));
    _columnNames.replaceInStrings("\"","");
    if( _columnNames.count() != _colCount)
        qDebug() << "column number does not match";

}

void GalFile::setSpotData(const QString & data)
{
    QStringList dataL = data.split(QRegExp("\\s"));
    int blockCol = _columnNames.indexOf("Block");
    int blockNumber = dataL[blockCol].toInt();
    Block * block;
    if (_blocks.value(blockNumber,0) != 0)
        block = _blocks.value(blockNumber);
    else
    {
        block = new Block(blockNumber,this);
        _blocks.insert(blockNumber,block);
    }
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

const QStringList & GalFile::columnnames()
{
    return _columnNames;
}
