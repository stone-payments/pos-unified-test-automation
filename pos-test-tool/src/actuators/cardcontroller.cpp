#include "cardcontroller.h"
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>

CardController::CardController()
{
    foreach (const QSerialPortInfo &devinfo, QSerialPortInfo::availablePorts())
    {
        if(devinfo.description().contains("Arduino"))
        {
            m_serialPort.setPortName(devinfo.portName());
        }
    }

    m_serialPort.setBaudRate(115200);
    m_serialPort.setDataBits(QSerialPort::Data8);
    m_serialPort.setFlowControl(QSerialPort::NoFlowControl);
    m_serialPort.setParity(QSerialPort::NoParity);
    m_serialPort.setStopBits(QSerialPort::OneStop);

    if (!m_serialPort.open(QIODevice::ReadWrite)) {
        qDebug() << QObject::tr("Falha ao abrir porta %1, erro: %2").arg(m_serialPort.portName()).arg(m_serialPort.errorString()) << endl;
    }
}

CardController::~CardController()
{
    m_serialPort.close();
}

void CardController::insert()
{
    m_serialPort.write("insert\n");
}

void CardController::remove()
{
    m_serialPort.write("remove\n");
}

