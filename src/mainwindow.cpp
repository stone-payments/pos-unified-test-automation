#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_scene(new QGraphicsScene(parent)),
    m_timer(new QTimer(parent))
{
    ui->setupUi(this);
    ui->cameraView->setScene(m_scene);

    // Default webcam
    capture.open(0);

    connect(m_timer, &QTimer::timeout, this, &MainWindow::updateCameraView);
    m_timer->start(16); // 60fps
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateCameraView()
{
    cv::Mat frame;
    capture >> frame;

    // Convert cv::Mat to QImage so we can display it in graphics view
    cv::cvtColor(frame, frame,CV_BGR2RGB);
    QImage image((const uchar *) frame.data, frame.cols, frame.rows, frame.step, QImage::Format_RGB888);

    m_scene->addPixmap(QPixmap::fromImage(image));
}
