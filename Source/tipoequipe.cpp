#include "tipoequipe.h"
#include "ui_tipoequipe.h"

tipoequipe::tipoequipe(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tipoequipe)
{
    ui->setupUi(this);

    setWindowModality(Qt::ApplicationModal);

    atualizarTabela();
}

tipoequipe::~tipoequipe()
{
    delete ui;
}

void tipoequipe::atualizarTabela()
{
    zerarTabela();

    QSqlQuery query;
    if(!query.exec("SELECT * FROM tipoequipe ORDER BY nometipoequipe DESC"))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
    }

    while(query.next())
    {
        ui->tabela->insertRow(0);
        ui->tabela->setItem(0,0, new QTableWidgetItem(query.value(1).toString()));
    }
}

void tipoequipe::zerarTabela()
{
    ui->tabela->clearContents();
    ui->tabela->setRowCount(0);
}

void tipoequipe::on_excluir_clicked()
{
    QSqlQuery query;

    if(QMessageBox::No == QMessageBox(QMessageBox::Information, "Atenção!", "Deseja realmente apagar este tipo de equipe? Esta operação não pode ser desfeita.", QMessageBox::Yes | QMessageBox::No).exec())
    {
        return;
    }

    QString itemselecionado = ui->tabela->selectedItems().first()->text();

    if(!query.exec("DELETE FROM ONLY tipoequipe WHERE nometipoequipe = '" + itemselecionado + "'"))
    {
        if(query.lastError().number() == 23503)
        {
            QMessageBox::critical(0, "Erro!", "Não é possível apagar pois já existem equipes cadastradas com este tipo!");
        }
        return;
    }

    ui->tabela->removeRow(ui->tabela->selectedRanges().first().topRow());
}

void tipoequipe::closeEvent(QCloseEvent* event)
{
    delete this;
    event->ignore();
}

void tipoequipe::keyPressEvent(QKeyEvent *e)
{
    if(e->key() == Qt::Key_Delete)
    {
        if(ui->excluir->isEnabled())
        {
            ui->excluir->click();
        }
    }
}

void tipoequipe::on_concluido_clicked()
{
    delete this;
}

void tipoequipe::on_tabela_itemSelectionChanged()
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

void tipoequipe::on_novo_clicked()
{
    tipoequipesecondwindow* tipoSecondWindow = new tipoequipesecondwindow();
    connect(tipoSecondWindow, SIGNAL(destroyed()),this,SLOT(atualizarTabela()));
    tipoSecondWindow->show();
}

void tipoequipe::on_editar_clicked()
{
    QString itemselecionado = ui->tabela->selectedItems().first()->text();

    tipoequipesecondwindow* tipoSecondWindow = new tipoequipesecondwindow(itemselecionado);
    connect(tipoSecondWindow, SIGNAL(destroyed()), this, SLOT(atualizarTabela()));
    tipoSecondWindow->show();
}
