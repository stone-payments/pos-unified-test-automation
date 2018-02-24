#include "postesttool.h"
#include "cardcontroller.h"
#include "keyboardcontroller.h"
#include "posobject.h"
#include "posobjectbuilder.h"
#include "printercontroller.h"
#include "touchcontroller.h"

#include <QObject>

PosTestTool::PosTestTool(PosModel device)
    : m_keyboardController(new KeyboardController),
      m_cardController(new CardController),
      m_touchController(new TouchController),
      m_isIdle(false) {
  m_posObject = PosObjectBuilder::getPosObject(device);
  m_printerControllerInstance = &PrinterController::instance();
  m_keyboardController->setDevice(m_posObject);

  showScreen();

  connect(m_printerControllerInstance, &PrinterController::printerIdle, this,
          [this]() {
            emit idle();
            m_isIdle = true;
          });

  connect(m_printerControllerInstance, &PrinterController::printerBusy, this,
          [this]() {
            emit busy();
            m_isIdle = false;
          });
}

void PosTestTool::insertCard() { m_cardController->insert(); }

void PosTestTool::removeCard() { m_cardController->remove(); }

void PosTestTool::keyPress(std::string key) {
  m_keyboardController->keyPress(QString::fromStdString(key));
}

void PosTestTool::write(std::string text) {
  m_keyboardController->write(QString::fromStdString(text));
}

void PosTestTool::showScreen() {
  m_printerControllerInstance->moveZ(10);
  m_printerControllerInstance->moveY(180);
}

bool PosTestTool::isIdle() { return m_isIdle; }
