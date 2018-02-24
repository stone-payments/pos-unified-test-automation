#ifndef POSTESTTOOL_H
#define POSTESTTOOL_H

#include <QImage>
#include <QObject>

class KeyboardController;
class CardController;
class PrinterController;
class PosObject;
enum class PosModel;

class PosTestTool : public QObject {
    Q_OBJECT
public:
    PosTestTool(PosModel device);
    ~PosTestTool();

    void insertCard();

    void removeCard();

    void keyPress(std::string key);

    void write(std::string text);

    void showScreen();

private:
    KeyboardController* m_keyboardController;
    CardController* m_cardController;
    PrinterController* m_printerController;
    PosObject* m_posObject;
};

#endif // POSTESTTOOL_H
