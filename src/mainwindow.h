#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>

#include "visionworker.h"

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

private slots:
    void updateCameraView(QImage);
};

#endif // MAINWINDOW_H
