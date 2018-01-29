#include "posobject.h"

QPoint PosObject::getKeyPosition(QString desiredKey)
{
    foreach (KeyMap key, m_keyboardMap)
    {
        if(key.keyList.contains(desiredKey))
        {
            return key.position;
        }
    }
    return QPoint(0,0);
}
