#ifndef PRINTERCONTROLLER_H
#define PRINTERCONTROLLER_H

#include <QObject>
#include <AtCore/AtCore>

class PrinterController : public QObject
{
    Q_OBJECT
public:
    explicit PrinterController(QObject *parent = nullptr);

    void moveAxis(uint dx, uint dy, uint dz);
signals:

public slots:
private:
    AtCore core;
    void initConnectsToAtCore();
};

#endif // PRINTERCONTROLLER_H
