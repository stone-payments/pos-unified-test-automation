#ifndef POSTESTTOOL_H
#define POSTESTTOOL_H

#include <QObject>
#include <QImage>

class KeyboardController;
class CardController;
class TouchController;
class PrinterController;
class VisionWorker;
class PosObject;
enum class PosModel;

class PosTestTool: public QObject
{
    Q_OBJECT
public:
    PosTestTool(PosModel device);

    void insertCard();

    void removeCard();

    void keyPress(std::string key);

    void write(std::string text);

    void showScreen();

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
