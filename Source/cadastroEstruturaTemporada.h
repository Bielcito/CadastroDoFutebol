#ifndef CADASTROESTRUTURATEMPORADA_H
#define CADASTROESTRUTURATEMPORADA_H

#include <QWidget>
#include <QFileDialog>
#include <QPixmap>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <iostream>

namespace Ui {
class cadastroEstruturaTemporada;
}

class cadastroEstruturaTemporada : public QWidget
{
    Q_OBJECT

public:
    explicit cadastroEstruturaTemporada(QString codtemporada, QWidget *parent = 0);
    ~cadastroEstruturaTemporada();

private slots:

    void on_cancelar_clicked();

    void mostrarGrupos();

    void on_incluirFase_clicked();

    void on_excluirFase_clicked();

    void on_alterarFase_clicked();

    void faseButtons();

    void faseWrite();

    void grupoButtons();

    void grupoWrite();

    void on_incluirGrupo_clicked();

    void on_excluirGrupo_clicked();

    void on_alterarGrupo_clicked();

    void on_adicionarRodada_clicked();

    void mostrarRodadas();

    void on_diminuirRodada_clicked();

    void on_checkBox_clicked(bool checked);

    void updateTorneio();

private:
    void initiateLists();
    void inicializarDisputas();
    QString converterParaDisputa(QString num);
    QStringList nomesTorneio;
    Ui::cadastroEstruturaTemporada *ui;
    QString codtemporada;
    const int maxNumberRodadasDisputa = 7;
};

#endif // CADASTROESTRUTURATEMPORADA_H
