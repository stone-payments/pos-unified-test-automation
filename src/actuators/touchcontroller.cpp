#include "touchcontroller.h"
#include <chrono>
#include <thread>

const float_t touchZOffset = 1;

TouchController::TouchController(QObject *parent): QObject(parent)
{
    m_printerControllerInstance = &PrinterController::instance();
    m_visionWorkerInstance = &VisionWorker::instance();
}

void TouchController::move(QPointF initialPoint, QPointF finalPoint)
{
    this->press(initialPoint);
    m_printerControllerInstance->setXYPosition(finalPoint);
    this->release();
}

void TouchController::click(QPointF point)
{
    this->press(point);
    this->release();
}

void TouchController::pressAndHold(QPointF point, int milliseconds)
{
    this->press(point);
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
    this->release();
}

void TouchController::press(QPointF coordinates)
{
    m_printerControllerInstance->setXYPosition(coordinates);
    m_printerControllerInstance->moveZ(touchZOffset);
}


void TouchController::release()
{
    m_printerControllerInstance->moveZ(-touchZOffset);
}

