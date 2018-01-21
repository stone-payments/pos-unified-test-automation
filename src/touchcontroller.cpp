#include "touchcontroller.h"

TouchController::TouchController(QObject *parent): QObject(parent)
{
    m_printerControllerInstance = &PrinterController::instance();
    m_visionWorkerInstance = &VisionWorker::instance();
}
