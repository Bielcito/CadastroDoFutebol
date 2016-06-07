#include "cadastroTemporada.h"
#include "ui_cadastroTemporada.h"

cadastroTemporada::cadastroTemporada(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::cadastroTemporada)
{
    ui->setupUi(this);

    setWindowModality(Qt::ApplicationModal);

    initiateComboBox();
    initiateListWidget("123456");

    editMode = false;
}

cadastroTemporada::cadastroTemporada(QString sCode, QString s0, QString s1, QString s2, QString s3, QString s4, QString s5, QString s6, QString s7, QString s8, QString s9, QString s10, QString s11, QString s12, QString s13, QString s14, QString s15, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::cadastroTemporada)
{
    ui->setupUi(this);

    setWindowModality(Qt::ApplicationModal);

    initiateComboBox();

    editMode = true;
    editCode = sCode;
    ui->campeonatoRelacionado->setCurrentText(s0);
    ui->tempNomeLabel->setText(s1);
    ui->tempPontosVitoria->setValue(s2.toInt());
    ui->tempPontosEmpate->setValue(s3.toInt());
    ui->tempPontosVitoriaProrrogacao->setValue(s4.toInt());
    ui->tempPontosVitoriaPenaltis->setValue(s5.toInt());
    ui->tempPontosDerrotaProrrogacao->setValue(s6.toInt());
    ui->tempPontosDerrotaPenaltis->setValue(s7.toInt());
    ui->tempDescricao->setText(s8);
    ui->tempNumTimesRebaixados->setValue(s9.toInt());
    ui->tempNumTimesPromovidos->setValue(s10.toInt());
    ui->tempPontosEmpateProrrogacao->setValue(s11.toInt());
    initiateListWidget(s12);
    ui->tempNumCompet1->setValue(s13.toInt());
    ui->tempNumCompet2->setValue(s14.toInt());
    ui->tempNumTimesRebaixamento->setValue(s15.toInt());
}

cadastroTemporada::~cadastroTemporada()
{
    delete ui;
}

/**
 * @brief cadastroTemporada::on_confirmar_clicked
 * Esta função é executada quando o botão "Confirmar" é clicado.
 */
void cadastroTemporada::on_confirmar_clicked()
{
    QSqlQuery query;

    //Verifica se está tudo preenchido:
    if(ui->campeonatoRelacionado->currentText().isEmpty())
    {
        QMessageBox::critical(0, "Erro!", "Por favor preencha o campo \"Campeonato Relacionado\".");
        return;
    }
    if(ui->tempNomeLabel->text().isEmpty())
    {
        QMessageBox::critical(0, "Erro!", "Por favor preencha o campo \"Nome da temporada\".");
        return;
    }

    //Verifica se já existe temporada com nome igual:
    if(!query.exec("SELECT * FROM temporada WHERE nometemporada = '" + ui->tempNomeLabel->text() + "'"))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
        return;
    }
    else
    {
        if(query.next())
        {
            if(editMode && query.value(0).toString() != editCode)
            {
                QMessageBox::critical(0, "Erro!", "Já existe uma temporada com esse nome.");
                return;
            }
            else if(!editMode)
            {
                QMessageBox::critical(0, "Erro!", "Já existe uma temporada com esse nome.");
                return;
            }
        }
    }

    //Converte os nomes do critério de desempate para números em sequência em uam string.
    QString criterios;
    for(int i = 0; i < ui->tempCriteriosDesempate->count(); i++)
    {
        if(ui->tempCriteriosDesempate->item(i)->text() == "Saldo de Gols")
        {
            criterios = criterios + "1";
        }
        else if(ui->tempCriteriosDesempate->item(i)->text() == "Número de Vitórias")
        {
            criterios = criterios + "2";
        }
        else if(ui->tempCriteriosDesempate->item(i)->text() == "Gols Pró")
        {
            criterios = criterios + "3";
        }
        else if(ui->tempCriteriosDesempate->item(i)->text() == "Gols Fora de Casa")
        {
            criterios = criterios + "4";
        }
        else if(ui->tempCriteriosDesempate->item(i)->text() == "Cartão Amarelo")
        {
            criterios = criterios + "5";
        }
        else if(ui->tempCriteriosDesempate->item(i)->text() == "Cartão Vermelho")
        {
            criterios = criterios + "6";
        }
        else
        {
            QMessageBox::critical(0, "Erro!", "Erro ao converter os critérios para númros ao confirmar!");
            return;
        }
    }

    if(editMode)
    {
        if(!query.exec("SELECT codcampeonato FROM campeonato WHERE nome = '" + ui->campeonatoRelacionado->currentText() + "'"))
        {
            QMessageBox::critical(0, "Erro!", query.lastError().text());
            return;
        }
        query.next();
        QString campeonato = query.value(0).toString();
        if(!query.exec("UPDATE temporada SET codcampeonato = " + campeonato +
                   ", nometemporada = '" + ui->tempNomeLabel->text() +
                   "', pontosvitoria = " + ui->tempPontosVitoria->text() +
                   ", pontosempate = " + ui->tempPontosEmpate->text() +
                   ", pontosvitoriaprorrogacao = " + ui->tempPontosVitoriaProrrogacao->text() +
                   ", pontosvitoriapenaltis = " + ui->tempPontosVitoriaPenaltis->text() +
                   ", pontosderrotaprorrogacao = " + ui->tempPontosDerrotaProrrogacao->text() +
                   ", pontosderrotapenaltis = " + ui->tempPontosDerrotaPenaltis->text() +
                   ", descricao = '" + ui->tempDescricao->toPlainText() +
                   "', numtimerebaixado = " + ui->tempNumTimesRebaixados->text() +
                   ", numtimepromovido = " + ui->tempNumTimesPromovidos->text() +
                   ", pontosempateprorrogacao = " + ui->tempPontosEmpateProrrogacao->text() +
                   ", sqldesempate = '" + criterios +
                   "', numtimecompet1 = " + ui->tempNumCompet1->text() +
                   ", numtimecompet2 = " + ui->tempNumCompet2->text() +
                   ", numtimeporrebaixamento = " + ui->tempNumTimesRebaixamento->text() + " WHERE codtemporada = " + editCode))
        {
            QMessageBox::critical(0, "Erro!", query.lastError().text());
        }
    }
    else
    {
        if(!ui->campeonatoRelacionado->currentText().isEmpty())
        {
            if(!query.exec("SELECT codcampeonato FROM campeonato WHERE nome = '" + ui->campeonatoRelacionado->currentText() + "'"))
            {
                QMessageBox::critical(0, "Erro!", query.lastError().text());
                return;
            }
            query.next();
        }
        QString s0 = query.value(0).toString();
        QString s1 = ui->tempNomeLabel->text();
        QString s2 = ui->tempPontosVitoria->text();
        QString s3 = ui->tempPontosEmpate->text();
        QString s4 = ui->tempPontosVitoriaProrrogacao->text();
        QString s5 = ui->tempPontosVitoriaPenaltis->text();
        QString s6 = ui->tempPontosDerrotaProrrogacao->text();
        QString s7 = ui->tempPontosDerrotaPenaltis->text();
        QString s8 = ui->tempDescricao->toPlainText();
        QString s9 = ui->tempNumTimesRebaixados->text();
        QString s10 = ui->tempNumTimesPromovidos->text();
        QString s11 = ui->tempPontosEmpateProrrogacao->text();
        QString s12 = criterios;
        QString s13 = ui->tempNumCompet1->text();
        QString s14 = ui->tempNumCompet2->text();
        QString s15 = ui->tempNumTimesRebaixamento->text();

        if(!query.exec("INSERT INTO temporada VALUES (default, " + s0 + ", '" + s1 + "', " + s2 + ", " + s3 + ", " + s4 + ", " + s5 + ", " + s6 + ", " + s7 + ", '" + s8 + "', " + s9 + ", " + s10 + ", " + s11 + ", '" + s12 + "', " + s13 + ", " + s14 + ", " + s15 + ")"))
        {
            QMessageBox::critical(0, "Erro!", query.lastError().text());
            return;
        }
    }

    delete this;
}

void cadastroTemporada::initiateComboBox()
{
    ui->campeonatoRelacionado->addItem("");

    QSqlQuery query;
    query.exec("SELECT nome FROM campeonato");

    while(query.next())
    {
        ui->campeonatoRelacionado->addItem(query.value(0).toString());
    }
}

void cadastroTemporada::initiateListWidget(QString criterios)
{
    QStringList nomeCriterios;

    for(int i = 0; i < 6; i++)
    {
        if(criterios[i] == '1')
        {
            nomeCriterios << "Saldo de Gols";
        }
        else if(criterios[i] == '2')
        {
            nomeCriterios << "Número de Vitórias";
        }
        else if(criterios[i] == '3')
        {
            nomeCriterios << "Gols Pró";
        }
        else if(criterios[i] == '4')
        {
            nomeCriterios << "Gols Fora de Casa";
        }
        else if(criterios[i] == '5')
        {
            nomeCriterios << "Cartão Amarelo";
        }
        else if(criterios[i] == '6')
        {
            nomeCriterios << "Cartão Vermelho";
        }
        else
        {
            QMessageBox::critical(0, "Erro!", "Erro na inicialização o campo de critérios de desempate!");
            return;
        }
    }

    for(int i = nomeCriterios.size()-1; i >= 0; i--)
    {
        ui->tempCriteriosDesempate->insertItem(0, nomeCriterios[i]);
    }
}

/**
 * @brief cadastroTemporada::on_cancelar_clicked
 * Esta função é executada quando é clicado no botão "Cancelar" da aba temporada.
 */
void cadastroTemporada::on_cancelar_clicked()
{
    close();
}

void cadastroTemporada::on_tempCima_clicked()
{
    int currentRow = ui->tempCriteriosDesempate->currentRow();

    if(currentRow == 0)
    {
        return;
    }

    QListWidgetItem *currentItem = ui->tempCriteriosDesempate->takeItem(currentRow);
    ui->tempCriteriosDesempate->insertItem(currentRow-1, currentItem);
    ui->tempCriteriosDesempate->setCurrentRow(currentRow-1);
}

void cadastroTemporada::on_tempBaixo_clicked()
{
    int currentRow = ui->tempCriteriosDesempate->currentRow();

    if(currentRow == ui->tempCriteriosDesempate->count()-1)
    {
        return;
    }

    QListWidgetItem *currentItem = ui->tempCriteriosDesempate->takeItem(currentRow);
    ui->tempCriteriosDesempate->insertItem(currentRow+1, currentItem);
    ui->tempCriteriosDesempate->setCurrentRow(currentRow+1);
}
