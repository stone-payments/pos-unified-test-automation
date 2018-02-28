#include "posobject.h"

QPair<QPointF, int> PosObject::getKeyPosition(QString desiredKey)
{
    foreach (KeyMap key, m_keyboardMapList) {
        if (key.keyList.contains(desiredKey)) {
            QPair<QPointF, int> keyPosition(key.position + m_originPosition, key.keyList.indexOf(desiredKey));
            return keyPosition;
        }
    }
    return QPair<QPointF, int>(QPointF(0, 0), 0);
}

PosObject::PosObject()
    : m_originPosition(QPointF(68, 48.5))
{
}
