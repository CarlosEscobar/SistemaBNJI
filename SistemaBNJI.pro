#-------------------------------------------------
#
# Project created by QtCreator 2014-03-02T22:27:20
#
#-------------------------------------------------

QT       += core gui
QT       += xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SistemaBNJI
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    admin.cpp \
    cliente.cpp \
    mundo_exop_cliente.cpp \
    comprar.cpp \
    mainadmin.cpp \
    addcone.cpp \
    compralibresincone.cpp \
    confirmarvuelo1.cpp \
    boleto.cpp \
    comprabarata.cpp

HEADERS  += mainwindow.h \
    admin.h \
    cliente.h \
    mundo_exop_cliente.h \
    comprar.h \
    mainadmin.h \
    addcone.h \
    compralibresincone.h \
    confirmarvuelo1.h \
    boleto.h \
    comprabarata.h

FORMS    += mainwindow.ui \
    admin.ui \
    cliente.ui \
    mundo_exop_cliente.ui \
    comprar.ui \
    mainadmin.ui \
    addcone.ui \
    compralibresincone.ui \
    confirmarvuelo1.ui \
    boleto.ui \
    comprabarata.ui
