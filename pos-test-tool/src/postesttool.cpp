#include "postesttool.h"
#include "cardcontroller.h"
#include "keyboardcontroller.h"
#include "posobject.h"
#include "posobjectbuilder.h"
#include "printercontroller.h"

#include <QObject>

PosTestTool::PosTestTool(PosModel device)
    : m_keyboardController(new KeyboardController)
    , m_cardController(new CardController)
{

    m_posObject = PosObjectBuilder::getPosObject(device);
    m_printerControllerInstance = &PrinterController::instance();
    m_keyboardController->setDevice(m_posObject);

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

void PosTestTool::keyPress(std::string key)
{
    m_keyboardController->keyPress(QString::fromStdString(key));
}

void PosTestTool::write(std::string text)
{
    m_keyboardController->write(QString::fromStdString(text));
}

void PosTestTool::showScreen()
{
    m_printerControllerInstance->moveZ(10);
    m_printerControllerInstance->moveY(180);
}
