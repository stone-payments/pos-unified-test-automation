#ifndef KEYBOARDCONTROLLER_H
#define KEYBOARDCONTROLLER_H

#include <QObject>
#include <QKeyEvent>

#include "printercontroller.h"
#include "visionworker.h"
#include "posobject.h"

class KeyboardController : public QObject
{
    Q_OBJECT
public:
    explicit KeyboardController(QObject *parent = nullptr);

    void keyPress(QString key);
    void keyPressAndHold(QString key, int milliseconds);
    void keyDown(QString);
    void keyUp();

    void setDevice(PosObject *device);
private:
    PrinterController *m_printerControllerInstance;
    VisionWorker *m_visionWorkerInstance;
    PosObject *m_device;
};

#endif // KEYBOARDCONTROLLER_H
