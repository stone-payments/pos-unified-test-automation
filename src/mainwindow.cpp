#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "printercontroller.h"
#include <QPixmap>
#include <QPainter>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_posTestTool(new PosTestTool(PosModel::PAX_S920))
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
    ui->cameraVisionView_3->setPixmap(QPixmap::fromImage(VisionWorker::instance().frame_1));
}

void MainWindow::on_buttonMove_clicked()
{
    float dx = ui->dx->text().toFloat();
    float dy = ui->dy->text().toFloat();
    float dz = ui->dz->text().toFloat();

    PrinterController::instance().moveAxis(dx, dy, dz);
}

void MainWindow::on_buttonInsertCard_clicked()
{
    m_posTestTool->insertCard();
    VisionWorker::instance().getBaseOrigin();
}

void MainWindow::on_buttonRemoveCard_clicked()
{
    m_posTestTool->removeCard();
}

void MainWindow::on_buttonKeyPress_clicked()
{
    QChar character(ui->inputKey->text()[0].toLatin1());
    m_posTestTool->m_keyboardController.keyPress((QString)character.unicode());
}

void MainWindow::on_buttonKeyPressAndHold_clicked()
{
    QChar character(ui->inputKey->text()[0].toLatin1());
    m_posTestTool->m_keyboardController.keyPressAndHold((QString)character.unicode(), 2000);
}

void MainWindow::on_buttonKeyDown_clicked()
{
    QChar character(ui->inputKey->text()[0].toLatin1());
    m_posTestTool->m_keyboardController.keyDown((QString)character.unicode());
}

void MainWindow::on_buttonKeyUp_clicked()
{
    m_posTestTool->m_keyboardController.keyUp();
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

void MainWindow::on_pushButton_clicked()
{
    m_posTestTool->m_keyboardController.write(ui->inputKey->text());
}
