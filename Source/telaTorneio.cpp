#include "telaTorneio.h"
#include "ui_telaTorneio.h"

telaTorneio::telaTorneio(QString codtemporada, QString codfase, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::telaTorneio)
{
    this->codtemporada = codtemporada;
    this->codfase = codfase;

    setWindowModality(Qt::ApplicationModal);

    ui->setupUi(this);

    nomesTorneio << "Final" << "Semifinais" << "Quartas de final" << "Oitavas de final" << "Décima-sextas de final" << "Trigésima-segundas de final" << "Sextagégima-quartas de final";

    atualizar_abas();
}

telaTorneio::~telaTorneio()
{
    delete ui;
}

void telaTorneio::atualizar_abas()
{
    QSqlQuery query;
    if(!query.exec("SELECT grupo.numeroderodadas FROM grupo WHERE grupo.codfase = " + codfase))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
        return;
    }

    if(!query.next())
    {
        QMessageBox::critical(0, "Erro!", "Erro de operacionalização, telaTorneio::atualizar_abas()");
    }

    int numeroderodadas = query.value(0).toInt();

    QTableWidget* tab;

    for(int i = 0; i < numeroderodadas; i++)
    {
        tab = new QTableWidget;
        inicializar_tabela(tab);
        ui->tabWidget->insertTab(0, tab, tr( ((QString)(nomesTorneio[i])).toStdString().c_str() ));
        mostrarJogos(tab, i);
    }
}

void telaTorneio::inicializar_tabela(QTableWidget *table)
{
    table->insertColumn(0);
    table->insertColumn(0);
    table->insertColumn(0);
    table->insertColumn(0);
    table->insertColumn(0);
    table->insertColumn(0);

    table->setEditTriggers(QAbstractItemView::NoEditTriggers);

    table->setSelectionMode(QAbstractItemView::SingleSelection);
    table->setSelectionBehavior(QAbstractItemView::SelectRows);
}

void telaTorneio::mostrarJogos(QTableWidget *table, int num)
{
    if(table == NULL)
    {
        table = (QTableWidget*)ui->tabWidget->currentWidget();
    }

    //Zerar tabela:

    while(table->rowCount() > 0)
    {
        table->removeRow(0);
    }

    QSqlQuery query;

    //Pegar Grupo:
    if(!query.exec("SELECT grupo.codgrupo FROM grupo WHERE grupo.codfase = " + codfase))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
        return;
    }

    if(!query.next())
    {
        QMessageBox::critical(0, "Erro!", "Erro de operacionalização, grupo telaTorneio::mostrarJogos(QTableWidget *, int)");
        return;
    }

    this->codgrupo = query.value(0).toString();

    //Pegar rodada de número = num:
    if(!query.exec("SELECT rodada.codrodada FROM rodada WHERE rodada.codgrupo = " + codgrupo))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
    }

    if(!query.next())
    {
        QMessageBox::critical(0, "Erro!", "Erro de operacionalização, rodada telaTorneio::mostrarJogos(QTableWidget *, int)");
        return;
    }

    this->codrodada = query.value(0).toString();

    if(!query.exec("SELECT jogo.datahorajogo, equipeC.nomeequipe, jogo.golstimecasa, jogo.golstimefora, equipeF.nomeequipe FROM jogo LEFT JOIN equipe AS equipeC ON equipeC.codequipe = jogo.codequipecasa LEFT JOIN equipe AS equipeF ON equipeF.codequipe = jogo.codequipefora WHERE jogo.codrodada = " + codrodada))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
    }

    while(query.next())
    {
        table->insertRow(0);
        table->setItem(0,0, new QTableWidgetItem(query.value(0).toString()));
        table->setItem(0,1, new QTableWidgetItem(query.value(1).toString()));
        table->setItem(0,2, new QTableWidgetItem(query.value(2).toString()));
        table->setItem(0,3, new QTableWidgetItem("X"));
        table->setItem(0,4, new QTableWidgetItem(query.value(3).toString()));
        table->setItem(0,5, new QTableWidgetItem(query.value(4).toString()));

        table->item(0, 2)->setTextAlignment(Qt::AlignVCenter | Qt::AlignRight);
        table->item(0, 3)->setTextAlignment(Qt::AlignVCenter | Qt::AlignHCenter);
        table->item(0, 4)->setTextAlignment(Qt::AlignVCenter | Qt::AlignLeft);

        table->resizeColumnsToContents();
    }
}

void telaTorneio::on_InserirJogo_clicked()
{
    jog = new cadastroJogo(this->codtemporada, this->codfase, this->codgrupo, this->codrodada);
    connect(jog, SIGNAL(destroyed(QObject*)), this, SLOT(callMostrarJogos()));
    jog->show();
}

void telaTorneio::callMostrarJogos()
{
    mostrarJogos(NULL, 0);
}
void telaTorneio::on_Excluir_clicked()
{
    QTableWidget* table = (QTableWidget*)ui->tabWidget->currentWidget();
    QString timecasa = table->selectedItems().at(1)->text();
    QString timefora = table->selectedItems().at(5)->text();

    QSqlQuery casa, fora;
    if(!casa.exec("SELECT codequipe FROM equipe WHERE equipe.nomeequipe = '" + timecasa + "'"))
    {
        QMessageBox::critical(0, "Erro!", casa.lastError().text());
        return;
    }

    if(!casa.next())
    {
        QMessageBox::critical(0, "Erro!", "Não achou a equipe casa.");
        return;
    }

    if(!fora.exec("SELECT codequipe FROM equipe WHERE equipe.nomeequipe = '" + timefora + "'"))
    {
        QMessageBox::critical(0, "Erro!", fora.lastError().text());
        return;
    }

    if(!fora.next())
    {
        QMessageBox::critical(0, "Erro!", "Não achou a equipe fora.");
        return;
    }

    QSqlQuery query;
    if(!query.exec("SELECT codjogo FROM jogo WHERE jogo.codequipecasa = " + casa.value(0).toString() + " AND jogo.codequipefora = " + fora.value(0).toString() + " AND jogo.codrodada = " + this->codrodada))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
        return;
    }

    if(!query.next())
    {
        QMessageBox::critical(0, "Erro!", "Não achou o jogo.");
        return;
    }

    QString codjogo = query.value(0).toString();

    if(!query.exec("DELETE FROM jogo WHERE jogo.codjogo = " + codjogo))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
        return;
    }

    this->callMostrarJogos();
}

void telaTorneio::on_pushButton_clicked()
{
    delete this;
}
