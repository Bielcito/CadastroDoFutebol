#ifndef CADASTROCLASSIFICACAO_H
#define CADASTROCLASSIFICACAO_H

#include <QWidget>
#include <QTextCursor>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <iostream>
using std::cout;
using std::endl;

namespace Ui {
class cadastroClassificacao;
}

class cadastroClassificacao : public QWidget
{
    Q_OBJECT

public:
    explicit cadastroClassificacao(QWidget *parent = 0);
    explicit cadastroClassificacao(QString codclassificacao, QString codestruturatemporada, QString datajogo, QString codequipe, QString pontos, QString vitoria, QString empate, QString derrota, QString vitoriaprorrogacao, QString vitoriapenaltis, QString derrotaprorrogacao, QString derrotapenaltis, QString golspro, QString golscontra, QString saldogols, QString publico, QString local, QString realizado, QString jogos, QString empateprorrogacao, QWidget *parent = 0);
    ~cadastroClassificacao();

private slots:
    void on_confirmar_clicked();

private:
    Ui::cadastroClassificacao *ui;
    void initiateComboBox();
    bool editMode;
    QString editCode;
};

#endif // CADASTROCLASSIFICACAO_H
