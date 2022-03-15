QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addeditdialog.cpp \
    addownerdialog.cpp \
    addpaymentdialog.cpp \
    addtariffdialog.cpp \
    housemanagementsystem.cpp \
    main.cpp \
    mainwindow.cpp \
    objectinfoform.cpp \
    ownerinfoform.cpp \
    paymentinfoform.cpp \
    tariffinfoform.cpp

HEADERS += \
    addeditdialog.h \
    addownerdialog.h \
    addpaymentdialog.h \
    addtariffdialog.h \
    housemanagementsystem.h \
    mainwindow.h \
    objectinfoform.h \
    ownerinfoform.h \
    paymentinfoform.h \
    tariffinfoform.h

FORMS += \
    addeditdialog.ui \
    addownerdialog.ui \
    addpaymentdialog.ui \
    addtariffdialog.ui \
    mainwindow.ui \
    objectinfoform.ui \
    ownerinfoform.ui \
    paymentinfoform.ui \
    tariffinfoform.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
