#include "posobjectbuilder.h"

PosObjectBuilder::PosObjectBuilder()
{

}

PosObject *PosObjectBuilder::getPos(QString model)
{
    return new PosObject();
}
