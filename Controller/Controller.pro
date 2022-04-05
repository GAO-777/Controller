QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    USB_Interface.cpp \
    binp_device.cpp \
    controllertab.cpp \
    ethernet_interface.cpp \
    main.cpp \
    mainwindow.cpp \
    tools.cpp

HEADERS += \
    USB_Interface.h \
    binp_device.h \
    controllertab.h \
    ethernet_interface.h \
    mainwindow.h \
    tools.h

FORMS += \
    connectionsetup.ui \
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
