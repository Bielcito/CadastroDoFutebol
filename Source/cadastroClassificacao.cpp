#include "cadastroClassificacao.h"
#include "ui_cadastroClassificacao.h"

cadastroClassificacao::cadastroClassificacao(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::cadastroClassificacao)
{
    ui->setupUi(this);

    setWindowModality(Qt::ApplicationModal);

    initiateComboBox();

    editMode = false;
}

cadastroClassificacao::cadastroClassificacao(QString codclassificacao, QString codestruturatemporada, QString datajogo, QString codequipe, QString pontos, QString vitoria, QString empate, QString derrota, QString vitoriaprorrogacao, QString vitoriapenaltis, QString derrotaprorrogacao, QString derrotapenaltis, QString golspro, QString golscontra, QString saldogols, QString publico, QString local, QString realizado, QString jogos, QString empateprorrogacao, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::cadastroClassificacao)
{
    ui->setupUi(this);

    setWindowModality(Qt::ApplicationModal);

    initiateComboBox();

    editMode = true;

    editCode = codclassificacao;

    QSqlQuery query;
    if(!query.exec("SELECT nomeestruturatemporada FROM estruturatemporada WHERE codestruturatemporada = " + codestruturatemporada))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
        return;
    }
    query.next();

    ui->estruturaTemporadaRelacionada->setCurrentText(query.value(0).toString());

    QString day, month, year;
    int i;

    for(i = 0; i < datajogo.size(); i++)
    {
        if(datajogo[i] != '-')
        {
            year = year + datajogo[i];
        }
        else
        {
            break;
        }
    }
    for(i++; i < datajogo.size(); i++)
    {
        if(datajogo[i] != '-')
        {
            day = day + datajogo[i];
        }
        else
        {
            break;
        }
    }
    for(i++; i < datajogo.size(); i++)
    {
        month = month + datajogo[i];
    }

    QDate date;
    date.setDate(year.toInt(), month.toInt(), day.toInt());
    ui->Data->setDate(date);

    if(!query.exec("SELECT nomeequipe FROM equipe WHERE codequipe = " + codequipe))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
        return;
    }
    query.next();

    ui->equipeRelacionada->setCurrentText(query.value(0).toString());
    ui->Pontos->setValue(pontos.toInt());
    ui->Vitoria->setValue(vitoria.toInt());
    ui->Empate->setValue(empate.toInt());
    ui->Derrota->setValue(derrota.toInt());
    ui->VitoriaProrrogacao->setValue(vitoriaprorrogacao.toInt());
    ui->VitoriaPenaltis->setValue(vitoriapenaltis.toInt());
    ui->DerrotaProrrogacao->setValue(derrotaprorrogacao.toInt());
    ui->DerrotaPenaltis->setValue(derrotapenaltis.toInt());
    ui->GolsPro->setValue(golspro.toInt());
    ui->GolsContra->setValue(golscontra.toInt());
    ui->SaldoGols->setValue(saldogols.toInt());
    ui->Publico->setValue(publico.toInt());
    ui->Local->setText(local);
    ui->Realizado->setValue(realizado.toInt());
    ui->Jogos->setValue(jogos.toInt());
    ui->EmpateProrrogacao->setValue(empateprorrogacao.toInt());
}

cadastroClassificacao::~cadastroClassificacao()
{
    delete ui;
}

void cadastroClassificacao::initiateComboBox()
{
    //Estrutura de Temporada Relacionada:
    ui->estruturaTemporadaRelacionada->addItem("");

    QSqlQuery query;
    if(!query.exec("SELECT nomeestruturatemporada FROM estruturatemporada"))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
        return;
    }

    while(query.next())
    {
        ui->estruturaTemporadaRelacionada->addItem(query.value(0).toString());
    }

    //Equipe Relacionada:
    ui->equipeRelacionada->addItem("");

    if(!query.exec("SELECT nomeequipe FROM equipe"))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
        return;
    }

    while(query.next())
    {
        ui->equipeRelacionada->addItem(query.value(0).toString());
    }
}

void cadastroClassificacao::on_confirmar_clicked()
{
    QSqlQuery query;

    //Verifica se está tudo preenchido:
    if(ui->estruturaTemporadaRelacionada->currentText().isEmpty())
    {
        QMessageBox::critical(0, "Erro!", "Por favor preencha o campo \"Estrutura de Temporada Relacionada\".");
        return;
    }
    if(ui->equipeRelacionada->currentText().isEmpty())
    {
        QMessageBox::critical(0, "Erro!", "Por favor preencha o campo \"Equipe Relacionada\".");
        return;
    }
    if(ui->Local->text().isEmpty())
    {
        QMessageBox::critical(0, "Erro!", "Por favor preencha o campo \"Local\".");
        return;
    }
    if(ui->Realizado->text().isEmpty())
    {
        QMessageBox::critical(0, "Erro!", "Por favor preencha o campo \"Realizado\".");
        return;
    }

    if(editMode)
    {
        if(!query.exec("SELECT codestruturatemporada FROM estruturatemporada WHERE nomeestruturatemporada = '" + ui->estruturaTemporadaRelacionada->currentText() + "'"))
        {
            QMessageBox::critical(0, "Erro!", query.lastError().text());
            return;
        }
        query.next();
        QString estruturatemporada = query.value(0).toString();

        if(!query.exec("SELECT codequipe FROM equipe WHERE nomeequipe = '" + ui->equipeRelacionada->currentText() + "'"))
        {
            QMessageBox::critical(0, "Erro!", query.lastError().text());
            return;
        }
        query.next();
        QString equipe = query.value(0).toString();

        if(!query.exec("UPDATE classificacao SET codestruturatemporada = " + estruturatemporada +
                       ", codequipe = " + equipe +
                       ", datajogo = '" + QString::number(ui->Data->date().year()) + "-" + QString::number(ui->Data->date().month()) + "-" + QString::number(ui->Data->date().day()) +
                       "', pontos = " + ui->Pontos->text() +
                       ", vitoria = " + ui->Vitoria->text() +
                       ", empate = " + ui->Empate->text() +
                       ", derrota = " + ui->Derrota->text() +
                       ", vitoriaprorrogacao = " + ui->VitoriaProrrogacao->text() +
                       ", vitoriapenaltis = " + ui->VitoriaPenaltis->text() +
                       ", derrotaprorrogacao = " + ui->DerrotaProrrogacao->text() +
                       ", derrotapenaltis = " + ui->DerrotaPenaltis->text() +
                       ", golspro = " + ui->GolsPro->text() +
                       ", golscontra = " + ui->GolsContra->text() +
                       ", saldogols = '" + ui->SaldoGols->text() +
                       "', publico = " + ui->Publico->text() +
                       ", local = '" + ui->Local->text() +
                       "', realizado = " + ui->Realizado->text() +
                       ", jogos = " + ui->Jogos->text() +
                       ", empateprorrogacao = " + ui->EmpateProrrogacao->text() + " WHERE codclassificacao = " + editCode))
        {
            QMessageBox::critical(0, "Erro!", query.lastError().text());
        }
    }
    else
    {
        if(!query.exec("SELECT codestruturatemporada FROM estruturatemporada WHERE nomeestruturatemporada = '" + ui->estruturaTemporadaRelacionada->currentText() + "'"))
        {
            QMessageBox::critical(0, "Erro!", query.lastError().text());
            return;
        }
        query.next();
        QString estruturatemporada = query.value(0).toString();

        if(!query.exec("SELECT codequipe FROM equipe WHERE nomeequipe = '" + ui->equipeRelacionada->currentText() + "'"))
        {
            QMessageBox::critical(0, "Erro!", query.lastError().text());
            return;
        }
        query.next();
        QString equipe = query.value(0).toString();

        if(!query.exec("INSERT INTO classificacao VALUES (default, " +
                       estruturatemporada + ", '" +
                       QString::number(ui->Data->date().year()) + "-" + QString::number(ui->Data->date().month()) + "-" + QString::number(ui->Data->date().day()) + "', " +
                       equipe + ", " +
                       ui->Pontos->text() + ", " +
                       ui->Vitoria->text() + ", " +
                       ui->Empate->text() + ", " +
                       ui->Derrota->text() + ", " +
                       ui->VitoriaProrrogacao->text() + ", " +
                       ui->VitoriaPenaltis->text() + ", " +
                       ui->DerrotaProrrogacao->text() + ", " +
                       ui->DerrotaPenaltis->text() + ", " +
                       ui->GolsPro->text() + ", " +
                       ui->GolsContra->text() + ", " +
                       ui->SaldoGols->text() + ", " +
                       ui->Publico->text() + ", '" +
                       ui->Local->text() + "', " +
                       ui->Realizado->text() + ", " +
                       ui->Jogos->text() + ", " +
                       ui->EmpateProrrogacao->text() + ")"))
        {
            QMessageBox::critical(0, "Erro!", query.lastError().text());
            return;
        }
    }

    delete this;
}
