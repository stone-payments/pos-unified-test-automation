#ifndef PRINTERCONTROLLER_H
#define PRINTERCONTROLLER_H

#include <QObject>
#include <AtCore/AtCore>
#include <math.h>
#include "visionworker.h"

class PrinterController : public QObject
{
    Q_OBJECT
public:
    void setXYZPosition(float x, float y, float z);

    void setXYPosition(QPointF point);

    void moveX(float x);
    void moveY(float y);
    void moveZ(float z);
    void wait(int millisseconds);

    /** Singleton implementation **/
    static PrinterController& instance()
    {
        static PrinterController instance;
        return instance;
    }
    /******************************/

signals:
    void printerIdle();

    void printerBusy();

private:
    /** Singleton implementation **/
    PrinterController();
    PrinterController (PrinterController const&);
    PrinterController& operator=(PrinterController const&);
    /******************************/

    AtCore core;
    void initConnectionToAtCore();
};

#endif // PRINTERCONTROLLER_H
