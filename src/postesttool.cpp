#include "postesttool.h"


PosTestTool::PosTestTool(PosModel device)
{
    m_posObject = PosObjectBuilder::getPos(device);
    m_printerControllerInstance = &PrinterController::instance();
    m_visionWorkerInstance = &VisionWorker::instance();
}

void PosTestTool::insertCard()
{
    m_cardController.insert();
}

void PosTestTool::removeCard()
{
    m_cardController.remove();
}
