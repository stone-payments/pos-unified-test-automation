#ifndef POSTESTTOOL_H
#define POSTESTTOOL_H

#include "pos-test-tool_global.h"
#include <QImage>

class KeyboardController;
class CardController;
class TouchController;
class PrinterController;
class VisionWorker;
class PosObject;
enum class PosModel;

class POSTESTTOOLSHARED_EXPORT PosTestTool: public QObject
{
    Q_OBJECT
public:
    PosTestTool(PosModel device);

    void insertCard();

    void removeCard();

    void keyPress(QString key);

    void write(QString text);

signals:
    void cameraImageChanged(QImage newImage);

private:
    KeyboardController *m_keyboardController;
    CardController *m_cardController;
    TouchController *m_touchController;
    PrinterController *m_printerControllerInstance;
    VisionWorker *m_visionWorkerInstance;
    PosObject *m_posObject;
};

#endif // POSTESTTOOL_H
