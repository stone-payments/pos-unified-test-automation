#ifndef PRINTERCONTROLLER_H
#define PRINTERCONTROLLER_H

#include <AtCore/AtCore>
#include <QObject>
#include <math.h>

class PrinterController : public QObject {
    Q_OBJECT
public:
    explicit PrinterController(QObject* parent = nullptr);
    ~PrinterController();
    void setXYZPosition(qreal x, qreal y, qreal z);

    void setXYPosition(QPointF point);

    void moveX(qreal x);
    void moveY(qreal y);
    void moveZ(qreal z);
    void wait(int millisseconds);

    static const int safeZPosition = 5;

private:
    AtCore core;
};

#endif // PRINTERCONTROLLER_H
