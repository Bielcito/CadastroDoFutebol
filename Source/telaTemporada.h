#ifndef TELATEMPORADA_H
#define TELATEMPORADA_H

#include <QWidget>
#include <QSqlQuery>
#include <QSqlError>
#include <QTableView>
#include <iostream>
#include <QMessageBox>
#include <cadastroJogo.h>
#include <tabelaclassificacao.h>
using std::cout;
using std::endl;

namespace Ui {
class telaTemporada;
}

class telaTemporada : public QWidget
{
    Q_OBJECT

public:
    explicit telaTemporada(QString codtemporada, QString codfase, QWidget *parent = 0);
    ~telaTemporada();

private slots:
    void mostrar_grupos();
    void mostrar_rodadas();
    void mostrar_jogos();

    void on_Incluir_clicked();

    void alterar_excluir_buttons();

    void on_MostrarTabela_clicked();

    void on_Excluir_clicked();

    void on_Fechar_clicked();

private:
    Ui::telaTemporada *ui;
    QString codtemporada;
    QString faseSelecionada;
    QString grupoSelecionado;
    QString rodadaSelecionada;
    cadastroJogo* jogo;
    TabelaClassificacao* tabela;
};

#endif // TELATEMPORADA_H
