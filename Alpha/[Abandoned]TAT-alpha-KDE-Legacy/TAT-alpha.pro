#-------------------------------------------------
#
# Project created by QtCreator 2018-06-11T12:34:46
#
#-------------------------------------------------

QT       += core gui
QT       += KCoreAddons KXmlGui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TAT-alpha-kde
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
TRANSLATIONS += zh_cn.ts

SOURCES += \
    main.cpp \
    TATCoreInterface.cpp \
    BeaconQtPlatformInfo.cpp \
    TATCoreProcessBackend.cpp \
    BeaconQtFile.cpp \
    BeaconQtString.cpp \
    TATChartFormat.cpp \
    BeaconQtFontLib.cpp \
    TATAboutTextHolder.cpp \
    TATDebugInterface.cpp \
    BeaconQtAboutData.cpp \
    TATAboutInterfaceKDE.cpp \
    TATAboutInterface.cpp \
    DecraptedAboutInterface.cpp

HEADERS += \
    main.h \
    TATCoreInterface.h \
    BeaconQtPlatformInfo.h \
    TATCoreProcessBackend.h \
    BeaconQtFile.h \
    BeaconQtString.h \
    TATStudentLib.h \
    TATChartFormat.h \
    TATCoreProcessBackendDebugSwitcher.h \
    BeaconQtFontLib.h \
    TATAboutTextHolder.h \
    TATAboutInterfaceKDE.h \
    TATDebugInterface.h \
    BeaconQtAboutData.h \
    TATAboutInterface.h \
    DecraptedAboutInterface.h

FORMS += \
    TATCoreInterface.ui \
    TATDebugInterface.ui \
    TATAboutInterface.ui \
    TATAboutInterfaceLegacy.ui \
    DecraptedAboutInterface.ui

RESOURCES += \
    resources.qrc
