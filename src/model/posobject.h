#ifndef POSOBJECT_H
#define POSOBJECT_H

#include <QtCore>

struct KeyMap {
    QPoint position;
    QStringList keyList;
};

enum PosModel {
    PAX_S920
};

class PosObject
{
public:
    QPair<QPointF, int> getKeyPosition(QString desiredKey);
private:
    PosObject() { }

    QString m_model;
    QString m_vendor;
    int m_width;
    int m_height;
    QRect m_keyboardROI;
    QRect m_screenROI;
    QList<KeyMap> m_keyboardMap;

    friend class PosObjectBuilder;
};

#endif // POSOBJECT_H
