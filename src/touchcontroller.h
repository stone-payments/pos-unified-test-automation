#ifndef MOUSECONTROLLER_H
#define MOUSECONTROLLER_H


class TouchController
{
public:
    TouchController();

    void move(int dx, int dy);
    void click(int x, int y);
    void press(int x, int y);
    void release();

};

#endif // MOUSECONTROLLER_H
