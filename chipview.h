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
    void wheelEvent ( QWheelEvent * event );
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void zoomIn(int speed=1);
    void zoomOut(int speed=1);

private:
    QPointF _moveStartPos;

};

#endif // CHIPVIEW_H
