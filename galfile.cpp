#include "galfile.h"

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
       throw("no gal file");

   QStringList headndata = in.readLine().split(QRegExp("\\s+"));
   int headCount = headndata.first().toInt();
   int colCount = headndata.last().toInt();

   QRegExp blockRx("Block[0-9]+");
   QRegExpValidator blockV(blockRx, 0);
   int pos=0;
   while (!in.atEnd() && headCount > 0) {
        QStringList headline = in.readLine().split('=');
        if(blockV.validate(headline.first(),pos))
            setBlock(headline.last());
        else
            _metaData.insert(headline.first(),headline.last());

   }
}

void GalFile::setBlock(const QString & data)
{

}
