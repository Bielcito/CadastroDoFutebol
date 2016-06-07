#include "cadastroEstruturaTemporada.h"
#include "ui_cadastroEstruturaTemporada.h"
#include <QMessageBox>
#include <QSqlError>

cadastroEstruturaTemporada::cadastroEstruturaTemporada(QString codtemporada, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::cadastroEstruturaTemporada)
{
    ui->setupUi(this);

    setWindowModality(Qt::ApplicationModal);

    this->codtemporada = codtemporada;

    //Inicializa as fases:
    initiateLists();

    //Atualiza os grupos de acordo com a fase selecionada:
    connect(ui->fases, SIGNAL(itemSelectionChanged()), this, SLOT(mostrarGrupos()));
    connect(ui->fases, SIGNAL(itemSelectionChanged()), this, SLOT(updateTorneio()));

    //Ativa os botões de fases:
    connect(ui->fases, SIGNAL(itemSelectionChanged()), this, SLOT(faseButtons()));
    connect(ui->nomeFase, SIGNAL(textChanged(QString)), this, SLOT(faseWrite()));

    //Ativa os botões de grupos, os botões de rodadas, e atualiza as rodadas do grupo selecionado:
    connect(ui->grupos, SIGNAL(itemSelectionChanged()), this, SLOT(grupoButtons()));
    connect(ui->nomeGrupo, SIGNAL(textChanged(QString)), this, SLOT(grupoWrite()));
    connect(ui->grupos, SIGNAL(itemSelectionChanged()), this, SLOT(mostrarRodadas()));

    inicializarDisputas();
}

cadastroEstruturaTemporada::~cadastroEstruturaTemporada()
{
    delete ui;
}

void cadastroEstruturaTemporada::on_cancelar_clicked()
{
    delete this;
}

void cadastroEstruturaTemporada::mostrarGrupos()
{   
    QSqlQuery query;
    QString nomefase = ui->fases->currentItem()->text();

    if(!query.exec("SELECT fase.istorneio FROM fase WHERE fase.nomefase = '" + nomefase + "' AND fase.codtemporada = " + this->codtemporada))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
        return;
    }

    if(!query.next())
    {
        QMessageBox::critical(0, "Erro!", "Erro inesperado. MostrarGrupos fase.istorneio");
        return;
    }

    ui->nomeGrupo->clear();

    if(ui->fases->selectedItems().empty())
    {
        ui->grupos->setEnabled(false);
        ui->nomeGrupo->setEnabled(false);
        ui->grupos->addItem("Selecione uma Fase");
        return;
    }
    else
    {
        if(query.value(0).toString() == "true")
        {
            ui->nomeGrupo->setDisabled(true);
        }
        else
        {
            ui->nomeGrupo->setEnabled(true);
        }

        ui->grupos->setEnabled(true);
    }

    if(!query.exec("SELECT grupo.nomegrupo FROM fase LEFT JOIN grupo ON (grupo.codfase = fase.codfase) WHERE fase.nomefase = '" + nomefase + "' AND fase.codtemporada = " + this->codtemporada + " ORDER BY grupo.codgrupo"))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
        return;
    }

    ui->grupos->clear();
    ui->rodadas->clear();

    while(query.next())
    {
        ui->grupos->addItem(query.value(0).toString());
    }
}

void cadastroEstruturaTemporada::initiateLists()
{
    QSqlQuery query;
    if(!query.exec("SELECT nomefase FROM fase WHERE fase.codtemporada = " + this->codtemporada + " ORDER BY codfase"))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
        return;
    }

    ui->fases->clear();

    while(query.next())
    {
        ui->fases->addItem(query.value(0).toString());
    }
}

void cadastroEstruturaTemporada::inicializarDisputas()
{
    nomesTorneio << "Final" << "Semifinais" << "Quartas de final" << "Oitavas de final" << "Décima-sextas de final" << "Trigésima-segundas de final" << "Sextagégima-quartas de final";
}

QString cadastroEstruturaTemporada::converterParaDisputa(QString num)
{
    int contador = num.toInt();

    if(contador > 8)
    {
        QMessageBox::critical(0, "Erro!", "Erro de operacionalização. converterParaDisputa(QString num) cadastroEstruturaTemporada.cpp");
        return "";
    }

    return nomesTorneio.at(contador - 1);
}

void cadastroEstruturaTemporada::on_incluirFase_clicked()
{
    QSqlQuery query;

    //Verifica se o nome está preenchido:
    if(ui->nomeFase->text().isEmpty())
    {
        QMessageBox::critical(0, "Erro!", "O nome não pode estar vazio.");
        return;
    }

    //Verifica se o nome já existe:
    if(!query.exec("SELECT nomefase FROM fase WHERE fase.codtemporada = " + this->codtemporada))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
        return;
    }

    while(query.next())
    {
        if(ui->nomeFase->text() == query.value(0).toString())
        {
            QMessageBox::critical(0, "Erro!", "Este nome já existe, por favor escolha outro.");
            return;
        }
    }

    //Inclui o nome na fase:
    if(!query.exec("INSERT INTO fase VALUES (default, " + this->codtemporada + ", '" + ui->nomeFase->text() + "')"))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
        return;
    }

    ui->nomeFase->clear();
    ui->grupos->clear();

    initiateLists();
}

void cadastroEstruturaTemporada::on_excluirFase_clicked()
{
    //Pega o ID da fase atual:
    QSqlQuery query;
    if(!query.exec("SELECT fase.codfase FROM fase WHERE fase.nomefase = '" + ui->fases->currentItem()->text() + "' AND fase.codtemporada = " + this->codtemporada))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
        return;
    }

    query.next();

    QString codfase = query.value(0).toString();

    if(!query.exec("SELECT * FROM grupo WHERE grupo.codfase = " + codfase))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
        return;
    }

    if(query.next())
    {
        QMessageBox::critical(0, "Erro!", "Não é possível excluir esta fase, pois já existem grupos para ela criados. Remova todos os grupos desta fase e tente novamente.");
        return;
    }

    if(!query.exec("DELETE FROM fase WHERE fase.codfase = " + codfase))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
        return;
    }

    delete ui->fases->currentItem();
}

void cadastroEstruturaTemporada::on_alterarFase_clicked()
{
    //Pega o ID da fase atual:
    QSqlQuery query;
    if(!query.exec("SELECT fase.codfase FROM fase WHERE fase.nomefase = '" + ui->fases->currentItem()->text() + "' AND fase.codtemporada = " + this->codtemporada))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
        return;
    }

    query.next();

    QString codfase = query.value(0).toString();

    //Verifica se o nome está preenchido:
    if(ui->nomeFase->text().isEmpty())
    {
        QMessageBox::critical(0, "Erro!", "O nome não pode estar vazio.");
        return;
    }

    //Verifica se o nome já existe:
    if(!query.exec("SELECT nomefase FROM fase WHERE fase.codtemporada = " + this->codtemporada + " AND fase.codfase != " + codfase))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
        return;
    }

    while(query.next())
    {
        if(ui->nomeFase->text() == query.value(0).toString())
        {
            QMessageBox::critical(0, "Erro!", "Este nome já existe, por favor escolha outro.");
            return;
        }
    }

    if(!query.exec("UPDATE fase SET nomefase = '" + ui->nomeFase->text() + "' WHERE fase.nomefase = '" + ui->fases->currentItem()->text() + "' AND fase.codtemporada = " + this->codtemporada))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
        return;
    }

    initiateLists();

    ui->nomeFase->clear();
}

void cadastroEstruturaTemporada::faseButtons()
{
    if(ui->fases->selectedItems().size() > 0)
    {
        if(ui->nomeFase->text().size() > 0)
        {
            ui->alterarFase->setEnabled(true);
        }
        else
        {
            ui->alterarFase->setDisabled(true);
        }
        ui->excluirFase->setEnabled(true);
    }
    else
    {
        ui->alterarFase->setDisabled(true);
        ui->excluirFase->setDisabled(true);
    }
}

void cadastroEstruturaTemporada::faseWrite()
{
    if(ui->nomeFase->text().size() > 0)
    {
        ui->incluirFase->setEnabled(true);
        if(ui->fases->selectedItems().size() > 0)
        {
            ui->alterarFase->setEnabled(true);
        }
        else
        {
            ui->alterarFase->setDisabled(true);
        }
    }
    else
    {
        ui->incluirFase->setDisabled(true);
        ui->alterarFase->setDisabled(true);
    }
}

void cadastroEstruturaTemporada::grupoButtons()
{
    QSqlQuery query;

    //Pega a fase:
    if(!query.exec("SELECT fase.codfase, fase.istorneio FROM fase WHERE fase.nomefase = '" + ui->fases->selectedItems().first()->text() + "' AND fase.codtemporada = " + this->codtemporada))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
        return;
    }

    if(!query.next())
    {
        QMessageBox::critical(0, "Erro!", "Situação inesperada, querynextgrupoButtons!");
        return;
    }

    QString codfase = query.value(0).toString();
    QString istorneio = query.value(1).toString();
    QString numeroderodadas;

    //Pega o número de rodadas do grupo único, caso a fase seja de eliminação:
    if(istorneio == "true")
    {
        if(!query.exec("SELECT grupo.numeroderodadas FROM grupo WHERE grupo.codfase = " + codfase))
        {
            QMessageBox::critical(0, "Erro!", query.lastError().text());
            return;
        }

        if(!query.next())
        {
            QMessageBox::critical(0, "Erro!", "Erro de operacionalização, cadastroEstruturaTemoprada::grupoButtons");
            return;
        }

        numeroderodadas = query.value(0).toString();
    }

    if(ui->grupos->selectedItems().size() > 0)
    {
        if(ui->nomeGrupo->text().size() > 0 && istorneio != "true")
        {
            ui->alterarGrupo->setEnabled(true);
        }
        else
        {
            ui->alterarGrupo->setDisabled(true);
        }

        if(istorneio != "true")
        {
            ui->excluirGrupo->setEnabled(true);
        }

        if(numeroderodadas.toInt()+1 <= maxNumberRodadasDisputa)
        {
            ui->adicionarRodada->setEnabled(true);
        }
        else
        {
            ui->adicionarRodada->setDisabled(true);
        }

        if(ui->rodadas->count() > 0)
        {
            ui->diminuirRodada->setEnabled(true);
        }
        else
        {
            ui->diminuirRodada->setDisabled(true);
        }
    }
    else
    {
        ui->alterarGrupo->setDisabled(true);
        ui->excluirGrupo->setDisabled(true);
        ui->adicionarRodada->setDisabled(true);
        ui->diminuirRodada->setDisabled(true);
    }
}

void cadastroEstruturaTemporada::grupoWrite()
{
    if(ui->nomeGrupo->text().size() > 0 && ui->fases->selectedItems().size() > 0)
    {
        ui->incluirGrupo->setEnabled(true);
        if(ui->grupos->selectedItems().size() > 0)
        {
            ui->alterarGrupo->setEnabled(true);
        }
        else
        {
            ui->alterarGrupo->setDisabled(true);
        }
    }
    else
    {
        ui->incluirGrupo->setDisabled(true);
        ui->alterarGrupo->setDisabled(true);
    }
}

void cadastroEstruturaTemporada::on_incluirGrupo_clicked()
{
    //Pega o id da fase selecionada:
    QSqlQuery query;
    if(!query.exec("SELECT fase.codfase FROM fase WHERE fase.nomefase = '" + ui->fases->currentItem()->text() + "' AND fase.codtemporada = " + this->codtemporada))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
        return;
    }

    query.next();

    QString codfase = query.value(0).toString();

    //Verifica se o nome está preenchido:
    if(ui->nomeGrupo->text().isEmpty())
    {
        QMessageBox::critical(0, "Erro!", "O nome do grupo não pode estar vazio.");
        return;
    }

    //Verifica se o nome já existe:
    if(!query.exec("SELECT nomegrupo FROM grupo WHERE grupo.codfase = " + codfase))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
        return;
    }

    while(query.next())
    {
        if(ui->nomeGrupo->text() == query.value(0).toString())
        {
            QMessageBox::critical(0, "Erro!", "Este nome já existe, por favor escolha outro.");
            return;
        }
    }

    //Inclui o nome nos grupos:
    if(!query.exec("INSERT INTO grupo VALUES (default, " + codfase + ", '" + ui->nomeGrupo->text() + "', 0)"))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
        return;
    }

    ui->nomeGrupo->clear();

    mostrarGrupos();
}

void cadastroEstruturaTemporada::on_excluirGrupo_clicked()
{
    QSqlQuery query;
    QString codfase, codgrupo;
    if(!query.exec("SELECT fase.codfase, fase.istorneio FROM fase WHERE fase.nomefase = '" + ui->fases->currentItem()->text() + "' AND fase.codtemporada = " + this->codtemporada))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
        return;
    }

    if(query.next())
    {
        if(query.value(1).toString() == "true")
        {
            QMessageBox::critical(0, "Erro!", "Não é possível excluir o 'Grupo Único', ele existe apenas para disputas de eliminação. Caso queira uma fase sem grupos, desmarque a opção 'Fase de eliminação' da fase selecionada.");
            ui->checkBox->setChecked(false);
            return;
        }
        codfase = query.value(0).toString();
    }

    if(!query.exec("SELECT grupo.codgrupo FROM grupo WHERE grupo.nomegrupo = '" + ui->grupos->currentItem()->text() + "' AND grupo.codfase = " + codfase))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
        return;
    }

    if(query.next())
    {
        codgrupo = query.value(0).toString();
    }

    if(!query.exec("SELECT * FROM rodada WHERE rodada.codgrupo = " + codgrupo))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
        return;
    }

    if(query.next())
    {
        QMessageBox::critical(0, "Erro!", "Não é possível deletar este grupo, pois já existem rodadas para ele criadas. Remova todas as rodadas deste grupo e tente novamente.");
        return;
    }

    if(!query.exec("DELETE FROM grupo WHERE grupo.nomegrupo = '" + ui->grupos->currentItem()->text() + "' AND grupo.codfase = " + codfase))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
        return;
    }

    delete ui->grupos->currentItem();
}

void cadastroEstruturaTemporada::on_alterarGrupo_clicked()
{
    //Pega o id da fase selecionada:
    QSqlQuery query;
    if(!query.exec("SELECT fase.codfase FROM fase WHERE fase.nomefase = '" + ui->fases->currentItem()->text() + "' AND fase.codtemporada = " + this->codtemporada))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
        return;
    }

    query.next();

    QString codfase = query.value(0).toString();

    //Pega o ID do grupo atual:
    if(!query.exec("SELECT grupo.codgrupo FROM grupo WHERE grupo.nomegrupo = '" + ui->grupos->currentItem()->text() + "' AND grupo.codfase = " + codfase))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
        return;
    }

    query.next();

    QString codgrupo = query.value(0).toString();

    //Verifica se o nome está preenchido:
    if(ui->nomeGrupo->text().isEmpty())
    {
        QMessageBox::critical(0, "Erro!", "O nome não pode estar vazio.");
        return;
    }

    //Verifica se o nome já existe:
    if(!query.exec("SELECT nomegrupo FROM grupo WHERE grupo.codfase = " + codfase + " AND grupo.codgrupo != " + codgrupo))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
        return;
    }

    while(query.next())
    {
        if(ui->nomeGrupo->text() == query.value(0).toString())
        {
            QMessageBox::critical(0, "Erro!", "Este nome já existe, por favor escolha outro.");
            return;
        }
    }

    if(!query.exec("UPDATE grupo SET nomegrupo = '" + ui->nomeGrupo->text() + "' WHERE grupo.nomegrupo = '" + ui->grupos->currentItem()->text() + "' AND grupo.codfase = " + codfase))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
        return;
    }

    mostrarGrupos();

    ui->nomeGrupo->clear();
}

void cadastroEstruturaTemporada::on_adicionarRodada_clicked()
{
    QSqlQuery query;

    //Pega o id da fase selecionada:
    if(!query.exec("SELECT fase.codfase FROM fase WHERE fase.nomefase = '" + ui->fases->currentItem()->text() + "' AND fase.codtemporada = " + this->codtemporada))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
        return;
    }

    query.next();

    QString codfase = query.value(0).toString();

    //Id e número de rodadas do grupo selecionado:
    if(!query.exec("SELECT grupo.codgrupo, grupo.numeroderodadas FROM grupo WHERE grupo.nomegrupo = '" + ui->grupos->currentItem()->text() + "' AND grupo.codfase = " + codfase))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
        return;
    }

    query.next();

    QString codgrupo = query.value(0).toString();
    QString numeroderodadas = QString::number(query.value(1).toInt()+1);


    //Incrementando as rodadas em 1:
    if(!query.exec("UPDATE grupo SET numeroderodadas = " + numeroderodadas + " WHERE grupo.codgrupo = " + codgrupo))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
        return;
    }

    //Criando a rodada e atribuindo ao grupo no banco de dados:
    if(!query.exec("INSERT INTO rodada VALUES(default, " + codgrupo + ", " + numeroderodadas + ")"))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
        return;
    }

    mostrarRodadas();
}

void cadastroEstruturaTemporada::mostrarRodadas()
{
    if(ui->fases->selectedItems().size() == 0)
    {
        return;
    }

    if(ui->grupos->selectedItems().size() == 0)
    {
        ui->rodadas->setDisabled(true);
        return;
    }
    else
    {
        ui->rodadas->setEnabled(true);
    }

    QSqlQuery query;

    //Pega o id da fase selecionada:
    if(!query.exec("SELECT fase.codfase, fase.istorneio FROM fase WHERE fase.nomefase = '" + ui->fases->currentItem()->text() + "' AND fase.codtemporada = " + this->codtemporada))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
        return;
    }

    query.next();

    QString codfase = query.value(0).toString();
    QString istorneio = query.value(1).toString();

    //Pega o ID do grupo atual:
    if(!query.exec("SELECT grupo.codgrupo FROM grupo WHERE grupo.nomegrupo = '" + ui->grupos->currentItem()->text() + "' AND grupo.codfase = " + codfase))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
        return;
    }

    query.next();

    QString codgrupo = query.value(0).toString();

    //Pega as rodadas do grupo selecionado e mostra na interface:
    if(!query.exec("SELECT rodada.numerodarodada FROM rodada WHERE rodada.codgrupo = " + codgrupo + " ORDER BY rodada.numerodarodada"))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
        return;
    }

    ui->rodadas->clear();

    while(query.next())
    {
        if(istorneio == "true")
        {
            if(query.value(0).toInt() <= this->maxNumberRodadasDisputa)
            {
                ui->rodadas->addItem(converterParaDisputa(query.value(0).toString()));
            }
            else
            {
                QMessageBox::critical(0, "Erro!", "Erro de operacionalização. cadastroEstruturaTemporada::mostrarRodadas()");
            }
        }
        else
        {
            ui->rodadas->addItem(query.value(0).toString());
        }
    }

    grupoButtons();
}

void cadastroEstruturaTemporada::on_diminuirRodada_clicked()
{
    QSqlQuery query;

    //Pega o id da fase selecionada:
    if(!query.exec("SELECT fase.codfase FROM fase WHERE fase.nomefase = '" + ui->fases->currentItem()->text() + "' AND fase.codtemporada = " + this->codtemporada))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
        return;
    }

    query.next();

    QString codfase = query.value(0).toString();

    //Id e número de rodadas do grupo selecionado:
    if(!query.exec("SELECT grupo.codgrupo, grupo.numeroderodadas FROM grupo WHERE grupo.nomegrupo = '" + ui->grupos->currentItem()->text() + "' AND grupo.codfase = " + codfase))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
        return;
    }

    query.next();

    QString codgrupo = query.value(0).toString();
    QString numeroderodadas = QString::number(query.value(1).toInt());
    QString numeroderodadasDecrementado = QString::number(query.value(1).toInt()-1);


    //Decrementando as rodadas em 1:
    if(!query.exec("UPDATE grupo SET numeroderodadas = " + numeroderodadasDecrementado + " WHERE grupo.codgrupo = " + codgrupo))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
        return;
    }

    //Deletando a rodada e atribuindo ao grupo no banco de dados:
    if(!query.exec("DELETE FROM rodada WHERE rodada.numerodarodada = " + numeroderodadas + " AND rodada.codgrupo = " + codgrupo))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
        return;
    }

    mostrarRodadas();
}

void cadastroEstruturaTemporada::on_checkBox_clicked(bool checked)
{
    QSqlQuery query;

    //Pega o id da fase selecionada:
    if(!query.exec("SELECT fase.codfase, fase.istorneio FROM fase WHERE fase.nomefase = '" + ui->fases->currentItem()->text() + "' AND fase.codtemporada = " + this->codtemporada))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
        return;
    }

    query.next();

    QString codfase = query.value(0).toString();
    QString istorneio = query.value(1).toString();

    //Se for marcado como verdadeiro, ele verifica se existem grupos na fase selecionada,
    //se existir, não deixa virar torneio. Se não existir, ele vai criar um grupo único relacionado à esta fase.
    //Ao desativar o checkbox, este grupo único deverá ser excluído.
    if (checked == true && istorneio == "false")
    {
        if(!query.exec("SELECT * FROM grupo WHERE grupo.codfase = " + codfase))
        {
            QMessageBox::critical(0, "Erro!", query.lastError().text());
            return;
        }

        if(query.next())
        {
            QMessageBox::critical(0, "Erro!", "Não é possível definir esta fase como torneio pois já existem grupos criados para ela. Por favor, exclua todos os grupos correspondentes a essa fase e tente novamente.");
            ui->checkBox->setChecked(false);
            return;
        }
        else
        {
            if(!query.exec("UPDATE fase SET istorneio = '1' WHERE fase.codfase = " + codfase))
            {
                QMessageBox::critical(0, "Erro!", query.lastError().text());
                return;
            }
            if(!query.exec("INSERT INTO grupo VALUES (default, " + codfase + ", 'Grupo Único', 0)"))
            {
                QMessageBox::critical(0, "Erro!", query.lastError().text());
                return;
            }
        }

        mostrarGrupos();
    }
    else
    {
        if(istorneio == "true")
        {
            if(!query.exec("DELETE FROM grupo WHERE grupo.codfase = " + codfase))
            {
                QMessageBox::critical(0, "Erro!", query.lastError().text());
                return;
            }
            if(!query.exec("UPDATE fase SET istorneio = '0' WHERE fase.codfase = " + codfase))
            {
                QMessageBox::critical(0, "Erro!", query.lastError().text());
                return;
            }

            mostrarGrupos();
        }
    }
}

void cadastroEstruturaTemporada::updateTorneio()
{
    QSqlQuery query;

    if(ui->fases->selectedItems().empty())
    {
        ui->checkBox->setChecked(false);
        ui->checkBox->setEnabled(false);
        return;
    }
    else
    {
        ui->checkBox->setEnabled(true);
    }

    //Pega o valor do torneio da fase selecionada:
    if(!query.exec("SELECT fase.istorneio FROM fase WHERE fase.nomefase = '" + ui->fases->currentItem()->text() + "' AND fase.codtemporada = " + this->codtemporada))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
        return;
    }

    query.next();

    QString istorneio = query.value(0).toString();

    if(istorneio == "true")
    {
        ui->checkBox->setChecked(true);
    }
    else
    {
        ui->checkBox->setChecked(false);
    }
}
