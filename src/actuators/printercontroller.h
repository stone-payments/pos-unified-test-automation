#ifndef PRINTERCONTROLLER_H
#define PRINTERCONTROLLER_H

#include <QObject>
#include <AtCore/AtCore>

class PrinterController : public QObject
{
    Q_OBJECT
public:
    void moveAxis(uint dx, uint dy, uint dz);

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
