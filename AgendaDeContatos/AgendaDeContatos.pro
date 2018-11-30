#-------------------------------------------------
#
# Project created by QtCreator 2016-04-21T10:28:11
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AgendaDeContatos
TEMPLATE = app


SOURCES += main.cpp\
        TelaPrincipal.cpp \
    Contato.cpp \
    TelaIncluir.cpp \
    Agenda.cpp \
    Telefone.cpp \
    Endereco.cpp \
    TelaAlterar.cpp \
    TelaExcluir.cpp \
    TelaListar.cpp \
    TelaBusca.cpp \
    OrdenadorTemplateMethod.cpp \
    OrdenarPorNome.cpp \
    OrdenarPorCPF.cpp \
    OrdenarPorEmail.cpp

HEADERS  += TelaPrincipal.h \
    Contato.h \
    TelaIncluir.h \
    CRUD.h \
    Agenda.h \
    Telefone.h \
    Endereco.h \
    TelaAlterar.h \
    TelaExcluir.h \
    TelaListar.h \
    TelaBusca.h \
    OrdenadorTemplateMethod.h \
    OrdenarPorNome.h \
    OrdenarPorCPF.h \
    OrdenarPorEmail.h

FORMS    += \
    TelaIncluir.ui \
    TelaAlterar.ui \
    TelaExcluir.ui \
    TelaListar.ui \
    TelaPrincipal.ui \
    TelaBusca.ui

RESOURCES +=
