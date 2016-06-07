#ifndef TABELACLASSIFICACAO_H
#define TABELACLASSIFICACAO_H

#include <QWidget>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>

namespace Ui {
class TabelaClassificacao;
}

class TabelaClassificacao : public QWidget
{
    Q_OBJECT

public:
    explicit TabelaClassificacao(QString codtemporada, QWidget *parent = 0);
    ~TabelaClassificacao();

private:
    Ui::TabelaClassificacao *ui;
    void inicializar_tabela();
    void inicializar_combobox();
    void calcular_jogo(QString codjogo);
    QString faseSelecionada;
    QString codtemporada;

private slots:
    void atualizar_classificacao();
};

#endif // TABELACLASSIFICACAO_H
