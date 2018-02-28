#include "keyboardcontroller.h"

KeyboardController::KeyboardController(QObject* parent)
    : QObject(parent)
    , m_device(nullptr)
    , m_printerController(nullptr)
{
}

void KeyboardController::write(QString phrase)
{
    if (m_device == nullptr || m_printerController == nullptr) {
        qCritical() << "Device or printer not set up";
        return;
    }

    m_printerController->moveZ(PrinterController::safeZPosition);
    QPair<QPointF, int> lastCharPosition;

    foreach (QChar character, phrase) {
        QPair<QPointF, int> charPosition = m_device->getKeyPosition(character);
        if (charPosition.first == lastCharPosition.first)
            m_printerController->wait(500);

        keyPress(character);
        lastCharPosition = charPosition;
    }
    m_printerController->moveZ(PrinterController::safeZPosition);
}

void KeyboardController::keyPress(QString key)
{
    if (m_device == nullptr || m_printerController == nullptr) {
        qCritical() << "Device or printer not set up";
        return;
    }

    QPair<QPointF, int> charPosition;
    charPosition = m_device->getKeyPosition(key);
    qDebug() << "char position: " << charPosition;

    if (charPosition.first == QPointF(0, 0)) {
        qCritical() << "charactere not found";
        return;
    }

    m_printerController->moveZ(PrinterController::safeZPosition);
    m_printerController->setXYPosition(charPosition.first);

    for (int i = 0; i <= charPosition.second; ++i) {
        m_printerController->moveZ(0);
        m_printerController->moveZ(PrinterController::safeZPosition / 2);
    }
    m_printerController->moveZ(PrinterController::safeZPosition);
}

void KeyboardController::setDevice(PosObject* device) { m_device = device; }
void KeyboardController::setPrinterController(PrinterController* printerController) { m_printerController = printerController; }
