#ifndef BLOCK_H
#define BLOCK_H

#include <QObject>

class Spot;
#include "galfile.h"

class Block : public QObject
{
    Q_OBJECT
public:

    Block(int number,const QString & data, GalFile * file);
    void addSpot(Spot * spot);
    Spot * spot(int column,int row);
    SpotList * spots();
    const QStringList & columnNames();

    int blockNumber();
    int xOrigin();
    int yOrigin();
    int diameter();
    int xCount();
    int yCount();
    int xSpacing();
    int ySpacing();

signals:

public slots:

private:
    void setData(const QString & data);

    SpotList _spots;
    GalFile * _file;
    int _blockNumber;
    int _xOrigin;
    int _yOrigin;
    int _diameter;
    int _xCount;
    int _yCount;
    int _xSpacing;
    int _ySpacing;
};

#endif // BLOCK_H
