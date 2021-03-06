#include "printercontroller.h"

#include <AtCore/GCodeCommands>
#include <QDebug>
#include <QtSerialPort>

PrinterController::PrinterController(QObject* parent)
    : QObject(parent)
{
    QString serialPort;
    foreach (const QSerialPortInfo& devinfo, QSerialPortInfo::availablePorts()) {
        qDebug() << "Serial port: " << devinfo.portName();
        if (devinfo.manufacturer().contains("1a86")) {
            serialPort = devinfo.portName();
        }
    }

    if (core.initSerial(serialPort, QSerialPort::Baud115200) == true) {
        core.home();
        moveZ(safeZPosition);
    }
}

PrinterController::~PrinterController()
{
    core.close();
}

void PrinterController::setXYZPosition(qreal x, qreal y, qreal z)
{
    core.setAbsolutePosition();
    core.pushCommand(GCode::toCommand(GCode::G0, QStringLiteral("X%1 Y%2 Z%3").arg(QString::number(x), QString::number(y), QString::number(z))));
}

void PrinterController::setXYPosition(QPointF point)
{
    core.setAbsolutePosition();
    core.pushCommand(GCode::toCommand(GCode::G0, QStringLiteral("X%1 Y%2").arg(QString::number(point.x()), QString::number(point.y()))));
}

void PrinterController::moveX(qreal x)
{
    core.setAbsolutePosition();
    core.pushCommand(GCode::toCommand(GCode::G0, QStringLiteral("%1%2").arg("X", QString::number(x))));
}

void PrinterController::moveY(qreal y)
{
    core.setAbsolutePosition();
    core.pushCommand(GCode::toCommand(GCode::G0, QStringLiteral("%1%2").arg("Y", QString::number(y))));
}

void PrinterController::moveZ(qreal z)
{
    core.setAbsolutePosition();
    core.pushCommand(GCode::toCommand(GCode::G0, QStringLiteral("%1%2").arg("Z", QString::number(z))));
}

void PrinterController::wait(int millisseconds)
{
    core.pushCommand(QStringLiteral("G4 P%1").arg(QString::number(millisseconds)));
}
