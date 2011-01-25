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

    struct Block {
       int xOrigin;
       int yOrigin;
       int diameter;
       int xCount;
       int yCount;
       int xSpacing;
       int ySpacing;
    };

    struct Row {
        int block;
        int column;
        int row;
        QString name;
        QString id;
        QStringList additionialCols;
    };

    typedef QMap<int,Block> BlockList;
    typedef QList<Row> RowList;
    typedef QHash<QString,QString> MetaData;


    explicit GalFile(QObject *parent = 0);
    explicit GalFile(const QString & fileName, QObject * parent = 0);

    void readFile(const QString & fileName);

private:
    QString _fileName;
    BlockList _blocks;
    RowList _data;
    MetaData _metaData;

signals:

public slots:

};

#endif // GALFILE_H
