#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>

#include "visionworker.h"
#include "printercontroller.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    Ui::MainWindow *ui;
    QGraphicsScene *m_scene;
    VisionWorker *m_visionWorker;
    PrinterController *m_printerController;

private slots:
    void updateCameraView(QImage);
    void on_buttonMove_clicked();
};

#endif // MAINWINDOW_H
