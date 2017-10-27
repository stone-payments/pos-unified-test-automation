#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include <opencv2/opencv.hpp>

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
    QGraphicsScene * m_scene;
    cv::VideoCapture capture;
    QTimer* m_timer;
private slots:
    void updateCameraView();
};

#endif // MAINWINDOW_H
