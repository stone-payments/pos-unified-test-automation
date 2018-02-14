#include "posobjectbuilder.h"
#include <QDebug>

PosObjectBuilder::PosObjectBuilder()
{

}

PosObject* PosObjectBuilder::getPos(PosModel model)
{
    PosObject *newObject = nullptr;
    switch (model) {
    case PosModel::PAX_S920:
        newObject = parse(":/model/PAX_S920.json");
        break;
    default:
        break;
    }

    return newObject;
}

PosObject *PosObjectBuilder::parse(QString jsonPath)
{
    QFile file(jsonPath);
    file.open(QIODevice::ReadOnly);
    QByteArray rawData = file.readAll();

    // Parse document
    QJsonDocument doc(QJsonDocument::fromJson(rawData));

    // Get JSON object
    QJsonObject json = doc.object();
    PosObject *object = new PosObject();

    object->m_vendor = json["vendor"].toString();
    object->m_model = json["model"].toString();
    object->m_width = json["width"].toInt();
    object->m_height = json["height"].toInt();

    QJsonObject keyboardObject = json["keyboardROI"].toObject();
    object->m_keyboardROI.setX(keyboardObject["x"].toInt());
    object->m_keyboardROI.setY(keyboardObject["y"].toInt());
    object->m_keyboardROI.setWidth(keyboardObject["w"].toInt());
    object->m_keyboardROI.setHeight(keyboardObject["h"].toInt());

    QJsonObject screenObject = json["screenROI"].toObject();
    object->m_screenROI.setX(screenObject["x"].toInt());
    object->m_screenROI.setY(screenObject["y"].toInt());
    object->m_screenROI.setWidth(screenObject["w"].toInt());
    object->m_screenROI.setHeight(screenObject["h"].toInt());

    QJsonArray keyMapArray = json["keyboardMap"].toArray();
    foreach (QJsonValue keyObject, keyMapArray) {
        KeyMap newKeyMap;
        qDebug() << "X: " << keyObject["x"].toInt();
        qDebug() << "Y: " << keyObject["y"].toInt();
        newKeyMap.position.setX(keyObject["x"].toInt());
        newKeyMap.position.setY(keyObject["y"].toInt());

        QVariantList keyVariantList = keyObject["keyList"].toArray().toVariantList();
        foreach (QVariant keyVariant, keyVariantList) {
            newKeyMap.keyList << keyVariant.toString();
        }
        object->m_keyboardMap.append(newKeyMap);
    }

    return object;
}
