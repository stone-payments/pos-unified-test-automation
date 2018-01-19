#ifndef POSTESTTOOL_H
#define POSTESTTOOL_H

#include <QObject>
#include "printercontroller.h"
#include "visionworker.h"


class PosTestTool : public QObject
{
    Q_OBJECT
public:
    explicit PosTestTool(QObject *parent = nullptr);

signals:

public slots:

private:

};

#endif // POSTESTTOOL_H
