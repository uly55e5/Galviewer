#ifndef CHIPPLOTTER_H
#define CHIPPLOTTER_H

#include <QObject>

class GalFile;
class QGraphicsScene;

class ChipPlotter : public QObject
{
    Q_OBJECT
public:
    explicit ChipPlotter(QObject *parent = 0);
    ChipPlotter(GalFile * file,QObject *parent=0);
    QGraphicsScene * scene();
signals:

public slots:
    void drawChip();
private:
    QGraphicsScene * _scene;
    GalFile * _file;

};

#endif // CHIPPLOTTER_H
