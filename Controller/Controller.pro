QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../../C_lib/Interfaces/ethernet_interface.cpp \
    ../../C_lib/Interfaces/USB_Interface.cpp \
    ../../C_lib/Qt_lib/binp_device.cpp \
    controllertab.cpp \
    main.cpp \
    mainwindow.cpp \
    ../../C_lib/Qt_lib/tools.cpp

HEADERS += \
    ../../C_lib/Interfaces/ethernet_interface.h \
    ../../C_lib/Interfaces/USB_Interface.h \
    ../../C_lib/Qt_lib/binp_device.h \
    ../../C_lib/Qt_lib/binp_device.h \
    ../../C_lib/Qt_lib/tools.h \
    controllertab.h \
    mainwindow.h \
    ../../C_lib/Qt_lib/tools.h

FORMS += \
    ../../C_lib/Qt_lib/connectionsetup.ui \
    controllertab.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32: LIBS += -L$$PWD/Drv/amd64/ -lftd2xx
win32: LIBS += -lws2_32

INCLUDEPATH += $$PWD/Drv/amd64
DEPENDPATH += $$PWD/Drv/amd64
