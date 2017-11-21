#include "gpio.h"
#include <QDebug>
#include <QFile>
#include <QTextStream>


const QString GPIO::gpioExportFilePath = "/sys/class/gpio/export";
const QString GPIO::gpioUnexportFilePath = "/sys/class/gpio/unexport";
const QString GPIO::gpioDirectionFilePath = "/sys/class/gpio/gpio%1/direction";
const QString GPIO::gpioEdgeFilePath = "/sys/class/gpio/gpio%1/edge";
const QString GPIO::gpioValueFilePath = "/sys/class/gpio/gpio%1/value";
const QString GPIO::gpioFilePath = "/sys/class/gpio/gpio%1";


/**
 * @brief GPIO::GPIO
 * @param parent
 */
GPIO::GPIO(QObject *parent) : QObject(parent)
{
    //Ao construir o objeto configuro o timeout do QTimer para o slot TimeoutTimer()
    connect(m_timerGPIO, SIGNAL(timeout()), this, SLOT(TimeoutTimer()));
}

/**
 * @brief GPIO::GPIO
 * @param gpioNumber
 * @param parent
 */
GPIO::GPIO(quint32 gpioNumber)
{
    // Configura a variavel privada com o Numero de GPIO informado
    this->m_gpioNumber = gpioNumber;

    //Ao construir o objeto configuro o timeout do QTimer para o slot TimeoutTimer()
    connect(m_timerGPIO, SIGNAL(timeout()), this, SLOT(TimeoutTimer()));
}

/**
 * @brief GPIO::~GPIO
 */
GPIO::~GPIO()
{
    gpioUnexport();
}

/**
 * @brief GPIO::gpioExport
 * @return
 */
int GPIO::gpioExport()
{
    if (gpioExported()) {
        qWarning() << "Cannot export the gpio pin since it is already exported:" << m_gpioNumber;
        return -1;
    }

    QFile gpioExportFile(gpioExportFilePath);
    if (!gpioExportFile.open(QIODevice::Append)) {
        qCritical() << "Cannot open the gpio export file:" << gpioExportFilePath;
        return -1;
    }

    // Seek to begining of the file
    gpioExportFile.seek(0);

    // Write value in file GPIO
    if (gpioExportFile.write(QByteArray::number(m_gpioNumber)) == -1) {
        qCritical() << Q_FUNC_INFO << "Error while writing the file:" << gpioExportFilePath;
        gpioExportFile.close();

        return -1;
    }

    gpioExportFile.close();

    return 0;

}

/**
 * @brief GPIO::gpioUnexport
 * @return
 */
int GPIO::gpioUnexport()
{
    if (!gpioExported()) {
        // TODO: Proper error mutator mechanism for storing different error
        // enumeration values internally that can be requested by the API user

        qDebug() << "Cannot unexport the gpio pin since it is not exported yet:" << m_gpioNumber;
        return -1;
    }

    QFile gpioUnexportFile(gpioUnexportFilePath);
    if (!gpioUnexportFile.open(QIODevice::Append)) {
        qCritical() << "Cannot open the gpio export file:" << gpioUnexportFilePath;
        return -1;
    }

    // Seek to begining of the file
    gpioUnexportFile.seek(0);

    // Write value in file GPIO
    if (gpioUnexportFile.write(QByteArray::number(m_gpioNumber)) == -1) {
        qDebug() << Q_FUNC_INFO << "Error while writing the file:" << gpioUnexportFilePath;
        gpioUnexportFile.close();

        return -1;
    }

    gpioUnexportFile.close();

    return 0;
}

/**
 * @brief GPIO::gpioExported
 * @return
 */
bool GPIO::gpioExported()
{
    if (!QFile(gpioFilePath.arg(m_gpioNumber)).exists()) {
        return false;
    }

    return true;
}

/**
 * @brief GPIO::direction
 * @return
 */
GPIO::Direction GPIO::direction() const
{
    /*
     * EXISTE UMA FALHA NESTA FUNÇÃO:
     *   EXERCICIO PARA PENSAR E RESOLVER
     */

    QString valueDirection;
    Direction vDirection;

    QFile gpioDirectionFile(gpioDirectionFilePath.arg(m_gpioNumber));
    if (!gpioDirectionFile.open(QIODevice::ReadOnly)) {
        qDebug() << "Cannot open the relevant gpio value file:" << gpioDirectionFilePath.arg(m_gpioNumber);
        gpioDirectionFile.close();
        //return -1;
    }

    QTextStream stream(&gpioDirectionFile);
    stream >> valueDirection;

    if (stream.status() != 0)
    {
        qCritical() << "Failed to read GPIO value";
        //return -1;
    }

    if (valueDirection.contains("out"))
    {
        gpioDirectionFile.close();
        vDirection = Direction::Output;
    }
    else if (valueDirection.contains("in"))
    {
        gpioDirectionFile.close();
        vDirection = Direction::Input;
    }
    else {
        vDirection = Direction::Undef;
    }

    return(vDirection);
}

/**
 * @brief GPIO::setDirection
 * @param direction
 * @return
 */
int GPIO::setDirection(GPIO::Direction direction)
{
    if (!gpioExported()) {
        if (gpioExport() == -1) {
            return -1;
        }
    }

    QFile gpioDirectionFile(gpioDirectionFilePath.arg(m_gpioNumber));

    if (!gpioDirectionFile.open(QIODevice::ReadWrite)) {
        qDebug() << "Cannot open the relevant gpio direction file:" << gpioDirectionFilePath;
        return -1;
    }

    int retval = 0;

    // Seek to begining of the file
    gpioDirectionFile.seek(0);

    // Write value in file GPIO
    switch (direction) {

    case Output:
        if (gpioDirectionFile.write("out") == -1) {
            qCritical() << Q_FUNC_INFO << "Error while writing the file:" << gpioDirectionFilePath;
            retval = -1;
        }

        break;

    case Input:
        if (gpioDirectionFile.write("in") == -1) {
            qCritical() << Q_FUNC_INFO << "Error while writing the file:" << gpioDirectionFilePath;
            retval = -1;
        }

        break;

    default:

        break;

    }

    // Close file descriptor of the GPIO opened
    gpioDirectionFile.close();

    return retval;
}

/**
 * @brief GPIO::edge
 * @return
 */
GPIO::Edge GPIO::edge() const
{
    /* EXERCICIO IMPLEMENTAR */
    return GPIO::Edge::None;
}

/**
 * @brief GPIO::setEdge
 * @param edge
 * @return
 */
int GPIO::setEdge(GPIO::Edge edge)
{
    if (!gpioExported()) {
        if (gpioExport() == -1) {
            return -1;
        }
    }

    QFile gpioEdgeFile(gpioEdgeFilePath.arg(m_gpioNumber));

    if (!gpioEdgeFile.open(QIODevice::ReadWrite)) {
        qCritical() << "Cannot open the relevant gpio edge file:" << gpioEdgeFilePath;
        return -1;
    }

    int retval = 0;

    // Seek to begining of the file
    gpioEdgeFile.seek(0);

    // Write value in file GPIO
    switch (edge) {

    case None:
        if (gpioEdgeFile.write("none") == -1) {
            qDebug() << Q_FUNC_INFO << "Error while writing the file:" << gpioEdgeFilePath;
            retval = -1;
        }
        break;

    case Falling:
        if (gpioEdgeFile.write("falling") == -1) {
            qDebug() << Q_FUNC_INFO << "Error while writing the file:" << gpioEdgeFilePath;
            retval = -1;
        }
        break;

    case Rising:
        if (gpioEdgeFile.write("rising") == -1) {
            qDebug() << Q_FUNC_INFO << "Error while writing the file:" << gpioEdgeFilePath;
            retval = -1;
        }
        break;

    case Both:
        if (gpioEdgeFile.write("both") == -1) {
            qDebug() << Q_FUNC_INFO << "Error while writing the file:" << gpioEdgeFilePath;
            retval = -1;
        }
        break;

    default:

        break;

    }

    // Close file descriptor of the GPIO opened
    gpioEdgeFile.close();

    return retval;

}

/**
 * @brief GPIO::value
 * @return
 */
qint32 GPIO::value() const
{
    qint32 valueGPIO;

    QFile gpioValueFile(gpioValueFilePath.arg(m_gpioNumber));
    if (!gpioValueFile.open(QIODevice::ReadOnly)) {
        qDebug() << "Cannot open the relevant gpio value file:" << gpioValueFilePath.arg(m_gpioNumber);
        gpioValueFile.close();
        return -1;
    }

    QTextStream stream(&gpioValueFile);
    stream >> valueGPIO;

    if (stream.status() != 0)
    {
        qDebug() << "Failed to read GPIO value";
        return -1;
    }

    gpioValueFile.close();

    return valueGPIO;
}

/**
 * @brief GPIO::setValue
 * @param value
 * @return
 */
int GPIO::setValue(GPIO::Level value)
{
    if (direction() != GPIO::Output) {
        qDebug() << "Cannot set the value for an input gpio pin:" << m_gpioNumber;
        return -1;
    }

    QFile gpioValueFile(gpioValueFilePath.arg(m_gpioNumber));
    if (!gpioValueFile.open(QIODevice::ReadWrite)) {
        qDebug() << "Cannot open the relevant gpio value file:" << gpioValueFilePath.arg(m_gpioNumber);
        gpioValueFile.close();
        return -1;
    }

    // Seek to begining of the file
    gpioValueFile.seek(0);

    // Write value in file GPIO
    if (gpioValueFile.write(QByteArray::number(value)) == -1) {
        qDebug() << Q_FUNC_INFO << "Error while writing the file:" << gpioValueFilePath.arg(m_gpioNumber);
        gpioValueFile.close();
        return -1;
    }

    // Close file descriptor of the GPIO opened
    gpioValueFile.close();

    return 0;
}

/**
 * @brief GPIO::getOutput
 * @return
 */
int GPIO::getOutput() const
{
    return(m_valueOutput);
}

/**
 * @brief GPIO::setOutput
 * @param value
 */
void GPIO::setOutput(int value)
{
    qDebug() << "Setando Output como " << value << endl;

    m_valueOutput = value;

    switch (value) {
    case GPIO::Level::High:
        setValue(Level::High);
        break;
    case GPIO::Level::Low:
        setValue(Level::Low);
        break;
    }
}

/**
 * @brief GPIO::getInput
 * @return
 */
int GPIO::getInput() const
{
    return(value());
}

/**
 * @brief GPIO::setInput
 * @param value
 */
void GPIO::setInput(int value)
{
    if (m_valueInput != value)
    {
        m_valueInput = value;

        emit inputChanged();
    }
}

/**
 * @brief GPIO::setGPIOInput
 * @param gpio
 */
void GPIO::setGPIOInput(int gpio)
{
    if (gpioExported())
        cleanGPIO();

    if (!gpioExported())
    {
        setGpioNumber(gpio);
        gpioExport();
        setDirection(Direction::Input);
    }
}

/**
 * @brief GPIO::setGPIOOutput
 * @param gpio
 */
void GPIO::setGPIOOutput(int gpio)
{
    if (gpioExported())
        cleanGPIO();

    if (!gpioExported())
    {
        setGpioNumber(gpio);
        gpioExport();
        setDirection(Direction::Output);
    }
}

/**
 * @brief GPIO::cleanGPIO
 */
void GPIO::cleanGPIO()
{
    this->gpioUnexport();
}

/**
 * @brief GPIO::StartMonitor
 */
void GPIO::StartMonitor()
{
    m_timerGPIO->setInterval(1000);
    m_timerGPIO->start();
}

/**
 * @brief GPIO::StartMonitor
 * @param msecs
 */
void GPIO::StartMonitor(const quint32 msecs)
{
    m_timerGPIO->setInterval(msecs);
    m_timerGPIO->start();
}

/**
 * @brief GPIO::StopMonitor
 */
void GPIO::StopMonitor()
{
    m_timerGPIO->stop();
}

/**
 * @brief GPIO::getCPU
 * @return
 */
QString GPIO::getCPU()
{
    /*
     *
     * # cat /proc/device-tree/model
     * Toradex Colibri iMX6DL/S on Colibri Evaluation Board V3
     */
    QFile cpuinfo("/proc/device-tree/model");

    if (cpuinfo.exists() && cpuinfo.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&cpuinfo);
        QString line;
        line = stream.readLine();

        if (line.contains("Colibri iMX6"))
        {
            qDebug().noquote() << "SoM Detected Colibri i.MX6"<< endl;
            return("Toradex Colibri i.MX6");
        }
        else if (line.contains("Colibri iMX7"))
        {
            qDebug().noquote() << "SoM Detected Colibri i.MX7"<< endl;
            return("Toradex Colibri i.MX7");
        }
        else if (line.contains("Apalis"))
        {
            qDebug().noquote() << "SoM Detected Apalis i.MX6Q"<< endl;
            return("Toradex Apalis i.MX6Q");
        }
        else
        {
            qDebug().noquote() << "SoM Toradex not detected!"<< endl;
            return("SoM Toradex not detected!");
        }
    }
    else
    {
        return("SoM Toradex not detected!");
    }

}

/**
 * @brief GPIO::getSN
 * @return
 */
QString GPIO::getSN()
{
    QFile serialNumber("/proc/device-tree/serial-number");

    if (serialNumber.exists() && serialNumber.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&serialNumber);
        QString line;
        line = stream.readLine();

        qDebug().noquote() << "SerialNumber: " << line << endl;
        return(line);
    }
    else
    {
        qDebug().noquote() << "SerialNumber: ERROR BOARD" << endl;
        return("ERROR BOARD");
    }
}

/**
 * @brief GPIO::TimeoutTimer
 */
void GPIO::TimeoutTimer()
{
    qint32 valuePin = value();

    if (direction() == Direction::Output)
    {
        if (valuePin == Level::Low)
        {
            //qDebug() << "GPIO["<< m_gpioNumber <<"] eh 0 mudando para 1" << endl;
            setValue(Level::High);
            valuePin = Level::High;
        }
        else if (valuePin == High)
        {
            //qDebug() << "GPIO["<< m_gpioNumber <<"] eh 1 mudando para 0" << endl;
            setValue(Level::Low);
            valuePin = Level::Low;
        }
        else if (valuePin < 0)
        {
            qDebug() << "Err :(" << endl;
            return;
        }
    }
    else if (direction() == Direction::Input) {
        if (valuePin == Level::Low)
        {
            //qDebug() << "GPIO["<< m_gpioNumber <<"] esta em Low" << endl;
            setInput(Level::Low);
            valuePin = Level::Low;
        }
        else if (valuePin == High)
        {
            //qDebug() << "GPIO["<< m_gpioNumber <<"] esta em High" << endl;
            setInput(Level::High);
            valuePin = Level::High;
        }
        else if (valuePin < 0)
        {
            qDebug() << "Err :(" << endl;
            return;
        }
    }
}
