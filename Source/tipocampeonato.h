#ifndef TIPOCAMPEONATO_H
#define TIPOCAMPEONATO_H

#include <QWidget>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlError>
#include <tipocampeonatosecondwindow.h>
#include <QCloseEvent>

namespace Ui {
class tipoCampeonato;
}

class tipoCampeonato : public QWidget
{
    Q_OBJECT

public:
    explicit tipoCampeonato(QWidget *parent = 0);
    ~tipoCampeonato();

private slots:

    void on_tabela_itemSelectionChanged();

    void on_editar_clicked();

    void on_novo_clicked();

    void atualizarTabela();

    void on_excluir_clicked();

    void keyPressEvent(QKeyEvent *e);

    void on_novo_2_clicked();

private:
    Ui::tipoCampeonato *ui;

    void closeEvent(QCloseEvent* event);

    void zerarTabela();
};

#endif // TIPOCAMPEONATO_H
