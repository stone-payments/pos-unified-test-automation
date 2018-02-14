#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "model/posobject.h"
#include <QPixmap>
#include <QPainter>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_posTestTool(new PosTestTool(PosModel::PAX_S920))
{
    ui->setupUi(this);
    connect(m_posTestTool, &PosTestTool::cameraImageChanged, this, &MainWindow::updateCameraView);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateCameraView(QImage image)
{
    ui->cameraView->setPixmap(QPixmap::fromImage(image));
}

void MainWindow::on_buttonKeyboardPress_clicked()
{
    m_posTestTool->keyPress(ui->inputKeyboard->text());
}

void MainWindow::on_buttonKeyboardWrite_clicked()
{
    m_posTestTool->write(ui->inputKeyboard->text());
}

void MainWindow::on_buttonCardInsert_clicked()
{
    m_posTestTool->insertCard();
}

void MainWindow::on_buttonCardRemove_clicked()
{
    m_posTestTool->removeCard();
}
