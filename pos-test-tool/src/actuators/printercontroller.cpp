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

void PrinterController::moveAxis(float dx, float dy, float dz)
{
    // std::count << "MOVE X: " << dx << "\tY: " << dy << "\tZ: " << std::endl;
    core.setRelativePosition();
    core.pushCommand(GCode::toCommand(GCode::G0, QStringLiteral("X%1 Y%2 Z%3").arg(QString::number(dx), QString::number(dy), QString::number(dz))));
}

void PrinterController::setXYPosition(QPointF point)
{
    core.setAbsolutePosition();
    core.pushCommand(GCode::toCommand(GCode::G0, QStringLiteral("X%1 Y%2").arg(QString::number(point.x()), QString::number(point.y()))));
}

void PrinterController::moveX(float_t dx)
{
    core.setRelativePosition();
    core.pushCommand(GCode::toCommand(GCode::G0, QStringLiteral("%1%2").arg("X", QString::number(dx))));
}

void PrinterController::moveY(float_t dy)
{
    core.setRelativePosition();
    core.pushCommand(GCode::toCommand(GCode::G0, QStringLiteral("%1%2").arg("Y", QString::number(dy))));
}

void PrinterController::moveZ(float_t dz)
{
    core.setAbsolutePosition();
    core.pushCommand(GCode::toCommand(GCode::G0, QStringLiteral("%1%2").arg("Z", QString::number(dz))));
}

void PrinterController::wait(int millisseconds)
{
    core.pushCommand(QStringLiteral("G4 P%1").arg(QString::number(millisseconds)));
}

void PrinterController::initConnectionToAtCore()
{

}
