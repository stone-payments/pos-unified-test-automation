#ifndef GPIO_H
#define GPIO_H

#include <QObject>
#include <QTimer>


class GPIO : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int output READ getOutput WRITE setOutput NOTIFY outputChanged)
    Q_PROPERTY(int input READ getInput WRITE setInput NOTIFY inputChanged)


public:
    Q_ENUMS(Direction)
    Q_ENUMS(Edge)
    Q_ENUMS(Level)

    // Direcao do GPIO ENTRADA ou SAIDA
    enum Direction { Undef=-1, Input=0, Output };

    // Detecção de borda
    enum Edge { None=0, Rising /* HIGH -> LOW */, Falling /* LOW  -> HIGH */, Both };

    // Valor do Pino 0(Desligado) ou 1(Ligado)
    enum Level { Low=0, High };


    explicit GPIO(QObject *parent = nullptr);
    GPIO(quint32 gpioNumber);
    ~GPIO();

    int gpioExport();
    int gpioUnexport();
    bool gpioExported();

    quint32 gpioNumber() const { return m_gpioNumber; }
    void setGpioNumber(quint32 gpioNumber) { m_gpioNumber = gpioNumber; }

    Direction direction() const;
    int setDirection(Direction direction);

    Edge edge() const;
    int setEdge(Edge edge);

    qint32 value() const;
    int setValue(Level value);

    // Funcoes do Q_PROPERTY
    int getOutput() const;
    void setOutput(int value);
    int getInput() const;
    void setInput(int value);

    // Q_INVOKABLE para chamar de QML -> C++
    Q_INVOKABLE void setGPIOInput(int gpio);
    Q_INVOKABLE void setGPIOOutput(int gpio);
    Q_INVOKABLE void cleanGPIO();
    Q_INVOKABLE void StartMonitor();
    Q_INVOKABLE void StartMonitor(const quint32 msecs);
    Q_INVOKABLE void StopMonitor();
    Q_INVOKABLE QString getCPU(void);
    Q_INVOKABLE QString getSN(void);


    static const QString gpioExportFilePath;
    static const QString gpioUnexportFilePath;
    static const QString gpioDirectionFilePath;
    static const QString gpioEdgeFilePath;
    static const QString gpioValueFilePath;
    static const QString gpioFilePath;

private:
    int m_valueOutput = -1;
    int m_valueInput = -1;

    QTimer *m_timerGPIO = new QTimer;
    quint32 m_gpioNumber;

public slots:
    void TimeoutTimer();

signals:
    void outputChanged();
    void inputChanged();

};

#endif // GPIO_H
