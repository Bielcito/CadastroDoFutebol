#ifndef EQUIPESPARTICIPANTES_H
#define EQUIPESPARTICIPANTES_H

#include <QWidget>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <iostream>
#include <QStringList>
using namespace std;

namespace Ui {
class equipesParticipantes;
}

class equipesParticipantes : public QWidget
{
    Q_OBJECT

public:
    explicit equipesParticipantes(QString codtemporada, QWidget *parent = 0);
    ~equipesParticipantes();

private slots:
    void on_seta_clicked();

    void on_remover_clicked();

    void on_cancelar_clicked();

    void on_confirmar_clicked();

    void setaEnable();
    void removerEnable();

private:
    void atualizarEquipes();
    void inicializar_num_equipes_restantes();
    Ui::equipesParticipantes *ui;
    QString codtemporada;
    QStringList idsToBeDeleted;
    int equipesRestantes;
};

#endif // EQUIPESPARTICIPANTES_H
