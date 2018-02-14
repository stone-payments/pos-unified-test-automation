#include "postesttool.h"
#include "printercontroller.h"
#include "visionworker.h"
#include "cardcontroller.h"
#include "keyboardcontroller.h"
#include "touchcontroller.h"
#include "posobjectbuilder.h"
#include "posobject.h"

#include <QObject>

PosTestTool::PosTestTool(PosModel device):
    m_keyboardController(new KeyboardController),
    m_cardController(new CardController),
    m_touchController(new TouchController)
{
    m_posObject = PosObjectBuilder::getPos(device);
    m_printerControllerInstance = &PrinterController::instance();
    m_visionWorkerInstance = &VisionWorker::instance();
    m_keyboardController->setDevice(m_posObject);
    m_visionWorkerInstance->setDevice(m_posObject);
    m_visionWorkerInstance->calibrate();

    connect(m_visionWorkerInstance, &VisionWorker::imageChanged, this, [this](QImage newImage){
        emit cameraImageChanged(newImage);
    });

    showScreen();
}

void PosTestTool::insertCard()
{
    m_cardController->insert();
}

void PosTestTool::removeCard()
{
    m_cardController->remove();
}

void PosTestTool::keyPress(QString key)
{
    m_keyboardController->keyPress(key);
}

void PosTestTool::write(QString text)
{
    m_keyboardController->write(text);
}

void PosTestTool::showScreen()
{
    m_printerControllerInstance->moveZ(10);
    m_printerControllerInstance->moveY(180);
}
