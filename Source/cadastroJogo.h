#ifndef CADASTROJOGO_H
#define CADASTROJOGO_H

#include <QWidget>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QDate>
#include "tipoequipe.h"
#include <iostream>
using namespace std;

namespace Ui {
class cadastroJogo;
}

class cadastroJogo : public QWidget
{
    Q_OBJECT

public:
    explicit cadastroJogo(QString codtemporada, QString codfase, QString codgrupo, QString codrodada, QWidget *parent = 0);
    explicit cadastroJogo(QString codtemporada, QString codfase, QString codgrupo, QString codrodada, QStringList equipes, QWidget *parent = 0);
    explicit cadastroJogo(
            QString codjogo,
            QString codestruturatemporada,
            QString codequipecasa,
            QString codequipefora,
            QString tv,
            QString nomeestadio,
            QString golstimecasa,
            QString golstimefora,
            QString golstimecasapritem,
            QString golstimeforapritem,
            QString prorrogacao,
            QString penaltis,
            QString golstimecasaprorrogacao,
            QString golstimeforaprorrogacao,
            QString golstimecasapenaltis,
            QString golstimeforapenaltis,
            QString publico,
            QString noticia,
            QString realizado,
            QString estatchutecasa,
            QString estatchutefora,
            QString estatfaltacasa,
            QString estatfaltafora,
            QString estatescanteiocasa,
            QString estatescanteiofora,
            QString estatimpedimentocasa,
            QString estatimpedimentofora,
            QString datahorajogo,
            QString codarbitro,
            QString codestadio,
            QString codclassificacaotimecasa,
            QString codclassificacaotimefora,
            QString codequipevencedora,
            QWidget *parent = 0);
    ~cadastroJogo();

private:
    Ui::cadastroJogo *ui;
    QString editCode;
    bool editMode;
    void keyPressEvent(QKeyEvent *e);
    void inicializarListas();
    void inicializarListas(QStringList equipes);
    void inicializarComboBox();
    QString codfase;
    QString codgrupo;
    QString codrodada;
    QString codtemporada;
    QStringList equipes;
    QStringList arbitros;
    QStringList estadios;
    bool editandoEquipeCasa;
    bool editandoEquipeFora;

private slots:
    void atualizarComboBoxEquipeCasa();
    void atualizarComboBoxEquipeFora();
    void on_isTempoNormal_clicked(bool x);
    void on_isProrrogacao_clicked(bool x);
    void on_isPenaltis_clicked(bool checked);
    void somarPontosCasa();
    void somarPontosFora();
    void on_Confirmar_clicked();
};

#endif // CADASTROJOGO_H
