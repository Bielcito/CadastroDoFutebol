#ifndef TELATORNEIO_H
#define TELATORNEIO_H

#include <QWidget>
#include <QTableWidget>
#include <QMessageBox>
#include <cmath>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QSignalMapper>
#include "cadastroJogo.h"

namespace Ui {
class telaTorneio;
}

class telaTorneio : public QWidget
{
    Q_OBJECT

public:
    explicit telaTorneio(QString codtemporada, QString codfase, QWidget *parent = 0);
    ~telaTorneio();

private slots:

    void on_InserirJogo_clicked();

    void callMostrarJogos();

    void on_Excluir_clicked();

    void on_pushButton_clicked();

private:
    Ui::telaTorneio *ui;
    QString codtemporada;
    QString codfase;
    QString codgrupo;
    QString codrodada;
    QStringList nomesTorneio;
    void atualizar_abas();
    void inicializar_tabela(QTableWidget* table);
    void mostrarJogos(QTableWidget* table, int num);
    cadastroJogo* jog;
};

#endif // TELATORNEIO_H
