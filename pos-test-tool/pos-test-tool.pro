#-------------------------------------------------
#
# Project created by QtCreator 2018-02-14T18:15:58
#
#-------------------------------------------------

QT       += core serialport

QMAKE_LFLAGS += -fPIC

TEMPLATE = lib
TARGET = PosTestTool

DEFINES += POSTESTTOOL_LIBRARY

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/actuators/cardcontroller.cpp \
    src/actuators/keyboardcontroller.cpp \
    src/actuators/printercontroller.cpp \
    src/model/posobject.cpp \
    src/postesttool.cpp \
    src/model/posobjectfactory.cpp

HEADERS += \
    src/actuators/cardcontroller.h \
    src/actuators/keyboardcontroller.h \
    src/actuators/printercontroller.h \
    src/model/posobject.h \
    src/model/pos_types.h \
    src/pos-test-tool_global.h \
    src/postesttool.h \
    src/model/posobjectfactory.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

DISTFILES += \
    res/model/PAX_S920.json \
    classdiagram.qmodel \
    src/paymentTest.py

RESOURCES += \
    res/resource.qrc

INCLUDEPATH += \
    src/actuators \
    src/model

# add AtCore
INCLUDEPATH += /usr/include/AtCore
LIBS += -L/usr/lib -lAtCore

python_wrapper {
    TARGET = _postesttool
    CONFIG += plugin no_plugin_name_prefix

    QMAKE_EXTENSION_SHLIB = so

    # add python to generate Wrapper
    INCLUDEPATH += /usr/include/python3.6

    SOURCES += \
        src/postesttool_wrap.cxx
}

