#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&VisionWorker::instance(), &VisionWorker::imageChanged, this, &MainWindow::updateCameraView);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateCameraView(QImage image)
{
    ui->cameraView->setPixmap(QPixmap::fromImage(image));
}

void MainWindow::on_buttonMove_clicked()
{
    uint dx = ui->dx->text().toInt();
    uint dy = ui->dy->text().toInt();
    uint dz = ui->dz->text().toInt();

    PrinterController::instance().moveAxis(dx, dy, dz);
}

void MainWindow::on_buttonInsertCard_clicked()
{
    m_posTestTool.insertCard();
}

void MainWindow::on_buttonRemoveCard_clicked()
{
    m_posTestTool.removeCard();
}
