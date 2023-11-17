QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    drawwindow.cpp \
    figura.cpp \
    goniec.cpp \
    gra.cpp \
    hetman.cpp \
    krol.cpp \
    main.cpp \
    mainwindow.cpp \
    mianowanie.cpp \
    pion.cpp \
    plansza.cpp \
    pole.cpp \
    pustepole.cpp \
    skoczek.cpp \
    wieza.cpp

HEADERS += \
    Kolor.h \
    drawwindow.h \
    figura.h \
    goniec.h \
    gra.h \
    hetman.h \
    krol.h \
    mainwindow.h \
    mianowanie.h \
    pion.h \
    plansza.h \
    pole.h \
    pustepole.h \
    skoczek.h \
    wieza.h

FORMS += \
    drawwindow.ui \
    mainwindow.ui \
    mianowanie.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Zasoby.qrc
