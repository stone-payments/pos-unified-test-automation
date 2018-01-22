#include "keyboardcontroller.h"

KeyboardController::KeyboardController(QObject *parent) : QObject(parent)
{
    m_printerControllerInstance = &PrinterController::instance();
    m_visionWorkerInstance = &VisionWorker::instance();
}
