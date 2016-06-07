#include "cadastroJogo.h"
#include "ui_cadastroJogo.h"

cadastroJogo::cadastroJogo(QString codtemporada, QString codfase, QString codgrupo, QString codrodada, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::cadastroJogo)
{
    ui->setupUi(this);

    setWindowModality(Qt::ApplicationModal);

    this->codtemporada = codtemporada;
    this->codfase = codfase;
    this->codgrupo = codgrupo;
    this->codrodada = codrodada;
    editandoEquipeCasa = false;
    editandoEquipeFora = false;

    inicializarListas();

    inicializarComboBox();

    connect(ui->EquipeCasaRelacionada, SIGNAL(currentIndexChanged(int)), this, SLOT(atualizarComboBoxEquipeCasa()));
    connect(ui->EquipeForaRelacionada, SIGNAL(currentIndexChanged(int)), this, SLOT(atualizarComboBoxEquipeFora()));

    connect(ui->GolsTimeCasaPritem, SIGNAL(valueChanged(int)), this, SLOT(somarPontosCasa()));
    connect(ui->GolsTimeCasaProrrogacao, SIGNAL(valueChanged(int)), this, SLOT(somarPontosCasa()));
    connect(ui->GolsTimeCasaPenaltis, SIGNAL(valueChanged(int)), this, SLOT(somarPontosCasa()));

    connect(ui->GolsTimeForaPritem, SIGNAL(valueChanged(int)), this, SLOT(somarPontosFora()));
    connect(ui->GolsTimeForaProrrogacao, SIGNAL(valueChanged(int)), this, SLOT(somarPontosFora()));
    connect(ui->GolsTimeForaPenaltis, SIGNAL(valueChanged(int)), this, SLOT(somarPontosFora()));
}

cadastroJogo::cadastroJogo(QString codtemporada, QString codfase, QString codgrupo, QString codrodada, QStringList equipes, QWidget *parent)
{
    ui->setupUi(this);

    setWindowModality(Qt::ApplicationModal);

    this->codtemporada = codtemporada;
    this->codfase = codfase;
    this->codgrupo = codgrupo;
    this->codrodada = codrodada;
    editandoEquipeCasa = false;
    editandoEquipeFora = false;

    inicializarListas(equipes);

    inicializarComboBox();

    connect(ui->EquipeCasaRelacionada, SIGNAL(currentIndexChanged(int)), this, SLOT(atualizarComboBoxEquipeCasa()));
    connect(ui->EquipeForaRelacionada, SIGNAL(currentIndexChanged(int)), this, SLOT(atualizarComboBoxEquipeFora()));

    connect(ui->GolsTimeCasaPritem, SIGNAL(valueChanged(int)), this, SLOT(somarPontosCasa()));
    connect(ui->GolsTimeCasaProrrogacao, SIGNAL(valueChanged(int)), this, SLOT(somarPontosCasa()));
    connect(ui->GolsTimeCasaPenaltis, SIGNAL(valueChanged(int)), this, SLOT(somarPontosCasa()));

    connect(ui->GolsTimeForaPritem, SIGNAL(valueChanged(int)), this, SLOT(somarPontosFora()));
    connect(ui->GolsTimeForaProrrogacao, SIGNAL(valueChanged(int)), this, SLOT(somarPontosFora()));
    connect(ui->GolsTimeForaPenaltis, SIGNAL(valueChanged(int)), this, SLOT(somarPontosFora()));
}

cadastroJogo::cadastroJogo(QString codjogo, QString codestruturatemporada, QString codequipecasa, QString codequipefora, QString tv, QString nomeestadio, QString golstimecasa, QString golstimefora, QString golstimecasapritem, QString golstimeforapritem, QString prorrogacao, QString penaltis, QString golstimecasaprorrogacao, QString golstimeforaprorrogacao, QString golstimecasapenaltis, QString golstimeforapenaltis, QString publico, QString noticia, QString realizado, QString estatchutecasa, QString estatchutefora, QString estatfaltacasa, QString estatfaltafora, QString estatescanteiocasa, QString estatescanteiofora, QString estatimpedimentocasa, QString estatimpedimentofora, QString datahorajogo, QString codarbitro, QString codestadio, QString codclassificacaotimecasa, QString codclassificacaotimefora, QString codequipevencedora, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::cadastroJogo)
{
    ui->setupUi(this);

    void atualizarComboBox();

    editCode = codjogo;

    QSqlQuery query;
    if(!query.exec("SELECT nomeestruturatemporada FROM estruturatemporada WHERE codestruturatemporada = " + codestruturatemporada))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
    }
    query.next();
    QString nomeestruturatemporada = query.value(0).toString();


    if(!query.exec("SELECT nomeequipe FROM equipe WHERE codequipe = " + codequipecasa + " OR " + codequipefora))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
    }
    query.next();
    QString nomeequipecasa = query.value(0).toString();
    QString nomeequipefora = query.value(0).toString();

    if(!query.exec("SELECT nomearbitro FROM arbitro WHERE codarbitro = " + codarbitro))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
    }
    query.next();
    QString nomearbitro = query.value(0).toString();

    if(!query.exec("SELECT nomeestadio FROM estadio WHERE codestadio = " + codestadio))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
    }
    query.next();
    QString nomeestadioo = query.value(0).toString();

    /*ui->EstruturaTemporadaRelacionada->setCurrentText(nomeestruturatemporada);
    ui->EquipeCasaRelacionada->setCurrentText(nomeequipecasa);
    ui->EquipeForaRelacionada->setCurrentText(nomeequipefora);
    ui->TV->setText(tv);
    ui->NomeEstadio->setText(nomeestadioo);
    ui->GolsTimeCasa->setValue(golstimecasa.toInt());
    ui->GolsTimeFora->setValue(golstimefora.toInt());
    ui->GolsTimeCasaPritem->setValue(golstimecasapritem.toInt());
    ui->GolsTimeForaPritem->setValue(golstimeforapritem.toInt());
    ui->Prorrogacao->setValue(prorrogacao.toInt());
    ui->Penaltis->setValue(penaltis.toInt());
    ui->GolsTimeCasaProrrogacao->setValue(golstimecasaprorrogacao.toInt());
    ui->GolsTimeForaProrrogacao->setValue(golstimeforaprorrogacao.toInt());
    ui->GolsCasaPenaltis->setValue(golstimecasapenaltis.toInt());
    ui->GolsForaPenaltis->setValue(golstimeforapenaltis.toInt());
    ui->Publico->setValue(publico.toInt());
    ui->Noticia->setText(noticia);
    ui->Realizado->setValue(realizado.toInt());
    ui->EstatChuteCasa->setValue(estatchutecasa.toInt());
    ui->EstatChuteFora->setValue(estatchutefora.toInt());
    ui->EstatFaltaCasa->setValue(estatfaltacasa.toInt());
    ui->EstatFaltaFora->setValue(estatfaltafora.toInt());
    ui->EstatEscanteioCasa->setValue(estatescanteiocasa.toInt());
    ui->EstatEscanteioFora->setValue(estatescanteiofora.toInt());
    ui->EstatImpedimentoCasa->setValue(estatimpedimentocasa.toInt());
    ui->EstatImpedimentoFora->setValue(estatimpedimentofora.toInt());
    QDateTime datetime;

    QString day, month, year, hour, minute, second;
    int i;

    for(i = 0; i < datahorajogo.size(); i++)
    {
        if(datahorajogo[i] != '-')
        {
            year = year + datahorajogo[i];
        }
        else
        {
            break;
        }
    }
    for(i++; i < datahorajogo.size(); i++)
    {
        if(datahorajogo[i] != '-')
        {
            day = day + datahorajogo[i];
        }
        else
        {
            break;
        }
    }
    for(i++; i < datahorajogo.size(); i++)
    {
        if(datahorajogo[i] != ' ')
        {
            month = month + datahorajogo[i];
        }
        else
        {
            break;
        }
    }
    for(i++; i < datahorajogo.size(); i++)
    {
        if(datahorajogo[i] != ':')
        {
            hour = hour + datahorajogo[i];
        }
        else
        {
            break;
        }
    }
    for(i++; i < datahorajogo.size(); i++)
    {
        if(datahorajogo[i] != ':')
        {
            minute = minute + datahorajogo[i];
        }
        else
        {
            break;
        }
    }
    for(i++; i < datahorajogo.size(); i++)
    {
            second = second + datahorajogo[i];
    }

    QDate date;
    date.setDate(year.toInt(), month.toInt(), day.toInt());
    QTime time;
    time.setHMS(hour.toInt(), minute.toInt(), second.toInt());

    ui->dateTimeEdit->setDate(date);
    ui->dateTimeEdit->setTime(time);
    ui->ArbitroRelacionado->setCurrentText(nomearbitro);
    ui->EstadioRelacionado->setCurrentText(nomeestadio);

    //Equipe Casa Relacionada:
    ui->EquipeCasaRelacionada->addItem("");

    if(!query.exec("SELECT equipe.nomeequipe FROM classificacao LEFT JOIN equipe ON classificacao.codequipe = equipe.codequipe LEFT JOIN estruturatemporada ON classificacao.codequipe = estruturatemporada.codequipe WHERE estruturatemporada.nomeestruturatemporada = " + ui->EstruturaTemporadaRelacionada->currentText() + " AND equipe.nomeequipe = " + ui->EquipeCasaRelacionada->currentText()))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
        return;
    }

    while(query.next())
    {
        ui->EquipeCasaRelacionada->addItem(query.value(0).toString());
    }

    //Equipe Fora Relacionada:
    ui->EquipeForaRelacionada->addItem("");

    if(!query.exec("SELECT equipe.nomeequipe FROM classificacao LEFT JOIN equipe ON classificacao.codequipe = equipe.codequipe LEFT JOIN estruturatemporada ON classificacao.codequipe = estruturatemporada.codequipe WHERE estruturatemporada.nomeestruturatemporada = " + ui->EstruturaTemporadaRelacionada->currentText() + " AND equipe.nomeequipe = " + ui->EquipeCasaRelacionada->currentText()))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
        return;
    }

    while(query.next())
    {
        ui->EquipeForaRelacionada->addItem(query.value(0).toString());
    }

    ui->ClassificacaoRelacionadaTimeCasa->setCurrentText(codclassificacaotimecasa);
    ui->ClassificacaoRelacionadaTimeFora->setCurrentText(codclassificacaotimefora);*/
}

cadastroJogo::~cadastroJogo()
{
    delete ui;
}

void cadastroJogo::keyPressEvent(QKeyEvent *e)
{
    if(e->key() == Qt::Key_Return)
    {
        ui->Confirmar->click();
    }
}

void cadastroJogo::inicializarListas()
{
    QSqlQuery query;
    if(!query.exec("SELECT equipe.nomeequipe FROM equipe LEFT JOIN equipecompetetemporada ON equipe.codequipe = equipecompetetemporada.codequipe WHERE equipecompetetemporada.codtemporada = " + codtemporada + " AND equipe.codequipe > 0 AND equipe.nomeequipe NOT IN (SELECT equipe.nomeequipe FROM equipe LEFT JOIN jogo ON equipe.codequipe = jogo.codequipecasa OR equipe.codequipe = jogo.codequipefora WHERE (equipe.codequipe = jogo.codequipecasa OR equipe.codequipe = jogo.codequipefora) AND jogo.codrodada = " + codrodada + ")"))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
        return;
    }

    while(query.next())
    {
        this->equipes << query.value(0).toString();
    }

    //Árbitros:
    if(!query.exec("SELECT nomearbitro FROM arbitro WHERE arbitro.codtemporada = " + codtemporada))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
        return;
    }

    while(query.next())
    {
        this->arbitros << query.value(0).toString();
    }

    //Estadios:
    if(!query.exec("SELECT nomeestadio FROM estadio ORDER BY codestadio"))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
        return;
    }

    while(query.next())
    {
        this->estadios << query.value(0).toString();
    }
}

void cadastroJogo::inicializarListas(QStringList equipes)
{
    this->equipes = equipes;

    QSqlQuery query;

    //Árbitros:
    if(!query.exec("SELECT nomearbitro FROM arbitro WHERE arbitro.codtemporada = " + codtemporada))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
        return;
    }

    while(query.next())
    {
        this->arbitros << query.value(0).toString();
    }

    //Estadios:
    if(!query.exec("SELECT nomeestadio FROM estadio ORDER BY codestadio"))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
        return;
    }

    while(query.next())
    {
        this->estadios << query.value(0).toString();
    }
}

void cadastroJogo::inicializarComboBox()
{
    //Inicializando:
    ui->EquipeCasaRelacionada->addItem("");
    ui->EquipeForaRelacionada->addItem("");
    ui->ArbitroRelacionado->addItem("");
    ui->EstadioRelacionado->addItem("");

    //Equipes:
    foreach(QString x, equipes)
    {
        ui->EquipeCasaRelacionada->addItem(x);
        ui->EquipeForaRelacionada->addItem(x);
    }

    //Arbitros:
    foreach(QString x, arbitros)
    {
        ui->ArbitroRelacionado->addItem(x);
    }

    //Estadios:
    foreach(QString x, estadios)
    {
        ui->EstadioRelacionado->addItem(x);
    }
}

void cadastroJogo::atualizarComboBoxEquipeCasa()
{
    QString currenttextfora = ui->EquipeForaRelacionada->currentText();
    QString currenttextcasa = ui->EquipeCasaRelacionada->currentText();

    disconnect(ui->EquipeForaRelacionada, SIGNAL(currentIndexChanged(int)), this, SLOT(atualizarComboBoxEquipeFora()));

    ui->EquipeForaRelacionada->clear();
    ui->EquipeForaRelacionada->addItem("");

    foreach(QString x, equipes)
    {
        ui->EquipeForaRelacionada->addItem(x);
    }
    ui->EquipeForaRelacionada->setCurrentText(currenttextfora);

    if(!currenttextcasa.isEmpty())
    {
        ui->EquipeForaRelacionada->removeItem(ui->EquipeForaRelacionada->findText(currenttextcasa));
    }

    connect(ui->EquipeForaRelacionada, SIGNAL(currentIndexChanged(int)), this, SLOT(atualizarComboBoxEquipeFora()));
}

void cadastroJogo::atualizarComboBoxEquipeFora()
{
    QString currenttextfora = ui->EquipeForaRelacionada->currentText();
    QString currenttextcasa = ui->EquipeCasaRelacionada->currentText();

    disconnect(ui->EquipeCasaRelacionada, SIGNAL(currentIndexChanged(int)), this, SLOT(atualizarComboBoxEquipeCasa()));

    ui->EquipeCasaRelacionada->clear();
    ui->EquipeCasaRelacionada->addItem("");
    foreach(QString x, equipes)
    {
        ui->EquipeCasaRelacionada->addItem(x);
    }
    ui->EquipeCasaRelacionada->setCurrentText(currenttextcasa);

    if(!currenttextfora.isEmpty())
    {
        ui->EquipeCasaRelacionada->removeItem(ui->EquipeCasaRelacionada->findText(currenttextfora));
    }

    connect(ui->EquipeCasaRelacionada, SIGNAL(currentIndexChanged(int)), this, SLOT(atualizarComboBoxEquipeCasa()));
}

void cadastroJogo::on_isTempoNormal_clicked(bool checked)
{
    if(checked)
    {
        ui->GolsTimeCasaPritem->setEnabled(true);
        ui->GolsTimeForaPritem->setEnabled(true);
    }
    else
    {
        ui->GolsTimeCasaPritem->setDisabled(true);
        ui->GolsTimeForaPritem->setDisabled(true);
    }
}

void cadastroJogo::on_isProrrogacao_clicked(bool checked)
{
    if(checked)
    {
        ui->GolsTimeCasaProrrogacao->setEnabled(true);
        ui->GolsTimeForaProrrogacao->setEnabled(true);
    }
    else
    {
        ui->GolsTimeCasaProrrogacao->setDisabled(true);
        ui->GolsTimeForaProrrogacao->setDisabled(true);
    }
}

void cadastroJogo::on_isPenaltis_clicked(bool checked)
{
    if(checked)
    {
        ui->GolsTimeCasaPenaltis->setEnabled(true);
        ui->GolsTimeForaPenaltis->setEnabled(true);
    }
    else
    {
        ui->GolsTimeCasaPenaltis->setDisabled(true);
        ui->GolsTimeForaPenaltis->setDisabled(true);
    }
}

void cadastroJogo::somarPontosCasa()
{
    int resultado = 0;

    resultado += ui->GolsTimeCasaPritem->value();
    resultado += ui->GolsTimeCasaPenaltis->value();
    resultado += ui->GolsTimeCasaProrrogacao->value();

    ui->GolsTimeCasa->setValue(resultado);
}

void cadastroJogo::somarPontosFora()
{
    int resultado = 0;

    resultado += ui->GolsTimeForaPritem->value();
    resultado += ui->GolsTimeForaPenaltis->value();
    resultado += ui->GolsTimeForaProrrogacao->value();

    ui->GolsTimeFora->setValue(resultado);
}

void cadastroJogo::on_Confirmar_clicked()
{
    //Verificar se tudo está preenchido corretamente:
    if(ui->EquipeCasaRelacionada->currentText().isEmpty())
    {
        QMessageBox::critical(0, "Erro!", "Escolha uma equipe anfitriã.");
        return;
    }
    if(ui->EquipeForaRelacionada->currentText().isEmpty())
    {
        QMessageBox::critical(0, "Erro!", "Escolha uma equipe Visitante.");
        return;
    }
    if(ui->GolsTimeCasaPenaltis == ui->GolsTimeForaPenaltis && ui->isPenaltis->isChecked())
    {
        QMessageBox::critical(0, "Erro!", "Os penaltis não podem ser iguais!");
        return;
    }
    if(ui->EstadioRelacionado->currentText().isEmpty())
    {
        QMessageBox::critical(0, "Erro!", "Escolha um estádio.");
        return;
    }

    //Pega os dados da interface e salva em strings locais para serem armazenadas no banco:

    QString codjogo, codrodada, codequipecasa, codequipefora, tv, nomeestadio, golstimecasa, golstimefora,
            golstimecasapritem, golstimeforapritem, prorrogacao, penaltis, golstimecasaprorrogacao,
            golstimeforaprorrogacao, golstimecasapenaltis, golstimeforapenaltis, publico, noticia,
            realizado, estatchutecasa, estatchutefora, estatfaltacasa, estatfaltafora, estatescanteiocasa,
            estatescanteiofora, estatimpedimentocasa, estatimpedimentofora, datahorajogo, codarbitro,
            codestadio, foto1, foto2, codclassificacaotimecasa, codclassificacaotimefora, codequipevencedora;

    codjogo = "default";
    codrodada = this->codrodada;

    //codequipecasa:
    QSqlQuery query;
    if(!query.exec("SELECT codequipe FROM equipe WHERE nomeequipe = '" + ui->EquipeCasaRelacionada->currentText() + "'"))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
        return;
    }

    query.next();

    codequipecasa = query.value(0).toString();

    //codequipefora:
    if(!query.exec("SELECT codequipe FROM equipe WHERE nomeequipe = '" + ui->EquipeForaRelacionada->currentText() + "'"))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
        return;
    }

    query.next();

    codequipefora = query.value(0).toString();

    tv = ui->TV->text();
    nomeestadio = ui->EstadioRelacionado->currentText();
    golstimecasa = ui->GolsTimeCasa->text();
    golstimefora = ui->GolsTimeFora->text();
    golstimecasapritem = ui->GolsTimeCasaPritem->text();
    golstimeforapritem = ui->GolsTimeForaPritem->text();
    prorrogacao = QString::number(ui->isPenaltis->isChecked());
    penaltis = QString::number(ui->isProrrogacao->isChecked());
    golstimecasaprorrogacao = ui->GolsTimeCasaProrrogacao->text();
    golstimeforaprorrogacao = ui->GolsTimeForaProrrogacao->text();
    golstimecasapenaltis = ui->GolsTimeCasaPenaltis->text();
    golstimeforapenaltis = ui->GolsTimeForaPenaltis->text();
    publico = ui->Publico->text();
    noticia = ui->Comentarios->toPlainText();
    realizado = "1";
    estatchutecasa = QString::number(ui->EstatChuteCasa->value());
    estatchutefora = QString::number(ui->EstatChuteFora->value());
    estatfaltacasa = QString::number(ui->EstatFaltaCasa->value());
    estatfaltafora = QString::number(ui->EstatFaltaFora->value());
    estatescanteiocasa = QString::number(ui->EstatEscanteioCasa->value());
    estatescanteiofora = QString::number(ui->EstatEscanteioFora->value());
    estatimpedimentocasa = QString::number(ui->EstatImpedimentoCasa->value());
    estatimpedimentofora = QString::number(ui->EstatImpedimentoFora->value());
    datahorajogo = QString::number(ui->dateTimeEdit->date().year()) +
            "-" + QString::number(ui->dateTimeEdit->date().month()) +
            "-" + QString::number(ui->dateTimeEdit->date().day()) +
            " " + QString::number(ui->dateTimeEdit->time().hour()) +
            ":" + QString::number(ui->dateTimeEdit->time().minute()) +
            ":" + QString::number(ui->dateTimeEdit->time().second());

    //codarbitro:
    if(!query.exec("SELECT codarbitro FROM arbitro WHERE nomearbitro = '" + ui->ArbitroRelacionado->currentText() + "'"))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
        return;
    }
    if(query.next())
    {
        codarbitro = query.value(0).toString();
    }
    else
    {
        codarbitro = "0";
    }

    //codestadio:
    if(!query.exec("SELECT codestadio FROM estadio WHERE nomeestadio = '" + ui->EstadioRelacionado->currentText() + "'"))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
        return;
    }

    if(query.next())
    {
        codestadio = query.value(0).toString();
    }
    else
    {
        codestadio = "0";
    }

    foto1 = "NULL"; //Não implementado ainda.
    foto2 = "NULL"; //Não implementado ainda.

    //Realizar checagem de codclassificacaotimecasa, e se não existir, criar uma para cada time com valores zerados aqui:
    if(!query.exec("SELECT classificacao.codclassificacao FROM classificacao LEFT JOIN fase ON classificacao.codfase = fase.codfase LEFT JOIN equipe ON classificacao.codequipe = equipe.codequipe WHERE equipe.codequipe = " + codequipecasa))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
        return;
    }

    if(!query.next())
    {
        if(!query.exec("INSERT INTO classificacao VALUES(default, " + this->codfase + ", '" + datahorajogo + "', " + codequipecasa + ", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'a', 0, 0, 0) RETURNING codclassificacao"))
        {
            QMessageBox::critical(0, "Erro!", query.lastError().text());
            return;
        }

        query.next();

        codclassificacaotimecasa = query.value(0).toString();
    }
    else
    {
        codclassificacaotimecasa = query.value(0).toString();
    }

    //Realizar chacagem de codclassificacaotimefora, e se não existir, criar uma para cada time com valores zerados aqui:
    if(!query.exec("SELECT classificacao.codclassificacao FROM classificacao LEFT JOIN fase ON classificacao.codfase = fase.codfase LEFT JOIN equipe ON classificacao.codequipe = equipe.codequipe WHERE equipe.codequipe = " + codequipefora))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
        return;
    }

    if(!query.next())
    {
        if(!query.exec("INSERT INTO classificacao VALUES(default, " + this->codfase + ", '" + datahorajogo + "', " + codequipefora + ", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'b', 0, 0, 0) RETURNING classificacao.codclassificacao"))
        {
            QMessageBox::critical(0, "Erro!", query.lastError().text());
            return;
        }

        query.next();

        codclassificacaotimefora = query.value(0).toString();
    }
    else
    {
        codclassificacaotimefora = query.value(0).toString();
    }

    //Pegando o time vencedor:
    codequipevencedora = "NULL";

    if(golstimecasapritem > golstimeforapritem)
    {
        codequipevencedora = codequipecasa;
    }
    else if(golstimeforapritem > golstimecasapritem)
    {
        codequipevencedora = golstimefora;
    }

    if(golstimecasaprorrogacao > golstimeforaprorrogacao)
    {
        codequipevencedora = codequipecasa;
    }
    else if(golstimeforaprorrogacao > golstimecasaprorrogacao)
    {
        codequipevencedora = codequipefora;
    }

    if(golstimecasapenaltis > golstimeforapenaltis)
    {
        codequipevencedora = codequipecasa;
    }
    else if(golstimeforapenaltis > golstimecasapenaltis)
    {
        codequipevencedora = codequipefora;
    }

    //Por fim, inserindo os dados do jogo:
    if(!query.exec("INSERT INTO jogo VALUES(default, " + codrodada +
                   ", " + codequipecasa +
                   ", " + codequipefora +
                   ", '" + tv +
                   "', '" + nomeestadio +
                   "', " +  golstimecasa +
                   ", " + golstimefora +
                   ", " + golstimecasapritem +
                   ", " + golstimeforapritem +
                   ", " + prorrogacao +
                   ", " + penaltis +
                   ", " + golstimecasaprorrogacao +
                   ", " + golstimeforaprorrogacao +
                   ", " + golstimecasapenaltis +
                   ", " + golstimeforapenaltis +
                   ", " + publico +
                   ", '" + noticia +
                   "', " + realizado +
                   ", " + estatchutecasa +
                   ", " + estatchutefora +
                   ", " + estatfaltacasa +
                   ", " + estatfaltafora +
                   ", " + estatescanteiocasa +
                   ", " + estatescanteiofora +
                   ", " + estatimpedimentocasa +
                   ", " + estatimpedimentofora +
                   ", '" + datahorajogo +
                   "', " + codarbitro +
                   ", " + codestadio +
                   ", '" + foto1 +
                   "', '" + foto2 +
                   "', " + codclassificacaotimecasa +
                   ", " + codclassificacaotimefora +
                   ", " + codequipevencedora + ")"))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
        return;
    }

    delete this;
}
