#ifndef POSOBJECTBUILDER_H
#define POSOBJECTBUILDER_H

#include "posobject.h"

class PosObjectBuilder
{
public:
    enum PosModel {
        PAX_S920
    };
    PosObjectBuilder();
    PosObject* getPos(PosModel model);

private:
    PosObject *parse(QString jsonPath);
};

#endif // POSOBJECTBUILDER_H
