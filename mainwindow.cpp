#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include "galfile.h"
#include "chipplotter.h"
#include <QDebug>
#include "spotgraphicsitem.h"
#include "spot.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionFileOpen,SIGNAL(triggered()),SLOT(openGalFile()));
    connect(ui->pushButtonZoomIn,SIGNAL(pressed()),ui->chipView,SLOT(zoomIn()));
    connect(ui->pushButtonZoomOut,SIGNAL(pressed()),ui->chipView,SLOT(zoomOut()));
    connect(ui->pushButtonSaveSeleceted,SIGNAL(pressed()),SLOT(saveSelectedItems()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openGalFile()
{
    QString fileName = QFileDialog::getOpenFileName();
    _galFileList.append(new GalFile(fileName,this));
    drawChip(_galFileList.last());
}

void MainWindow::drawChip(GalFile *file)
{

    ChipPlotter * cp = new ChipPlotter(file,this);
    QGraphicsScene * scene =  cp->scene();
    ui->chipView->setScene(scene);
    ui->chipView->show();
    ui->chipView->fitInView(scene->sceneRect(),Qt::KeepAspectRatio);

}

void MainWindow::saveSelectedItems()
{
    QList<QGraphicsItem *> items =  ui->chipView->scene()->selectedItems();
    bool first = true;
    foreach (QGraphicsItem * item, items) {
        SpotGraphicsItem * spot =qgraphicsitem_cast<SpotGraphicsItem *> (item);
        if (spot != 0)
        {

            if(first)
            {
                qDebug() << spot->spot()->dataNamesAsString();
            }
            qDebug() << spot->spot()->dataAsString();
        }
    }
}
