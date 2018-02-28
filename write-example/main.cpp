#include "postesttool.h"
#include <QCoreApplication>

int main(int argc, char* argv[])
{
    QCoreApplication a(argc, argv);

    PosTestTool ptt(PosModel::PAX_S920);
    ptt.write("tcc");

    return a.exec();
}
