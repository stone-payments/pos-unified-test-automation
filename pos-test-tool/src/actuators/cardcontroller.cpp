#include "cardcontroller.h"
#include <QDebug>
#include <QtSerialPort/QSerialPortInfo>

CardController::CardController(QObject* parent)
    : QObject(parent)
{
    foreach (const QSerialPortInfo& devinfo, QSerialPortInfo::availablePorts()) {
        if (devinfo.description().contains("Arduino")) {
            m_serialPort.setPortName(devinfo.portName());
        }
    }

    m_serialPort.setBaudRate(QSerialPort::Baud115200);
    m_serialPort.setDataBits(QSerialPort::Data8);
    m_serialPort.setFlowControl(QSerialPort::NoFlowControl);
    m_serialPort.setParity(QSerialPort::NoParity);
    m_serialPort.setStopBits(QSerialPort::OneStop);

    if (!m_serialPort.open(QIODevice::ReadWrite)) {
        qCritical() << QObject::tr("Falha ao abrir porta %1, erro: %2")
                           .arg(m_serialPort.portName())
                           .arg(m_serialPort.errorString())
                    << endl;
    }
}

CardController::~CardController() { m_serialPort.close(); }

void CardController::insert() { m_serialPort.write("insert\n"); }

void CardController::remove() { m_serialPort.write("remove\n"); }
