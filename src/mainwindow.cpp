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
    ui->cameraRawView->setPixmap(QPixmap::fromImage(image));
    ui->cameraVisionView_1->setPixmap(QPixmap::fromImage(image));
    ui->cameraVisionView_2->setPixmap(QPixmap::fromImage(image));
    ui->cameraVisionView_3->setPixmap(QPixmap::fromImage(image));
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

void MainWindow::on_buttonKeyPress_clicked()
{
    QChar character(ui->inputKey->text()[0].toLatin1());
    m_keyBoardController.keyPress((Qt::Key)character.unicode());
}

void MainWindow::on_buttonKeyPressAndHold_clicked()
{
    QChar character(ui->inputKey->text()[0].toLatin1());
    m_keyBoardController.keyPressAndHold((Qt::Key)character.unicode(), 2000);
}

void MainWindow::on_buttonKeyDown_clicked()
{
    QChar character(ui->inputKey->text()[0].toLatin1());
    m_keyBoardController.keyDown((Qt::Key)character.unicode());
}

void MainWindow::on_buttonKeyUp_clicked()
{
    m_keyBoardController.keyUp();
}

void MainWindow::on_buttonTouchClick_clicked()
{
    QPointF point(ui->inputTouchX->text().toFloat(), ui->inputTouchY->text().toFloat());
    m_touchController.click(point);
}

void MainWindow::on_buttonTouchPress_clicked()
{
    QPointF point(ui->inputTouchX->text().toFloat(), ui->inputTouchY->text().toFloat());
    m_touchController.press(point);
}

void MainWindow::on_buttonTouchPressAndHold_clicked()
{
    QPointF point(ui->inputTouchX->text().toFloat(), ui->inputTouchY->text().toFloat());
    m_touchController.pressAndHold(point, 2000);
}

void MainWindow::on_buttonTouchMove_clicked()
{
    QPointF initialPoint(ui->inputTouchX->text().toFloat(), ui->inputTouchY->text().toFloat());
    QPointF finalPoint(ui->inputTouchX->text().toFloat(), ui->inputTouchY->text().toFloat());
    m_touchController.move(initialPoint, finalPoint);
}
