#ifndef KEYBOARDCONTROLLER_H
#define KEYBOARDCONTROLLER_H

#include <QKeyEvent>
#include <QObject>

#include "posobject.h"
#include "printercontroller.h"

class KeyboardController : public QObject {
    Q_OBJECT
public:
    explicit KeyboardController(QObject* parent = nullptr);
    void write(QString phrase);
    void keyPress(QString key);
    void setDevice(PosObject* device);
    void setPrinterController(PrinterController* PrinterController);

private:
    PosObject* m_device;
    PrinterController* m_printerController;
};

#endif // KEYBOARDCONTROLLER_H
