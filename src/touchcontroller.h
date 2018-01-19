#ifndef MOUSECONTROLLER_H
#define MOUSECONTROLLER_H

#include <QObject>

class TouchController: public QObject
{
    Q_OBJECT
public:
    explicit TouchController(QObject *parent = nullptr);

    void move(int dx, int dy);
    void click(int x, int y);
    void press(int x, int y);
    void release();

};

#endif // MOUSECONTROLLER_H
