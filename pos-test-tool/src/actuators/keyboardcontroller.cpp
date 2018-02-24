#include "keyboardcontroller.h"

KeyboardController::KeyboardController(QObject* parent)
    : QObject(parent)
    , m_device(nullptr)
{
    m_printerControllerInstance = &PrinterController::instance();
}

void KeyboardController::write(QString phrase)
{
    m_printerControllerInstance->moveZ(m_safeZPosition);
    QPair<QPointF, int> lastCharPosition;

    foreach (QChar character, phrase) {
        QPair<QPointF, int> charPosition = m_device->getKeyPosition(character);
        if (charPosition.first == lastCharPosition.first)
            m_printerControllerInstance->wait(500);

        keyPress(character);
        lastCharPosition = charPosition;
    }
    m_printerControllerInstance->moveZ(m_safeZPosition);
}

void KeyboardController::keyPress(QString key)
{
    QPair<QPointF, int> charPosition;
    charPosition = m_device->getKeyPosition(key);
    qDebug() << "char position: " << charPosition;

    m_printerControllerInstance->setXYPosition(charPosition.first);

    for (int i = 0; i <= charPosition.second; ++i) {
        m_printerControllerInstance->moveZ(0);
        m_printerControllerInstance->moveZ(m_safeZPosition / 2);
    }
    m_printerControllerInstance->moveZ(m_safeZPosition);
}

void KeyboardController::setDevice(PosObject* device) { m_device = device; }
