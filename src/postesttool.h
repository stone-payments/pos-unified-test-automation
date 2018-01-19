#ifndef POSTESTTOOL_H
#define POSTESTTOOL_H

#include <QObject>

class PosTestTool : public QObject
{
    Q_OBJECT
public:
    explicit PosTestTool(QObject *parent = nullptr);

signals:

public slots:
};

#endif // POSTESTTOOL_H