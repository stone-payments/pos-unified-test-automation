#ifndef TOUCHCONTROLLER_H
#define TOUCHCONTROLLER_H

#include <QObject>
#include "printercontroller.h"
#include "visionworker.h"

class TouchController: public QObject
{
    Q_OBJECT
public:
    explicit TouchController(QObject *parent = nullptr);

    void move(int dx, int dy);
    void click(int x, int y);
    void press(int x, int y);
    void release();

private:
    PrinterController *m_printerControllerInstance;
    VisionWorker *m_visionWorkerInstance;
};

#endif // TOUCHCONTROLLER_H
