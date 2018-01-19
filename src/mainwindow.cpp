#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_scene(new QGraphicsScene(parent)),
    m_visionWorker(new VisionWorker),
    m_cardController(new CardController)
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

    PrinterController::instance().moveAxis(dx, dy, dz);
}

void MainWindow::on_buttonInsertCard_clicked()
{
    m_cardController->insert();
}

void MainWindow::on_buttonRemoveCard_clicked()
{
    m_cardController->remove();
}
