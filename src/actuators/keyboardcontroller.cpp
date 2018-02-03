#include "keyboardcontroller.h"
#include <chrono>
#include <thread>

const float_t keyZOffset = 5;

KeyboardController::KeyboardController(QObject *parent) :
    QObject(parent),
    m_device(nullptr)
{
    m_printerControllerInstance = &PrinterController::instance();
    m_visionWorkerInstance = &VisionWorker::instance();
}

void KeyboardController::keyPress(QString key)
{
    this->keyUp();
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
    QPair<QPointF, int> charPosition;

    if(m_device != nullptr)
    {
        charPosition = m_device->getKeyPosition(key);
        qDebug() << "char position: " << charPosition;
    }
    else
    {
        charPosition.first = m_visionWorkerInstance->getKeyPosition(key);
    }

    m_printerControllerInstance->setXYPosition(charPosition.first);

    for (int i = 0; i <= charPosition.second; ++i) {
        m_printerControllerInstance->moveZ(0);
        this->keyUp();
    }
}

void KeyboardController::keyUp()
{
    m_printerControllerInstance->moveZ(keyZOffset);
}

void KeyboardController::setDevice(PosObject *device)
{
    m_device = device;
}
