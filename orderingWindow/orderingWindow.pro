QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Table.cpp \
    checkoutwindow.cpp \
    dialog.cpp \
    dish.cpp \
    main.cpp \
    mainwindow.cpp \
    order.cpp \
    orderqueue.cpp \
    restaurant.cpp

HEADERS += \
    Table.h \
    checkoutwindow.h \
    dialog.h \
    dish.h \
    mainwindow.h \
    order.h \
    orderqueue.h \
    restaurant.h

FORMS += \
    checkoutwindow.ui \
    dialog.ui \
    mainwindow.ui \
    restaurant.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    image.qrc

DISTFILES +=
