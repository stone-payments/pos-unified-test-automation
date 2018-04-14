#include "postesttool.h"
#include "cardcontroller.h"
#include "keyboardcontroller.h"
#include "posobject.h"
#include "posobjectfactory.h"
#include "printercontroller.h"

#include <QObject>

PosTestTool::PosTestTool(PosModel device)
    : m_keyboardController(new KeyboardController(this))
    , m_cardController(new CardController(this))
    , m_printerController(new PrinterController(this))
{
    m_posObject = PosObjectFactory::getPosObject(device);
    m_keyboardController->setDevice(m_posObject);
    m_keyboardController->setPrinterController(m_printerController);
}

PosTestTool::~PosTestTool()
{
    delete m_posObject;
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
    m_printerController->moveZ(PrinterController::safeZPosition);
    m_printerController->moveY(180);
}
