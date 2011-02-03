#ifndef CHIPVIEW_H
#define CHIPVIEW_H

#include <QGraphicsView>

class ChipView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit ChipView(QWidget *parent = 0);

signals:

public slots:
    void wheelEvent ( QWheelEvent * event ) ;

};

#endif // CHIPVIEW_H
