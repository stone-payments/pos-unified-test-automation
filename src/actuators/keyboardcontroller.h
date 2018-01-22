#ifndef KEYBOARDCONTROLLER_H
#define KEYBOARDCONTROLLER_H

#include <QObject>
#include <QKeyEvent>
#include "printercontroller.h"
#include "visionworker.h"

class KeyboardController : public QObject
{
    Q_OBJECT
public:
    explicit KeyboardController(QObject *parent = nullptr);

    void keyPress(Qt::Key key);
    void keyPressAndHold(Qt::Key key, int milliseconds);
    void keyDown(Qt::Key);
    void keyUp();
private:
    PrinterController *m_printerControllerInstance;
    VisionWorker *m_visionWorkerInstance;
};

#endif // KEYBOARDCONTROLLER_H
