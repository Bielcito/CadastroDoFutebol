#include "telaTemporada.h"
#include "ui_telaTemporada.h"

telaTemporada::telaTemporada(QString codtemporada, QString codfase, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::telaTemporada)
{
    ui->setupUi(this);

    setWindowModality(Qt::ApplicationModal);

    this->codtemporada = codtemporada;
    this->faseSelecionada = codfase;

    mostrar_grupos();
    connect(ui->grupo, SIGNAL(currentIndexChanged(int)), this, SLOT(mostrar_rodadas()));
    connect(ui->rodada, SIGNAL(currentIndexChanged(int)), this, SLOT(mostrar_jogos()));

    //botão alterar e excluir:
    connect(ui->tableWidget, SIGNAL(itemSelectionChanged()), SLOT(alterar_excluir_buttons()));

    //pesquisa:
    //connect(ui->pesquisa, SIGNAL(textChanged(QString)), this, SLOT());
}

telaTemporada::~telaTemporada()
{
    delete ui;
}

void telaTemporada::mostrar_grupos()
{
    QSqlQuery query;

    //Preenchendo o combobox com os grupos da fase selecionada:
    if(!query.exec("SELECT grupo.nomegrupo FROM grupo WHERE grupo.codfase = " + faseSelecionada + " ORDER BY codgrupo"))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
        return;
    }

    ui->grupo->clear();
    ui->grupo->addItem("");

    while(query.next())
    {
        ui->grupo->addItem(query.value(0).toString());
    }
}

void telaTemporada::mostrar_rodadas()
{
    if(ui->grupo->currentText().isEmpty())
    {
        ui->rodada->clear();
        return;
    }

    //Pegando o id do grupo selecionado:
    QSqlQuery query;
    if(!query.exec("SELECT grupo.codgrupo FROM grupo WHERE grupo.nomegrupo = '" + ui->grupo->currentText() + "' AND grupo.codfase = " + faseSelecionada))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
        return;
    }

    query.next();

    grupoSelecionado = query.value(0).toString();

    //Adicionando ao combobox as rodadas do grupo selecionado:
    if(!query.exec("SELECT rodada.numerodarodada FROM rodada WHERE rodada.codgrupo = " + grupoSelecionado + " ORDER BY rodada.numerodarodada"))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
    }

    ui->rodada->clear();
    ui->rodada->addItem("");

    while(query.next())
    {
        ui->rodada->addItem(query.value(0).toString());
    }
}

void telaTemporada::mostrar_jogos()
{
    if(ui->rodada->currentText().isEmpty())
    {
        while(ui->tableWidget->rowCount() > 0)
        {
            ui->tableWidget->removeRow(0);
        }
        ui->tableWidget->clear();
        ui->Incluir->setDisabled(true);
        return;
    }

    //Pegar o id da rodada selecionada:
    QSqlQuery query;
    if(!query.exec("SELECT rodada.codrodada FROM rodada WHERE rodada.numerodarodada = " + ui->rodada->currentText() + " AND rodada.codgrupo = " + grupoSelecionado))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
        return;
    }

    query.next();

    rodadaSelecionada = query.value(0).toString();

    //Inserindo na TableWidget os jogos pertencentes à rodada selecionada:
    if(!query.exec("SELECT jogo.datahorajogo, equipeC.nomeequipe, jogo.golstimecasa, jogo.golstimefora, equipeF.nomeequipe FROM jogo LEFT JOIN equipe AS equipeC ON equipeC.codequipe = jogo.codequipecasa LEFT JOIN equipe AS equipeF ON equipeF.codequipe = jogo.codequipefora WHERE jogo.codrodada = " + rodadaSelecionada))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
        return;
    }

    while(ui->tableWidget->rowCount() > 0)
    {
        ui->tableWidget->removeRow(0);
    }

    while(query.next())
    {
        ui->tableWidget->insertRow(0);
        ui->tableWidget->setItem(0, 0, new QTableWidgetItem(query.value(0).toString()));
        ui->tableWidget->item(0, 0)->setTextAlignment(Qt::AlignCenter);

        ui->tableWidget->setItem(0, 1, new QTableWidgetItem(query.value(1).toString()));
        ui->tableWidget->item(0, 1)->setTextAlignment(Qt::AlignCenter);

        ui->tableWidget->setItem(0, 2, new QTableWidgetItem(query.value(2).toString()));
        ui->tableWidget->item(0, 2)->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);

        ui->tableWidget->setItem(0, 3, new QTableWidgetItem("X"));
        ui->tableWidget->item(0, 3)->setTextAlignment(Qt::AlignCenter);

        ui->tableWidget->setItem(0, 4, new QTableWidgetItem(query.value(3).toString()));
        ui->tableWidget->item(0, 4)->setTextAlignment(Qt::AlignLeft | Qt::AlignVCenter);

        ui->tableWidget->setItem(0, 5, new QTableWidgetItem(query.value(4).toString()));
        ui->tableWidget->item(0, 5)->setTextAlignment(Qt::AlignCenter);
    }

    ui->Incluir->setEnabled(true);
    ui->tableWidget->resizeColumnsToContents();
}

void telaTemporada::on_Incluir_clicked()
{
    jogo = new cadastroJogo(this->codtemporada, this->faseSelecionada, this->grupoSelecionado, this->rodadaSelecionada);
    connect(jogo, SIGNAL(destroyed(QObject*)), this, SLOT(mostrar_jogos()));
    jogo->show();
}

void telaTemporada::alterar_excluir_buttons()
{
    if(ui->tableWidget->selectedItems().size() > 0)
    {
        ui->Alterar->setEnabled(true);
        ui->Excluir->setEnabled(true);
    }
    else
    {
        ui->Alterar->setDisabled(true);
        ui->Excluir->setDisabled(true);
    }
}

void telaTemporada::on_MostrarTabela_clicked()
{
    tabela = new TabelaClassificacao(codtemporada);
    tabela->show();
}

void telaTemporada::on_Excluir_clicked()
{
    QString timecasa = ui->tableWidget->selectedItems().at(1)->text();
    QString timefora = ui->tableWidget->selectedItems().at(5)->text();

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
    if(!query.exec("SELECT codjogo FROM jogo WHERE jogo.codequipecasa = " + casa.value(0).toString() + " AND jogo.codequipefora = " + fora.value(0).toString() + " AND jogo.codrodada = " + this->rodadaSelecionada))
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

    mostrar_jogos();
}

void telaTemporada::on_Fechar_clicked()
{
    this->close();
}
