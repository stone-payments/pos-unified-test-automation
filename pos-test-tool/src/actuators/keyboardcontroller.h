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

    void write(QString phrase);

    void keyPress(QString key);

    void setDevice(PosObject *device);
private:
    PrinterController *m_printerControllerInstance;
    VisionWorker *m_visionWorkerInstance;
    PosObject *m_device;
};

#endif // KEYBOARDCONTROLLER_H
