#-------------------------------------------------
#
# Project created by QtCreator 2015-06-25T15:59:08
#
#-------------------------------------------------

QT       += core gui
QT += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CadastroDoFutebol
TEMPLATE = app


SOURCES += \
    cadastroCampeonato.cpp \
    Conexao.cpp \
    main.cpp \
    mainwindow.cpp \
    senha.cpp \
    tipocampeonato.cpp \
    tipocampeonatosecondwindow.cpp \
    cadastroTemporada.cpp \
    cadastroEstadio.cpp \
    cadastroArbitro.cpp \
    cadastroEquipe.cpp \
    tipoequipe.cpp \
    tipoequipesecondwindow.cpp \
    cadastroJogador.cpp \
    cadastroEstruturaTemporada.cpp \
    cadastroJogo.cpp \
    equipesParticipantes.cpp \
    informacaoTemporada.cpp \
    telaTemporada.cpp \
    tabelaclassificacao.cpp \
    selecionarFase.cpp \
    telaTorneio.cpp

HEADERS  += \
    cadastroCampeonato.h \
    Conexao.h \
    CreateConnection.h \
    mainwindow.h \
    senha.h \
    tipocampeonato.h \
    tipocampeonatosecondwindow.h \
    cadastroTemporada.h \
    cadastroEstadio.h \
    cadastroArbitro.h \
    cadastroEquipe.h \
    tipoequipe.h \
    tipoequipesecondwindow.h \
    cadastroJogador.h \
    cadastroEstruturaTemporada.h \
    cadastroJogo.h \
    equipesParticipantes.h \
    informacaoTemporada.h \
    telaTemporada.h \
    tabelaclassificacao.h \
    selecionarFase.h \
    telaTorneio.h

FORMS    += mainwindow.ui \
    senha.ui \
    cadastroCampeonato.ui \
    tipocampeonato.ui \
    tipocampeonatosecondwindow.ui \
    cadastroTemporada.ui \
    cadastroEstadio.ui \
    cadastroArbitro.ui \
    cadastroEquipe.ui \
    tipoequipe.ui \
    tipoequipesecondwindow.ui \
    cadastroJogador.ui \
    cadastroEstruturaTemporada.ui \
    cadastroJogo.ui \
    equipesParticipantes.ui \
    informacaoTemporada.ui \
    telaTemporada.ui \
    tabelaclassificacao.ui \
    selecionarFase.ui \
    telaTorneio.ui

DISTFILES +=
