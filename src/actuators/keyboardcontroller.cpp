#include "keyboardcontroller.h"
#include <chrono>
#include <thread>

const float_t keyZOffset = 1;

KeyboardController::KeyboardController(QObject *parent) : QObject(parent)
{
    m_printerControllerInstance = &PrinterController::instance();
    m_visionWorkerInstance = &VisionWorker::instance();
}

void KeyboardController::keyPress(Qt::Key key)
{
    this->keyDown(key);
    this->keyUp();
}

void KeyboardController::keyPressAndHold(Qt::Key key, int milliseconds)
{
    this->keyDown(key);
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
    this->keyUp();
}

void KeyboardController::keyDown(Qt::Key key)
{
    QPointF charPosition = m_visionWorkerInstance->getCharPosition(QChar(key));
    m_printerControllerInstance->setXYPosition(charPosition);

    m_printerControllerInstance->moveZ(keyZOffset);
}

void KeyboardController::keyUp()
{
    m_printerControllerInstance->moveZ(-keyZOffset);
}
