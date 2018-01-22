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

    void move(QPointF initialPoint, QPointF finalPoint);
    void click(QPointF point);
    void press(QPointF point);
    void pressAndHold(QPointF point, int millisseconds);
    void release();

private:
    PrinterController *m_printerControllerInstance;
    VisionWorker *m_visionWorkerInstance;
};

#endif // TOUCHCONTROLLER_H
