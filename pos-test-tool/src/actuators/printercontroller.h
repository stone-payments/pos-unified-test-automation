#ifndef PRINTERCONTROLLER_H
#define PRINTERCONTROLLER_H

#include <AtCore/AtCore>
#include <QObject>
#include <math.h>

class PrinterController : public QObject {
    Q_OBJECT
public:
    void setXYZPosition(qreal x, qreal y, qreal z);

    void setXYPosition(QPointF point);

    void moveX(qreal x);
    void moveY(qreal y);
    void moveZ(qreal z);
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
    PrinterController(PrinterController const&);
    PrinterController& operator=(PrinterController const&);
    /******************************/

    AtCore core;
};

#endif // PRINTERCONTROLLER_H
