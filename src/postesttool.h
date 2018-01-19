#ifndef POSTESTTOOL_H
#define POSTESTTOOL_H

#include <QObject>
#include "printercontroller.h"
#include "visionworker.h"
#include "cardcontroller.h"
#include "keyboardcontroller.h"
#include "mousecontroller.h"

class PosTestTool : public QObject
{
    Q_OBJECT
public:
    explicit PosTestTool(QObject *parent = nullptr);

    void insertCard();

    void removeCard();
signals:

public slots:

private:
    CardController m_cardController;
    TouchController m_touchController;
    KeyboardController m_keyboardController;
    PrinterController *m_printerControllerInstance;
    VisionWorker *m_visionWorkerInstance;
};

#endif // POSTESTTOOL_H
