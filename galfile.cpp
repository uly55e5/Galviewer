#include "galfile.h"

#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QRegExpValidator>

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
   qDebug() << line;
   if (line.toUpper().startsWith("ATF"))
       _metaData.insert("version",line.split(QRegExp("\\s+")).last());
   else
       throw("no gal file");

   QStringList headndata = in.readLine().split(QRegExp("\\s+"));
   int headCount = headndata.first().toInt();
   int colCount = headndata.last().toInt();
   qDebug() << headCount << colCount;
   QRegExp blockRx("Block[0-9]+");
   QRegExpValidator blockV(blockRx, 0);
   int pos=0;
   while (!in.atEnd() && headCount > 0) {
        QStringList headline = in.readLine().split('=');
        qDebug() << headline.first();
        if(blockV.validate(headline.first(),pos))
            setBlock(headline.first().mid(5).toInt(),headline.last());
        else
            _metaData.insert(headline.first(),headline.last());
        headCount--;
   }
   qDebug() << _blocks.count();
   setSpotIndex(in.readLine(),colCount);
   while (!in.atEnd())
   {
       setSpotData(in.readLine());
   }
   emit fileRead();
}

void GalFile::setBlock(int block, const QString & data)
{
    Block * newBlock = new Block(data);
    _blocks.insert(block,newBlock);
}

void GalFile::setSpotIndex(const QString & data, int colCount)
{
    QStringList dataL = data.split(QRegExp("\\s"));
    for(int i=0; i< dataL.count(); i++)
    {
        if (dataL[i] == "Block")
            _colHeads.block=i;
        else if (dataL[i] == "Row")
            _colHeads.row = i;
        else if (dataL[i] == "Column")
            _colHeads.column = i;
        else if (dataL[i] == "ID")
            _colHeads.id = QString().setNum(i);
        else if (dataL[i] == "Name")
            _colHeads.name = QString().setNum(i);
        else
            _colHeads.additionialCols.append(dataL[i]);
    }
}

void GalFile::setSpotData(const QString & data)
{
    QStringList dataL = data.split(QRegExp("\\s"));
    Spot * row = new Spot();
    for(int i=0; i< dataL.count(); i++)
    {
        if(i == _colHeads.block)
            row->block = dataL[i].toInt();
        else if(i == _colHeads.row)
            row->row = dataL[i].toInt();
        else if(i == _colHeads.column)
            row->column = dataL[i].toInt();
        else if(i == _colHeads.name.toInt())
            row->name = dataL[i];
        else if(i == _colHeads.id.toInt())
            row->id = dataL[i];
        else
            row->additionialCols.append(dataL[i]);
    }
    _data.append(row);
    qDebug() << _data.count();
}

GalFile::BlockList * GalFile::blocks()
{
    return &_blocks;
}

GalFile::SpotList * GalFile::spots()
{
    return &_data;
}

GalFile::Block::Block(const QString & data)
{
    QStringList dataList = data.split(',');
    xOrigin = dataList[0].toInt();
    yOrigin = dataList[1].toInt();
    diameter = dataList[2].toInt();
    xCount = dataList[3].toInt();
    xSpacing = dataList[4].toInt();
    yCount = dataList[5].toInt();
    ySpacing = dataList[6].toInt();

}
