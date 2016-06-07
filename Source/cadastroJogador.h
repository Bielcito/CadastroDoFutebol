#ifndef CADASTROJOGADOR_H
#define CADASTROJOGADOR_H

#include <QWidget>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QFileDialog>
#include <QDate>
#include "tipoequipe.h"
#include <iostream>
using namespace std;

namespace Ui {
class cadastroJogador;
}

class cadastroJogador : public QWidget
{
    Q_OBJECT

public:
    explicit cadastroJogador(QWidget *parent = 0);
    explicit cadastroJogador(QString codjogador, QString codequipe, QString codtemporada, QString apelidojogador, QString nomejogador, QString numerocamisa, QString datanascimento, QString nacionalidade, QString posicao, QString status, QString email, QString foto, QWidget *parent = 0);
    ~cadastroJogador();

private slots:
    void on_Confirmar_clicked();

    void on_SelecionarImagem_clicked();

    void on_RemoverImagem_clicked();

    void on_Cancelar_clicked();

private:
    Ui::cadastroJogador *ui;
    QString editCode;
    bool editMode;
    bool imageIsChanged;
    QString file;
    void keyPressEvent(QKeyEvent *e);
    void atualizarComboBox();
    void inicializar_sem_jogador();
};

#endif // CADASTROJOGADOR_H
