#ifndef GALFILE_H
#define GALFILE_H

#include <QHash>
#include <QObject>
#include <QMap>
#include <QStringList>

class GalFile : public QObject
{

    Q_OBJECT
public:
    enum BlockType {
        Rectangular,
        Orange1,
        Orange2
    };

    class Block
    {
    public:
       Block(const QString & data);
       int xOrigin;
       int yOrigin;
       int diameter;
       int xCount;
       int yCount;
       int xSpacing;
       int ySpacing;
    };

    struct Spot {
        int block;
        int column;
        int row;
        QString name;
        QString id;
        QStringList additionialCols;
    };

    typedef QMap<int,Block *> BlockList;
    typedef QList<Spot *> SpotList;
    typedef QHash<QString,QString> MetaData;


    explicit GalFile(QObject *parent = 0);
    explicit GalFile(const QString & fileName, QObject * parent = 0);

    void readFile(const QString & fileName);
    BlockList * blocks();
    SpotList * spots();
signals:
    void fileRead();
private:
    QString _fileName;
    BlockList _blocks;
    SpotList _data;
    MetaData _metaData;
    Spot _colHeads;

    void setBlock(int block, const QString & data);
    void setSpotData(const QString & data);
    void setSpotIndex(const QString & data, int colCount);

signals:

public slots:

};

#endif // GALFILE_H
