#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class GalFile;

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void openGalFile();
private:
    Ui::MainWindow *ui;
    QList<GalFile *> _galFileList;
};

#endif // MAINWINDOW_H
