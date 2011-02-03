#ifndef GALFILE_H
#define GALFILE_H

#include <QHash>
#include <QObject>
#include <QMap>
#include <QStringList>

class Block;
class Spot;

typedef QMap<int,Block *> BlockList;
typedef QList<Spot *> SpotList;

class GalFile : public QObject
{

    Q_OBJECT
public:
    enum BlockType {
        Rectangular,
        Orange1,
        Orange2
    };

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
    QStringList _columnNames;
    MetaData _metaData;
    int _colCount;

    void newBlock(int block, const QString & data);
    void setColumnHeader(const QString & data);
    void setSpotData(const QString & data);

signals:

public slots:

};

#endif // GALFILE_H
