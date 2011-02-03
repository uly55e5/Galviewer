#ifndef SPOT_H
#define SPOT_H

#include <QObject>
#include <QStringList>

class Block;

class Spot : public QObject
{
    Q_OBJECT
public:
    explicit Spot(const QStringList & data,Block * parent = 0);
    int blockNumber();
    int column();
    int row();
    QString name();
    QString id();
    int diameter();
    int xPos();
    int yPos();
    QString value(QString column);
    QString value(int column);

signals:

public slots:

private:
    Block * _block;
    QStringList _data;
};

#endif // SPOT_H
