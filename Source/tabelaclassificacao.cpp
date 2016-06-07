#include "tabelaclassificacao.h"
#include "ui_tabelaclassificacao.h"

TabelaClassificacao::TabelaClassificacao(QString codtemporada, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TabelaClassificacao)
{
    ui->setupUi(this);

    setWindowModality(Qt::ApplicationModal);

    this->codtemporada = codtemporada;

    inicializar_combobox();
    connect(ui->Fase, SIGNAL(currentIndexChanged(QString)), this, SLOT(atualizar_classificacao()));
}

TabelaClassificacao::~TabelaClassificacao()
{
    delete ui;
}

void TabelaClassificacao::inicializar_tabela()
{

    QSqlQuery query;

    if(!query.exec("SELECT classificacao.datajogo, equipe.nomeequipe, classificacao.pontos, classificacao.golspro, classificacao.golscontra, classificacao.saldogols, classificacao.jogos, classificacao.vitoria, classificacao.empate, classificacao.derrota, classificacao.vitoriaprorrogacao, classificacao.derrotaprorrogacao, classificacao.empateprorrogacao, classificacao.vitoriapenaltis, classificacao.derrotapenaltis FROM classificacao LEFT JOIN equipe ON classificacao.codequipe = equipe.codequipe WHERE classificacao.codfase = " + faseSelecionada))
    {}
}

void TabelaClassificacao::inicializar_combobox()
{
    QSqlQuery query;
    if(!query.exec("SELECT nomefase FROM fase WHERE fase.codtemporada = " + this->codtemporada))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
        return;
    }

    ui->Fase->addItem("");

    while(query.next())
    {
        ui->Fase->addItem(query.value(0).toString());
    }
}

void TabelaClassificacao::atualizar_classificacao()
{
    //Zerando a TableWidget:
    while(ui->tableWidget->rowCount() > 0)
    {
        ui->tableWidget->removeRow(0);
    }

    //Checando para ver se está preenchido:
    if(ui->Fase->currentText().isEmpty())
    {
        return;
    }

    //Pegar fase selecionada e salvar na classe:
    QSqlQuery query;
    if(!query.exec("SELECT codfase FROM fase WHERE fase.nomefase = '" + ui->Fase->currentText() + "' AND fase.codtemporada = " + codtemporada))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
        return;
    }

    if(query.next())
    {
        this->faseSelecionada = query.value(0).toString();
    }
    else
    {
        QMessageBox::critical(0, "Erro!", "Não conseguiu pegar a fase selecionada!");
        return;
    }

    //Zerando as tabela de classificação de cada time:
    if(!query.exec("UPDATE classificacao SET pontos = 0, vitoria = 0, empate = 0, derrota = 0, vitoriaprorrogacao = 0, vitoriapenaltis = 0, derrotaprorrogacao = 0, derrotapenaltis = 0, golspro = 0, golscontra = 0, saldogols = 0, jogos = 0, empateprorrogacao = 0 WHERE codclassificacao > 0 AND codfase = " + faseSelecionada))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
        return;
    }

    //Pegar ids dos grupos da fase selecionada:
    QSqlQuery queryGrupos;
    if(!queryGrupos.exec("SELECT codgrupo FROM grupo WHERE grupo.codfase = " + faseSelecionada))
    {
        QMessageBox::critical(0, "Erro!", queryGrupos.lastError().text());
        return;
    }

    while(queryGrupos.next())
    {
        //Pegar ids das rodadas de cada grupo da iteração:
        QSqlQuery queryRodadas;
        if(!queryRodadas.exec("SELECT codrodada FROM rodada WHERE rodada.codgrupo = " + queryGrupos.value(0).toString()))
        {
            QMessageBox::critical(0, "Erro!", queryRodadas.lastError().text());
            return;
        }

        while(queryRodadas.next())//Pegar id do jogo de cada rodada da iteração:
        {
            QSqlQuery queryJogos;
            if(!queryJogos.exec("SELECT codjogo FROM jogo WHERE jogo.codrodada = " + queryRodadas.value(0).toString()))
            {
                QMessageBox::critical(0, "Erro!", queryJogos.lastError().text());
                return;
            }

            while(queryJogos.next())//Para cada jogo, executar a função calcular_jogo(QString jogo):
            {
                calcular_jogo(queryJogos.value(0).toString());
            }
        }
    }

    //Por fim, após atualizar a tabela de classificação, atualiza a interface com os dados:
    if(!query.exec("SELECT datajogo, equipe.nomeequipe, pontos, golspro, golscontra, saldogols, jogos, vitoria, empate, derrota, vitoriaprorrogacao, derrotaprorrogacao, empateprorrogacao, vitoriapenaltis, derrotapenaltis FROM classificacao LEFT JOIN equipe ON classificacao.codequipe = equipe.codequipe WHERE classificacao.codfase = " + faseSelecionada))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
        return;
    }

    while(query.next())
    {
        ui->tableWidget->insertRow(0);
        ui->tableWidget->setItem(0, 0, new QTableWidgetItem(query.value(0).toString()));
        ui->tableWidget->setItem(0, 1, new QTableWidgetItem(query.value(1).toString()));
        ui->tableWidget->setItem(0, 2, new QTableWidgetItem(query.value(2).toString()));
        ui->tableWidget->setItem(0, 3, new QTableWidgetItem(query.value(3).toString()));
        ui->tableWidget->setItem(0, 4, new QTableWidgetItem(query.value(4).toString()));
        ui->tableWidget->setItem(0, 5, new QTableWidgetItem(query.value(5).toString()));
        ui->tableWidget->setItem(0, 6, new QTableWidgetItem(query.value(6).toString()));
        ui->tableWidget->setItem(0, 7, new QTableWidgetItem(query.value(7).toString()));
        ui->tableWidget->setItem(0, 8, new QTableWidgetItem(query.value(8).toString()));
        ui->tableWidget->setItem(0, 9, new QTableWidgetItem(query.value(9).toString()));
        ui->tableWidget->setItem(0, 10, new QTableWidgetItem(query.value(10).toString()));
        ui->tableWidget->setItem(0, 11, new QTableWidgetItem(query.value(11).toString()));
        ui->tableWidget->setItem(0, 12, new QTableWidgetItem(query.value(12).toString()));
        ui->tableWidget->setItem(0, 13, new QTableWidgetItem(query.value(13).toString()));
        ui->tableWidget->setItem(0, 14, new QTableWidgetItem(query.value(14).toString()));
    }
}

void TabelaClassificacao::calcular_jogo(QString codjogo)
{
    //Pegando dados do jogo:
    QSqlQuery query;

    if(!query.exec("SELECT codequipecasa, codequipefora, golstimecasa, golstimefora, golstimecasapritem, golstimeforapritem, prorrogacao, penaltis, golstimecasaprorrogacao, golstimeforaprorrogacao, golstimecasapenaltis, golstimeforapenaltis, datahorajogo, codclassificacaotimecasa, codclassificacaotimefora FROM jogo WHERE jogo.codjogo = " + codjogo))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
        return;
    }

    query.next();

    QString codequipecasa = query.value(0).toString();
    QString codequipefora = query.value(1).toString();
    QString golstimecasa = query.value(2).toString();
    QString golstimefora = query.value(3).toString();
    QString golstimecasapritem = query.value(4).toString();
    QString golstimeforapritem = query.value(5).toString();
    QString prorrogacao = query.value(6).toString();
    QString penaltis = query.value(7).toString();
    QString golstimecasaprorrogacao = query.value(8).toString();
    QString golstimeforaprorrogacao = query.value(9).toString();
    QString golstimecasapenaltis = query.value(10).toString();
    QString golstimeforapenaltis = query.value(11).toString();
    QString datahorajogo = query.value(12).toString();
    QString codclassificacaotimecasa = query.value(13).toString();
    QString codclassificacaotimefora = query.value(14).toString();

    //====//

    //Pegando valor dos pontos para cada tipo de vitória/derrota/empate:
    if(!query.exec("SELECT pontosvitoria, pontosempate, pontosvitoriaprorrogacao, pontosvitoriapenaltis, pontosderrotaprorrogacao, pontosderrotapenaltis, pontosderrotaprorrogacao FROM temporada WHERE codtemporada = " + codtemporada))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
        return;
    }

    query.next();

    QString pontosvitoria = query.value(0).toString();
    QString pontosempate = query.value(1).toString();
    QString pontosvitoriaprorrogacao = query.value(2).toString();
    QString pontosvitoriapenaltis = query.value(3).toString();
    QString pontosderrotaprorrogacao = query.value(4).toString();
    QString pontosderrotapenaltis = query.value(5).toString();
    QString pontosempateprorrogacao = query.value(6).toString();

    //====//

    //Atualizando as tabelas de classificação:
    QString casadatajogo, casapontos = "0", casavitoria = "0", casaempate = "0", casaderrota = "0",
            casavitoriaprorrogacao = "0", casavitoriapenaltis = "0", casaderrotaprorrogacao = "0",
            casaderrotapenaltis = "0", casagolspro, casagolscontra, casasaldogols, casapublico, casalocal,
            casarealizado, casajogos, casaempateprorrogacao = "0";

    casadatajogo = datahorajogo;
    casagolspro = golstimecasa;
    casagolscontra = golstimefora;
    casasaldogols = QString::number(golstimecasa.toInt() - golstimefora.toInt());
    casapublico = "?";
    casalocal = "?";
    casarealizado = "?";
    casajogos = "1";

    QString foradatajogo, forapontos = "0", foravitoria = "0", foraempate = "0", foraderrota = "0",
            foravitoriaprorrogacao = "0", foravitoriapenaltis = "0", foraderrotaprorrogacao = "0",
            foraderrotapenaltis = "0", foragolspro, foragolscontra, forasaldogols, forapublico, foralocal,
            forarealizado, forajogos, foraempateprorrogacao = "0";

    foradatajogo = datahorajogo;
    foragolspro = golstimefora;
    foragolscontra = golstimecasa;
    forasaldogols = QString::number(golstimefora.toInt() - golstimecasa.toInt());
    forapublico = "?";
    foralocal = "?";
    forarealizado = "?";
    forajogos = "1";

    //Pegando o valor dos pontos, vitoria, empate, derrota, vitoriaprorrogacao,
    //vitoriapenaltis, derrotaprorrogacao, derrotapenaltis e casaempateprorrogacao para cada equipe:
    if(golstimecasapritem > golstimeforapritem)
    {
        casapontos = pontosvitoria;
        forapontos = "0";

        casavitoria = "1";
        foraderrota = "1";
    }
    else if(golstimecasapritem < golstimeforapritem)
    {
        casapontos = "0";
        forapontos = pontosvitoria;

        casaderrota = "1";
        foravitoria = "1";
    }
    else
    {
        if(prorrogacao == "1")
        {
            if(golstimecasaprorrogacao > golstimeforaprorrogacao)
            {
                casapontos = pontosvitoriaprorrogacao;
                forapontos = pontosderrotaprorrogacao;

                casavitoriaprorrogacao = "1";
                foraderrotaprorrogacao = "1";
            }
            else if(golstimecasaprorrogacao < golstimeforaprorrogacao)
            {
                casapontos = pontosderrotaprorrogacao;
                forapontos = pontosvitoriaprorrogacao;

                casaderrotaprorrogacao = "1";
                foravitoriaprorrogacao = "1";
            }
            else
            {
                if(penaltis == "1")
                {
                    if(golstimecasapenaltis > golstimeforapenaltis)
                    {
                        casapontos = pontosvitoriapenaltis;
                        forapontos = pontosderrotapenaltis;

                        casavitoriapenaltis = "1";
                        foraderrotapenaltis = "1";
                    }
                    else
                    {
                        casapontos = pontosderrotapenaltis;
                        forapontos = pontosvitoriapenaltis;

                        casaderrotapenaltis = "1";
                        foravitoriapenaltis = "1";
                    }
                }
                else
                {
                    casapontos = pontosempateprorrogacao;
                    forapontos = pontosempateprorrogacao;

                    casaempateprorrogacao = "1";
                    foraempateprorrogacao = "1";
                }
            }
        }
        else
        {
            casapontos = pontosempate;
            forapontos = pontosempate;

            casaempate = "1";
            foraempate = "1";
        }
    }

    //====//

    //Por fim atualizando a tabela de classificação:
    //para equipecasa:
    if(!query.exec("UPDATE classificacao SET "
                   "datajogo = '" + datahorajogo +
                   "', pontos = pontos + " + casapontos +
                   ", vitoria = vitoria + " + casavitoria +
                   ", empate = empate + " + casaempate +
                   ", derrota = derrota + " + casaderrota +
                   ", vitoriaprorrogacao = vitoriaprorrogacao + " + casavitoriaprorrogacao +
                   ", vitoriapenaltis = vitoriapenaltis + " + casavitoriapenaltis +
                   ", derrotaprorrogacao = derrotaprorrogacao + " + casaderrotaprorrogacao +
                   ", derrotapenaltis = derrotapenaltis + " + casaderrotapenaltis +
                   ", golspro = golspro + " + casagolspro +
                   ", golscontra = golscontra + " + casagolscontra +
                   ", saldogols = saldogols + " + casasaldogols +
                   ", jogos = jogos + " + casajogos +
                   ", empateprorrogacao = empateprorrogacao + " + casaempateprorrogacao +
                   " WHERE codclassificacao = " + codclassificacaotimecasa
                   ))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
        return;
    }
    //para equipefora:
    if(!query.exec("UPDATE classificacao SET "
                   "datajogo = '" + datahorajogo +
                   "', pontos = pontos + " + forapontos +
                   ", vitoria = vitoria + " + foravitoria +
                   ", empate = empate + " + foraempate +
                   ", derrota = derrota + " + foraderrota +
                   ", vitoriaprorrogacao = vitoriaprorrogacao + " + foravitoriaprorrogacao +
                   ", vitoriapenaltis = vitoriapenaltis + " + foravitoriapenaltis +
                   ", derrotaprorrogacao = derrotaprorrogacao + " + foraderrotaprorrogacao +
                   ", derrotapenaltis = derrotapenaltis + " + foraderrotapenaltis +
                   ", golspro = golspro + " + foragolspro +
                   ", golscontra = golscontra + " + foragolscontra +
                   ", saldogols = saldogols + " + forasaldogols +
                   ", jogos = jogos + " + forajogos +
                   ", empateprorrogacao = empateprorrogacao + " + foraempateprorrogacao +
                   " WHERE codclassificacao = " + codclassificacaotimefora
                   ))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
        return;
    }
}
