#ifndef BLOCK_H
#define BLOCK_H

#include <QObject>

class Spot;
#include "galfile.h"

class Block : public QObject
{
    Q_OBJECT
public:

    Block(int number,const QString & data, GalFile * file = 0);
    void addSpot(Spot * spot);
    Spot * spot(int column,int row);
    SpotList * spots();

    int blockNumber;
    int xOrigin;
    int yOrigin;
    int diameter;
    int xCount;
    int yCount;
    int xSpacing;
    int ySpacing;

signals:

public slots:

private:
    SpotList _spots;
    GalFile * _file;

};

#endif // BLOCK_H
