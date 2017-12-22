#ifndef CARDCONTROLLER_H
#define CARDCONTROLLER_H

#include <QObject>
#include <QSerialPort>

class CardController
{
public:
    CardController();
    ~CardController();
    void insert();
    void remove();
private:
    QSerialPort m_serialPort;
};


#endif // CARDCONTROLLER_H
