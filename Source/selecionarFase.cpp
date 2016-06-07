#include "selecionarFase.h"
#include "ui_selecionarFase.h"

SelecionarFase::SelecionarFase(QString codtemporada, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SelecionarFase)
{
    ui->setupUi(this);

    setWindowModality(Qt::ApplicationModal);

    this->codtemporada = codtemporada;

    atualizarComboBox();

    connect(ui->comboBox, SIGNAL(currentIndexChanged(QString)), this, SLOT(abrirCorrespondente()));
}

SelecionarFase::~SelecionarFase()
{
    delete ui;
}

void SelecionarFase::abrirCorrespondente()
{
    QSqlQuery query;

    if(!ui->comboBox->currentText().isEmpty())
    {
        ui->confirmar->setEnabled(true);
    }
    else
    {
        ui->confirmar->setEnabled(false);
    }

    if(ui->comboBox->currentText().isEmpty())
    {
        return;
    }

    if(!query.exec("SELECT fase.codfase FROM fase WHERE fase.codtemporada = " + this->codtemporada + " AND fase.nomefase = '" + ui->comboBox->currentText() + "'"))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
        return;
    }

    if(query.next())
    {
        this->codfase = query.value(0).toString();
    }
}

void SelecionarFase::atualizarComboBox()
{
    ui->comboBox->clear();

    QSqlQuery query;

    if(!query.exec("SELECT nomefase FROM fase WHERE fase.codtemporada = " + this->codtemporada + " ORDER BY codfase"))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
        return;
    }

    ui->comboBox->addItem("");

    while(query.next())
    {
        ui->comboBox->addItem(query.value(0).toString());
    }
}

void SelecionarFase::on_confirmar_clicked()
{
    QSqlQuery query;

    if(!query.exec("SELECT fase.istorneio FROM fase WHERE fase.codfase = " + this->codfase))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
        return;
    }

    if(!query.next())
    {
        QMessageBox::critical(0, "Erro!", "Não foi possível achar o id da fase correspondente, contacte o desenvolvedor do software para solucionar problemas.");
        return;
    }

    if(query.value(0).toString() == "true")
    {
        telatorneio = new telaTorneio(codtemporada, codfase);
        connect(telatorneio, SIGNAL(destroyed(QObject*)), this, SLOT(atualizarComboBox()));
        telatorneio->show();

        close();
    }
    else
    {
        telatemporada = new telaTemporada(codtemporada, codfase);
        connect(telatemporada, SIGNAL(destroyed(QObject*)), this, SLOT(atualizarComboBox()));
        telatemporada->show();

        close();
    }
}
