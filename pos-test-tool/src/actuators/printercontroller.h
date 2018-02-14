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
    void moveAxis(float dx, float dy, float dz);

    void setXYPosition(QPointF point);

    void moveX(float_t dx);
    void moveY(float_t dy);
    void moveZ(float_t dz);
    void wait(int millisseconds);

    /** Singleton implementation **/
    static PrinterController& instance()
    {
        static PrinterController instance;
        return instance;
    }
    /******************************/

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
