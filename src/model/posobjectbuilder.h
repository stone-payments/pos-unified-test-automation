#ifndef POSOBJECTBUILDER_H
#define POSOBJECTBUILDER_H

#include "posobject.h"

class PosObjectBuilder
{
public:
    PosObjectBuilder();
    PosObject* getPos(QString model);
};

#endif // POSOBJECTBUILDER_H
