#include "keyboardcontroller.h"

const float_t keyZOffset = 1;

KeyboardController::KeyboardController(QObject *parent) : QObject(parent)
{
    m_printerControllerInstance = &PrinterController::instance();
    m_visionWorkerInstance = &VisionWorker::instance();
}

void KeyboardController::keyPress(Qt::Key key)
{
    QPointF charPosition = m_visionWorkerInstance->getCharPosition(QChar(key));
    m_printerControllerInstance->setXYPosition(charPosition);

    m_printerControllerInstance->moveZ(keyZOffset);
    m_printerControllerInstance->moveZ(-keyZOffset);
}

