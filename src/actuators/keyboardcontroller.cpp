#include "keyboardcontroller.h"
#include <chrono>
#include <thread>

const float_t keyZOffset = 1;

KeyboardController::KeyboardController(QObject *parent) :
    QObject(parent),
    m_device(nullptr)
{
    m_printerControllerInstance = &PrinterController::instance();
    m_visionWorkerInstance = &VisionWorker::instance();
}

void KeyboardController::keyPress(QString key)
{
    this->keyDown(key);
    this->keyUp();
}

void KeyboardController::keyPressAndHold(QString key, int milliseconds)
{
    this->keyDown(key);
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
    this->keyUp();
}

void KeyboardController::keyDown(QString key)
{
    QPointF charPosition;

    if(m_device != nullptr)
    {
        charPosition = m_device->getKeyPosition(key);
    }
    else
    {
        charPosition = m_visionWorkerInstance->getKeyPosition(key);
    }

    m_printerControllerInstance->setXYPosition(charPosition);

    m_printerControllerInstance->moveZ(keyZOffset);
}

void KeyboardController::keyUp()
{
    m_printerControllerInstance->moveZ(-keyZOffset);
}

void KeyboardController::setDevice(PosObject *device)
{
    m_device = device;
}
