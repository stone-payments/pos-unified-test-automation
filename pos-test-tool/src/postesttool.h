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

    bool isIdle();

signals:
    void cameraImageChanged(QImage newImage);

    void idle();

    void busy();

private:
    KeyboardController *m_keyboardController;
    CardController *m_cardController;
    TouchController *m_touchController;
    PrinterController *m_printerControllerInstance;
    VisionWorker *m_visionWorkerInstance;
    PosObject *m_posObject;

    bool m_isIdle;
};

#endif // POSTESTTOOL_H
