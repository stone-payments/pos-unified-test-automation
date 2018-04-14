#ifndef POSOBJECTFACTORY_H
#define POSOBJECTFACTORY_H

#include "pos_types.h"
#include "posobject.h"

class PosObjectFactory {
public:
    static PosObject* getPosObject(PosModel model);

private:
    PosObjectFactory();
    static PosObject* parse(QString jsonPath);
};

#endif // POSOBJECTFACTORY_H
