#include "mainwindow.h"
#include <QPainter>
#include <QPixmap>
#include "model/posobject.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      m_posTestTool(new PosTestTool(PosModel::PAX_S920)) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_buttonKeyboardPress_clicked() {
  m_posTestTool->keyPress(ui->inputKeyboard->text().toStdString());
}

void MainWindow::on_buttonKeyboardWrite_clicked() {
  m_posTestTool->write(ui->inputKeyboard->text().toStdString());
  m_posTestTool->showScreen();
}

void MainWindow::on_buttonCardInsert_clicked() { m_posTestTool->insertCard(); }

void MainWindow::on_buttonCardRemove_clicked() { m_posTestTool->removeCard(); }
