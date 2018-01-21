#ifndef KEYBOARDCONTROLLER_H
#define KEYBOARDCONTROLLER_H

#include <QObject>
#include "printercontroller.h"
#include "visionworker.h"

class KeyboardController : public QObject
{
    Q_OBJECT
public:
    explicit KeyboardController(QObject *parent = nullptr);

    void keyPress(int key);
    void keyPressAndHold(int key, int milliseconds);
    void keyDown(int key);
    void keyUp();
signals:

public slots:

private:
    PrinterController *m_printerControllerInstance;
    VisionWorker *m_visionWorkerInstance;
};

#endif // KEYBOARDCONTROLLER_H
