#include "equipesParticipantes.h"
#include "ui_equipesParticipantes.h"

equipesParticipantes::equipesParticipantes(QString codtemporada, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::equipesParticipantes)
{
    ui->setupUi(this);
    setWindowModality(Qt::ApplicationModal);

    connect(ui->tableWidgetEquipes, SIGNAL(itemSelectionChanged()), this, SLOT(setaEnable()));
    connect(ui->tableWidgetParticipantes, SIGNAL(itemSelectionChanged()), this, SLOT(removerEnable()));
    this->codtemporada = codtemporada;
    inicializar_num_equipes_restantes();
    atualizarEquipes();
}

equipesParticipantes::~equipesParticipantes()
{
    delete ui;
}

void equipesParticipantes::atualizarEquipes()
{
    //Atualizar Equipes:
    QSqlQuery query;

    if(!query.exec("SELECT codequipe, nomeequipe, tipoequipe FROM equipe"))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
        return;
    }

    while(query.next())
    {
        ui->tableWidgetEquipes->insertRow(0);
        ui->tableWidgetEquipes->setItem(0, 0, new QTableWidgetItem(query.value(0).toString()));
        ui->tableWidgetEquipes->setItem(0, 1, new QTableWidgetItem(query.value(1).toString()));
        ui->tableWidgetEquipes->setItem(0, 2, new QTableWidgetItem(query.value(2).toString()));
    }

    //Atualizar Participantes:
    if(!query.exec("SELECT equipe.codequipe, equipe.nomeequipe, equipe.tipoequipe FROM equipe LEFT JOIN equipecompetetemporada ON (equipecompetetemporada.codequipe = equipe.codequipe) WHERE equipecompetetemporada.codtemporada = " + this->codtemporada))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
        return;
    }
    while(query.next())
    {
        this->equipesRestantes--;
        ui->tableWidgetParticipantes->insertRow(0);
        ui->tableWidgetParticipantes->setItem(0, 0, new QTableWidgetItem(query.value(0).toString()));
        ui->tableWidgetParticipantes->setItem(0, 1, new QTableWidgetItem(query.value(1).toString()));
        ui->tableWidgetParticipantes->setItem(0, 2, new QTableWidgetItem(query.value(2).toString()));
    }

    //Atualizar label dos números restantes:
    ui->equipesRestantes->setText(QString::number(this->equipesRestantes));
}

void equipesParticipantes::inicializar_num_equipes_restantes()
{
    QSqlQuery query;
    if(!query.exec("SELECT numtimecompet1 FROM temporada WHERE codtemporada = " + this->codtemporada))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
        return;
    }
    query.next();
    this->equipesRestantes = query.value(0).toInt();
}

void equipesParticipantes::on_seta_clicked()
{
    QTableWidgetItem* id = new QTableWidgetItem(ui->tableWidgetEquipes->selectedItems().at(0)->text());
    QTableWidgetItem* nome = new QTableWidgetItem(ui->tableWidgetEquipes->selectedItems().at(1)->text());
    QTableWidgetItem* tipo = new QTableWidgetItem(ui->tableWidgetEquipes->selectedItems().at(2)->text());

    //Verifica se ainda é possível adicionar equipes:
    if(this->equipesRestantes == 0)
    {
        QMessageBox::critical(0, "Erro!", "Número máximo de equipes participantes atingido.");
        return;
    }

    //Verifica se a equipe selecionada já existe na temporada:
    for(int i = 0; i < ui->tableWidgetParticipantes->rowCount(); i++)
    {
        if(ui->tableWidgetParticipantes->item(i, 0)->text() == id->text())
        {
            QMessageBox::critical(0, "Erro!", "A equipe selecionada já existe na temporada.");
            return;
        }
    }

    //Verifica se a equipe selecionada já existe nos ids para serem deletados:
    for(int i = 0; i < this->idsToBeDeleted.size(); i++)
    {
        if(id->text() == this->idsToBeDeleted.at(i))
        {
            this->idsToBeDeleted.removeAt(i);
            break;
        }
    }

    ui->tableWidgetParticipantes->insertRow(0);
    ui->tableWidgetParticipantes->setItem(0, 0, id);
    ui->tableWidgetParticipantes->setItem(0, 1, nome);
    ui->tableWidgetParticipantes->setItem(0, 2, tipo);
    this->equipesRestantes--;
    ui->equipesRestantes->setText(QString::number(this->equipesRestantes));
}

void equipesParticipantes::on_remover_clicked()
{
    this->equipesRestantes++;
    ui->equipesRestantes->setText(QString::number(this->equipesRestantes));
    int rowToBeDeleted = ui->tableWidgetParticipantes->selectedRanges().first().topRow();
    QString codequipe = ui->tableWidgetParticipantes->selectedItems().first()->text();
    ui->tableWidgetParticipantes->removeRow(rowToBeDeleted);
    this->idsToBeDeleted.append(codequipe);
}

void equipesParticipantes::on_cancelar_clicked()
{
    this->close();
}

void equipesParticipantes::on_confirmar_clicked()
{
    QSqlQuery query;

    for(int i = 0; i < ui->tableWidgetParticipantes->rowCount(); i++)
    {
        QString id = ui->tableWidgetParticipantes->item(i, 0)->text();
        if(!query.exec("INSERT INTO equipecompetetemporada(codequipe, codtemporada) SELECT " + id + ", " + this->codtemporada + "WHERE NOT EXISTS (SELECT * FROM equipecompetetemporada WHERE codequipe = " + id + "AND codtemporada = " + this->codtemporada + ")"))
        {
            QMessageBox::critical(0, "Erro!", query.lastError().text());
            return;
        }
    }

    for(int i = 0; i < idsToBeDeleted.size(); i++)
    {
        if(!query.exec("DELETE FROM equipecompetetemporada WHERE codequipe = " + idsToBeDeleted.at(i) + "AND codtemporada = " + this->codtemporada))
        {
            QMessageBox::critical(0, "Erro!", query.lastError().text());
            return;
        }
    }


    delete this;
}

void equipesParticipantes::setaEnable()
{
    if(ui->tableWidgetEquipes->selectedItems().size() > 0)
    {
        ui->seta->setEnabled(true);
    }
    else
    {
        ui->seta->setDisabled(true);
    }
}

void equipesParticipantes::removerEnable()
{
    if(ui->tableWidgetParticipantes->selectedItems().size() > 0)
    {
        ui->remover->setEnabled(true);
    }
    else
    {
        ui->remover->setDisabled(true);
    }
}
