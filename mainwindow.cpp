#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include "galfile.h"
#include "chipplotter.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionFileOpen,SIGNAL(triggered()),SLOT(openGalFile()));
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
