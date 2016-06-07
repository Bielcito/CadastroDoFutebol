#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Conexao.h"
#include <fstream>
#include <iostream>
#include <string>
#include <QFile>
#include <QTextStream>
#include "cadastroCampeonato.h"
#include <QPushButton>
#include <QWidgetItem>
#include <QSql>
#include <QLineEdit>
#include <QItemEditorFactory>
#include <QProcess>
#include "cadastroTemporada.h"
#include "cadastroEstadio.h"
#include "cadastroArbitro.h"
#include "cadastroEquipe.h"
#include "cadastroJogador.h"
#include "cadastroEstruturaTemporada.h"
#include "cadastroClassificacao.h"
#include "cadastroJogo.h"
#include "equipesParticipantes.h"
#include "telaTemporada.h"
#include "selecionarFase.h"
#include <windows.h>
using std::ofstream;
using std::cout;
using std::endl;
using std::string;

class Senha;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setSenha(QString senha);

private slots:

    void isSelected();

    void showSelectedItemInformations();

    void atualizar();

    void on_actionFazer_Backup_triggered();

    void on_actionCarregar_arquivo_de_Backup_triggered();

    void on_actionSobre_o_Cadastro_do_Futebol_triggered();

    void on_campNovo_clicked();

    void on_campEditar_clicked();

    void on_campExcluir_clicked();

    void on_tempNovo_clicked();

    void on_tempEditar_clicked();

    void on_tempExcluir_clicked();

    void on_estNovo_clicked();

    void on_estEditar_clicked();

    void on_estExcluir_clicked();

    void on_arbNovo_clicked();

    void on_arbEditar_clicked();

    void on_arbExcluir_clicked();

    void on_equNovo_clicked();

    void on_equEditar_clicked();

    void on_equExcluir_clicked();

    void on_jogEditar_clicked();

    void on_jogExcluir_clicked();

    void on_equipesParticipantesAdicionar_clicked();

    void on_tempAbrirTemporada_clicked();

    void on_tempEstruturaTemporada_clicked();

    void on_jogNovo_clicked();

    void on_actionAtualizar_Banco_de_Dados_triggered();

private:
    Ui::MainWindow *ui;
    Senha* w2;
    QString senha;
    Conexao* db;
    void showPasswordWindow();
    void alterPgpassContent();
    void createInitialDatabase();
    void gatheringData();
    cadastroCampeonato* camp;
    cadastroTemporada* temp;
    cadastroEstadio* est;
    cadastroArbitro* arb;
    cadastroEquipe* equ;
    cadastroJogador* jog;
    cadastroEstruturaTemporada* estt;
    cadastroClassificacao* clas;
    equipesParticipantes* equipesparticipantes;
    telaTemporada* telatemporada;
    SelecionarFase* selecionarFase;

    void activateWidgetsUpdates();
    void resizeTableWidgets();
    QString dicioJogPosicao(int num);

    void changeFrameStyle();
    bool doesFileExist(const wchar_t *filename);
    bool create_pgpassconf();
};

#endif // MAINWINDOW_H
