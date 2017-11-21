#include "printercontroller.h"

#include <AtCore/GCodeCommands>
#include <QDebug>

PrinterController::PrinterController(QObject *parent) : QObject(parent)
{
    core.initSerial("ttyUSB0", 115200); // TODO: Auto detect usb port.
    core.home();
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

void PrinterController::initConnectsToAtCore()
{

}
