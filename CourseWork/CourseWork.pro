QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    BoughtCollection.cpp \
    Investment.cpp \
    PaperCollection.cpp \
    SecurityPaper.cpp \
    User.cpp \
    changeinformation.cpp \
    client.cpp \
    graphics.cpp \
    main.cpp \
    mainwindow.cpp \
    myinvestment.cpp \
    qcustomplot.cpp \
    utils.cpp

HEADERS += \
    BoughtCollection.h \
    Investment.h \
    PaperCollection.h \
    SecurityPaper.h \
    User.h \
    changeinformation.h \
    client.h \
    graphics.h \
    mainwindow.h \
    myinvestment.h \
    qcustomplot.h \
    utils.h

FORMS += \
    changeinformation.ui \
    client.ui \
    graphics.ui \
    mainwindow.ui \
    myinvestment.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
