#include <QApplication>
#include "model/posobjectbuilder.h"
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    PosObjectBuilder posBuilder;
    PosObject *pos = posBuilder.getPos(PosObjectBuilder::PAX_S920);

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
