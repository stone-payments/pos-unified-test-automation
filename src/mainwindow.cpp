#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_scene(new QGraphicsScene(parent)),
    m_visionWorker(new VisionWorker),
    m_printerController(new PrinterController)
{
    ui->setupUi(this);
    ui->cameraView->setScene(m_scene);

    connect(m_visionWorker, &VisionWorker::imageChanged, this, &MainWindow::updateCameraView);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateCameraView(QImage image)
{
    m_scene->addPixmap(QPixmap::fromImage(image));
}

void MainWindow::on_buttonMove_clicked()
{
    uint dx = ui->dx->text().toInt();
    uint dy = ui->dy->text().toInt();
    uint dz = ui->dz->text().toInt();

    m_printerController->moveAxis(dx, dy, dz);
}
