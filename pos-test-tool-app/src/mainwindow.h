#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsScene>
#include <QMainWindow>
#include <QTimer>

#include "postesttool.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow* ui;
    PosTestTool* m_posTestTool;

private slots:
    void on_buttonKeyboardPress_clicked();
    void on_buttonKeyboardWrite_clicked();
    void on_buttonCardInsert_clicked();
    void on_buttonCardRemove_clicked();
};

#endif // MAINWINDOW_H
