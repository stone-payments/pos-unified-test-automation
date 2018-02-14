#ifndef POSTESTTOOL_H
#define POSTESTTOOL_H

#include "pos-test-tool_global.h"
#include "printercontroller.h"
#include "visionworker.h"
#include "cardcontroller.h"
#include "keyboardcontroller.h"
#include "touchcontroller.h"
#include "model/posobjectbuilder.h"

class POSTESTTOOLSHARED_EXPORT PosTestTool
{
public:
    PosTestTool(PosModel device);

    void insertCard();

    void removeCard();

private:
    KeyboardController m_keyboardController;
    CardController m_cardController;
    TouchController m_touchController;
    PrinterController *m_printerControllerInstance;
    VisionWorker *m_visionWorkerInstance;
    PosObject *m_posObject;
};

#endif // POSTESTTOOL_H
