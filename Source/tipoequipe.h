#ifndef TIPOEQUIPE_H
#define TIPOEQUIPE_H

#include <QWidget>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlError>
#include <QCloseEvent>
#include "tipoequipesecondwindow.h"

namespace Ui {
class tipoequipe;
}

class tipoequipe : public QWidget
{
    Q_OBJECT

public:
    explicit tipoequipe(QWidget *parent = 0);
    ~tipoequipe();

private slots:
    void atualizarTabela();

    void on_excluir_clicked();

    void keyPressEvent(QKeyEvent *e);

    void on_concluido_clicked();

    void on_tabela_itemSelectionChanged();

    void on_novo_clicked();

    void on_editar_clicked();

private:
    void closeEvent(QCloseEvent* event);
    Ui::tipoequipe *ui;
    void zerarTabela();
};

#endif // TIPOEQUIPE_H
