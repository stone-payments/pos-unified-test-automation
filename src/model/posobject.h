#ifndef POSOBJECT_H
#define POSOBJECT_H

#include <QtCore>

struct KeyMap {
    QPoint position;
    QList<Qt::Key> key;
};

class PosObject
{
private:
    PosObject() { }

    QString m_model;
    QString m_vendor;
    float m_width;
    float m_height;
    QRect m_keypadROI;
    QRect m_screenROI;
    QList<KeyMap> m_keyboardMap;

    friend class PosObjectBuilder;
};

#endif // POSOBJECT_H
