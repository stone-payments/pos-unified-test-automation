#ifndef POSTESTTOOL_H
#define POSTESTTOOL_H

#include "printercontroller.h"
#include "visionworker.h"
#include "cardcontroller.h"
#include "keyboardcontroller.h"
#include "touchcontroller.h"
#include "model/posobjectbuilder.h"

class PosTestTool
{
public:
    PosTestTool(PosModel device);

    void insertCard();

    void removeCard();

    KeyboardController m_keyboardController;
    PosObject *m_posObject;
private:

    CardController m_cardController;
    TouchController m_touchController;
    PrinterController *m_printerControllerInstance;
    VisionWorker *m_visionWorkerInstance;
};

#endif // POSTESTTOOL_H
