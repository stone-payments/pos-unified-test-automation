#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>

#include "postesttool.h"

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
    KeyboardController m_keyBoardController;
    TouchController m_touchController;
    PosTestTool *m_posTestTool;

private slots:
    void updateCameraView(QImage);
    void on_buttonMove_clicked();
    void on_buttonInsertCard_clicked();
    void on_buttonRemoveCard_clicked();
    void on_buttonKeyPress_clicked();
    void on_buttonKeyPressAndHold_clicked();
    void on_buttonKeyDown_clicked();
    void on_buttonKeyUp_clicked();
    void on_buttonTouchClick_clicked();
    void on_buttonTouchPress_clicked();
    void on_buttonTouchPressAndHold_clicked();
    void on_buttonTouchMove_clicked();
};

#endif // MAINWINDOW_H
