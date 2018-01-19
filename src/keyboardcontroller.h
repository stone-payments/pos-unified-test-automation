#ifndef KEYBOARDCONTROLLER_H
#define KEYBOARDCONTROLLER_H

#include <QObject>

class KeyboardController : public QObject
{
    Q_OBJECT
public:
    explicit KeyboardController(QObject *parent = nullptr);

    void keyPress(int key);
    void keyPressAndHold(int key, int milliseconds);
    void keyDown(int key);
    void keyUp();
signals:

public slots:
};

#endif // KEYBOARDCONTROLLER_H
