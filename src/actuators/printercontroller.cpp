#include "printercontroller.h"

#include <AtCore/GCodeCommands>
#include <QDebug>

PrinterController::PrinterController()
{
    QString serialPort;
    foreach (const QSerialPortInfo &devinfo, QSerialPortInfo::availablePorts())
    {
        qDebug() << "Serial port: " <<devinfo.portName() ;
        if(devinfo.manufacturer().contains("1a86"))
        {
            serialPort = devinfo.portName();

        }
    }

    if(core.initSerial(serialPort, 115200) == true)
    {
        core.home();
    }
}

void PrinterController::moveAxis(uint dx, uint dy, uint dz)
{
    qDebug() << "MOVE X: " << dx << "\tY: " << dy << "\tZ: " << dz;
    core.setRelativePosition();
    core.pushCommand(GCode::toCommand(GCode::G1, QStringLiteral("%1%2").arg("X", QString::number(dx))));
    core.pushCommand(GCode::toCommand(GCode::G1, QStringLiteral("%1%2").arg("Y", QString::number(dy))));
    core.pushCommand(GCode::toCommand(GCode::G1, QStringLiteral("%1%2").arg("Z", QString::number(dz))));
    core.setAbsolutePosition();
}

void PrinterController::setXYPosition(QPointF point)
{
    core.setAbsolutePosition();
    core.pushCommand(GCode::toCommand(GCode::G1, QStringLiteral("X%1 Y%2").arg(QString::number(point.x()), QString::number(point.y()))));
}

void PrinterController::moveX(float_t dx)
{
    core.setRelativePosition();
    core.pushCommand(GCode::toCommand(GCode::G1, QStringLiteral("%1%2").arg("X", QString::number(dx))));
}

void PrinterController::moveY(float_t dy)
{
    core.setRelativePosition();
    core.pushCommand(GCode::toCommand(GCode::G1, QStringLiteral("%1%2").arg("Y", QString::number(dy))));
}

void PrinterController::moveZ(float_t dz)
{
    core.setAbsolutePosition();
    core.pushCommand(GCode::toCommand(GCode::G1, QStringLiteral("%1%2").arg("Z", QString::number(dz))));
}

void PrinterController::initConnectionToAtCore()
{

}
