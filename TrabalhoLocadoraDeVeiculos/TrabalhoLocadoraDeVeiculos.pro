#-------------------------------------------------
#
# Project created by QtCreator 2016-06-06T15:45:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TrabalhoLocadoraDeVeiculos
TEMPLATE = app


SOURCES += main.cpp\
        TelaPrincipal.cpp \
    Cliente.cpp \
    CNH.cpp \
    Data.cpp \
    Telefone.cpp \
    Endereco.cpp \
    PersistenciaCliente.cpp \
    MenuCliente.cpp \
    TelaIncluirCliente.cpp \
    ValidadeDeDados.cpp

HEADERS  += TelaPrincipal.h \
    Cliente.h \
    CNH.h \
    Data.h \
    Telefone.h \
    Endereco.h \
    CrudDoCliente.h \
    PersistenciaCliente.h \
    MenuCliente.h \
    TelaIncluirCliente.h \
    ValidadeDeDados.h

FORMS    += TelaPrincipal.ui \
    MenuCliente.ui \
    TelaIncluirCliente.ui

RESOURCES += \
    fundos.qrc
