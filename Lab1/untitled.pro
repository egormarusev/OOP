QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    collection.cpp \
    element.cpp \
    enterconnection.cpp \
    enterelements.cpp \
    enterfrequency.cpp \
    entersourses.cpp \
    fullresistance.cpp \
    inductancecapacitance.cpp \
    main.cpp \
    mainwindow.cpp \
    potentials.cpp \
    pq.cpp \
    resistor.cpp \
    utils.cpp \
    workwindow.cpp

HEADERS += \
    collection.h \
    element.h \
    enterconnection.h \
    enterelements.h \
    enterfrequency.h \
    entersourses.h \
    fullresistance.h \
    inductancecapacitance.h \
    mainwindow.h \
    potentials.h \
    pq.h \
    resistor.h \
    utils.h \
    workwindow.h

FORMS += \
    enterconnection.ui \
    enterelements.ui \
    enterfrequency.ui \
    entersourses.ui \
    fullresistance.ui \
    mainwindow.ui \
    potentials.ui \
    pq.ui \
    workwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
