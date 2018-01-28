#ifndef POSOBJECT_H
#define POSOBJECT_H

#include <QObject>
#include <QtCore>

struct KeyMap {
    QPoint position;
    QList<Qt::Key> key;
};

class PosObject : public QObject
{
    Q_OBJECT
private:
    explicit PosObject(QObject *parent = nullptr);

    QString m_model;
    QString m_vendor;
    float m_width;
    float m_height;
    QRect m_keypadROI;
    QRect m_screenROI;
    QList<KeyMap> m_keyboardMap;
};

#endif // POSOBJECT_H
