#include "tipocampeonato.h"
#include "ui_tipocampeonato.h"

tipoCampeonato::tipoCampeonato(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tipoCampeonato)
{
    ui->setupUi(this);

    setWindowModality(Qt::ApplicationModal);

    atualizarTabela();
}

tipoCampeonato::~tipoCampeonato()
{
    delete ui;
}

void tipoCampeonato::on_tabela_itemSelectionChanged()
{
    if(ui->tabela->selectedItems().size() > 0)
    {
        ui->editar->setEnabled(true);
        ui->excluir->setEnabled(true);
    }
    else
    {
        ui->editar->setEnabled(false);
        ui->excluir->setEnabled(false);
    }
}

void tipoCampeonato::on_editar_clicked()
{
    QString itemselecionado = ui->tabela->selectedItems().first()->text();

    tipoCampeonatoSecondWindow* tipoSecondWindow = new tipoCampeonatoSecondWindow(itemselecionado);
    connect(tipoSecondWindow, SIGNAL(destroyed()), this, SLOT(atualizarTabela()));
    tipoSecondWindow->show();
}

void tipoCampeonato::atualizarTabela()
{
    zerarTabela();

    QSqlQuery query;
    if(!query.exec("SELECT * FROM tipocampeonato ORDER BY nometipocampeonato DESC"))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
    }

    while(query.next())
    {
        ui->tabela->insertRow(0);
        ui->tabela->setItem(0,0, new QTableWidgetItem(query.value(1).toString()));
    }

    ui->tabela->resizeColumnsToContents();
}

void tipoCampeonato::on_novo_clicked()
{
    tipoCampeonatoSecondWindow* tipoSecondWindow = new tipoCampeonatoSecondWindow();
    connect(tipoSecondWindow, SIGNAL(destroyed()),this,SLOT(atualizarTabela()));
    tipoSecondWindow->show();
}

void tipoCampeonato::zerarTabela()
{
    ui->tabela->clearContents();
    ui->tabela->setRowCount(0);
}

/**
 * @brief tipoCampeonato::on_excluir_clicked
 * Esta função é executada quando o botão "Excluir..." é apertado.
 */
void tipoCampeonato::on_excluir_clicked()
{
    QSqlQuery query;

    if(QMessageBox::No == QMessageBox(QMessageBox::Information, "Atenção!", "Deseja realmente apagar este tipo de campeonato? Esta operação não pode ser desfeita.", QMessageBox::Yes | QMessageBox::No).exec())
    {
        return;
    }

    QString itemselecionado = ui->tabela->selectedItems().first()->text();

    if(!query.exec("DELETE FROM ONLY tipocampeonato WHERE nometipocampeonato = '" + itemselecionado + "'"))
    {
        if(query.lastError().number() == 23503)
        {
            QMessageBox::critical(0, "Erro!", "Não é possível apagar pois já existem campeonatos que são deste tipo!");
        }
        return;
    }

    ui->tabela->removeRow(ui->tabela->selectedRanges().first().topRow());
}

void tipoCampeonato::closeEvent(QCloseEvent* event)
{
    delete this;
    event->ignore();
}

void tipoCampeonato::keyPressEvent(QKeyEvent *e)
{
    if(e->key() == Qt::Key_Delete)
    {
        if(ui->excluir->isEnabled())
        {
            ui->excluir->click();
        }
    }
}

void tipoCampeonato::on_novo_2_clicked()
{
    delete this;
}
