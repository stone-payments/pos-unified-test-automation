#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>

#include "visionworker.h"
#include "printercontroller.h"
#include "cardcontroller.h"

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
    CardController *m_cardController;

private slots:
    void updateCameraView(QImage);
    void on_buttonMove_clicked();
    void on_buttonInsertCard_clicked();
    void on_buttonRemoveCard_clicked();
};

#endif // MAINWINDOW_H
