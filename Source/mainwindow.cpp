#include "mainwindow.h"
#include "senha.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    changeFrameStyle();

    resizeTableWidgets();

    showPasswordWindow();

    activateWidgetsUpdates();
}

MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief MainWindow::setSenha
 * @param senha
 * Assim que é pressionado o botão da janela w2, esta função é chamada com a senha do lineEdit
 * passada por parâmetro. Esta função salva a senha passada na variável senha da classe a qual
 * e em seguida, executa o próximo passo.
 */
void MainWindow::setSenha(QString senha)
{
    this->senha = senha;
    db = new Conexao("localhost", "cadastrofutebol", "postgres", senha);
    if(!db->isOpened())
    {
        db->close();
        db = new Conexao("localhost", "postgres", "postgres", senha);
        if(!db->isOpened())
        {
            QMessageBox::critical(0, "Erro!", db->get().lastError().text());
            showPasswordWindow();
            return;
        }
        QSqlQuery(db->get());

        QSqlQuery query;
        if( query.exec("CREATE DATABASE cadastrofutebol") )
        {
            db->close();
        }
        else
        {
            QMessageBox messagebox;
            messagebox.critical(0,"Erro!","Não foi possível criar o banco de dados \"cadastrofutebol\"");
            return;
        }
        db = new Conexao("localhost", "cadastrofutebol", "postgres", senha);
    }

    this->show();
    alterPgpassContent();
}

/**
 * @brief MainWindow::showPasswordWindow
 * Quando esta função é chamada, a janela w2 é aberta para que o usuário coloque sua senha.
 */
void MainWindow::showPasswordWindow()
{
    w2 = new Senha(this);
    w2->show();
}

/**
 * @brief MainWindow::alterPgpassContent
 * Esta função sobreescreve o arquivo pgpass.conf no diretório APPDATA com as senhas que serão necessárias
 * para se logar ao banco sem a necessidade de digitar a senha no prompt de comando.
 * Ao terminar, a função executa o próximo passo.
 */
void MainWindow::alterPgpassContent()
{
    create_pgpassconf();

    // Checa a variável de ambiente APPDATA.

    char* appdata;
    appdata = getenv("APPDATA");
    if(appdata == NULL)
    {
        QMessageBox messageBox;
        messageBox.critical(0,"Erro!","Variável de ambiente \"APPDATA\" não existe neste sistema !");
        return;
    }

    //Cria a string que contém o caminho para o pgpass.conf.

    string path;
    path += appdata;
    path += "\\postgresql\\pgpass.conf";

    //Caso o arquivo não exista, dá erro.

    if (!std::ifstream(path.c_str()))
    {
        QMessageBox messageBox;
        messageBox.critical(0,"Erro!","Não foi possível abrir o arquivo pgpass.conf !");
        return;
    }

    //Edita o arquivo, excluindo o conteúdo que estava nele anteriormente, e adicionando a ele a senha para acessar o banco.

    std::ofstream f;
    f.open(path.c_str(), std::fstream::trunc);

    if(f.is_open())
    {
        f << "localhost:5432:postgres:postgres:" << this->senha.toStdString() << "\n" << "localhost:5432:cadastrofutebol:postgres:" << this->senha.toStdString();
    }

    f.close();

    createInitialDatabase();
}

/**
 * @brief MainWindow::createInitialDatabase
 * Essa função cria o banco de dados inicial para que o programa possa funcionar.
 * Ao terminar, ele chama o próximo passo. Para preencher a tela com os dados do banco.
 */
void MainWindow::createInitialDatabase()
{
    QSqlQuery query(db->get());

    //Leitura do arquivo InitialDatabase.sql para criação do banco de dados inicial:

    QString path = QCoreApplication::applicationDirPath();
    path.append("/InitialDatabase.sql");
    QFile scriptFile(path);
    if (scriptFile.open(QIODevice::ReadOnly))
    {
        // The SQLite driver executes only a single (the first) query in the QSqlQuery
        //  if the script contains more queries, it needs to be splitted.
        QStringList scriptQueries = QTextStream(&scriptFile).readAll().split(";;");

        foreach (QString queryTxt, scriptQueries)
        {
            if (queryTxt.trimmed().isEmpty()) {
                continue;
            }

            QSqlQuery query;

            if (!query.exec(queryTxt))
            {
                QMessageBox messagebox;
                messagebox.critical(0, "Error!", "Não foi possível executar a query.\n" + query.lastError().text());
                return;
            }
            query.finish();
        }
    }
    else
    {
        QMessageBox messagebox;
        messagebox.critical(0, "Error!", "Não foi possível abrir o arquivo \"InitialDatabase.sql\"!");
        return;
    }

    //Criação das pastas necessárias para gerenciamento das imagens e funcionamento da função de backup:

    path = getenv("LOCALAPPDATA");

    QString caminho1 = "/cadastrofutebol";
    QString caminho2 = "/cadastrofutebol/imagens";
    QString caminho3 = "/cadastrofutebol/imagens/campeonato";
    QString caminho4 = "/cadastrofutebol/temp";

    if(path.isEmpty())
    {
        QMessageBox::critical(0, "Erro!", "Não foi possível encontrar a variável de ambiente \"LOCALAPPDATA\"");
        return;
    }

    if(!QDir(path + caminho1).exists())
    {
        QDir().mkdir(path + caminho1);
    }
    if(!QDir(path + caminho2).exists())
    {
        QDir().mkdir(path + caminho2);
    }
    if(!QDir(path + caminho3).exists())
    {
        QDir().mkdir(path + caminho3);
    }
    if(!QDir(path + caminho4).exists())
    {
        QDir().mkdir(path + caminho4);
    }

    gatheringData();
}

/**
 * @brief MainWindow::on_pushButton_2_clicked
 * Esta função é chamada quando o botão "Excluir" é apertado.
 */
void MainWindow::on_campExcluir_clicked()
{
    if(QMessageBox::Yes == QMessageBox(QMessageBox::Information,"Atenção!","Deseja realmente excluir o campeonato selecionado? Esta operação não poderá ser desfeita.", QMessageBox::Yes | QMessageBox::No).exec())
    {
        QString id = ui->campTableWidget->selectedItems().first()->text();
        QSqlQuery query;

        if(!query.exec("DELETE FROM ONLY campeonato WHERE codcampeonato = '" + id + "' RETURNING escudo"))
        {
            QMessageBox::critical(0,"Erro!", query.lastError().text());
            return;
        }

        query.next();

        if(!query.value(0).toString().isEmpty())
        {
            QString path = getenv("LOCALAPPDATA");
            path.append("/cadastrofutebol/imagens/campeonato/" + query.value(0).toString());
            if(!QFile::remove(path))
            {
                QMessageBox::critical(0,"Erro!", "Arquivo " + path + " não foi removido com sucesso, tente removê-lo manualmente mais tarde.");
            }
        }

        ui->campTableWidget->removeRow(ui->campTableWidget->selectedRanges().first().topRow());
    }
}

/**
 * @brief MainWindow::on_pushButton_clicked
 * Esta função é chamada quando o botão "Novo..." é apertado.
 * Ela abre uma nova janela para cadastro de um campeonato.
 */
void MainWindow::on_campNovo_clicked()
{
    camp = new cadastroCampeonato();
    connect(camp, SIGNAL(destroyed()), this, SLOT(atualizar()));
    camp->show();
}

/**
 * @brief MainWindow::isSelected
 * Esta função faz com que os botões "Editar..." e "Excluir" das tableWidgets sejam ativados caso haja
 * algum item selecionado.
 */
void MainWindow::isSelected()
{
    //Campeonato:
    if(ui->campTableWidget->selectedItems().size() > 0)
    {
        ui->campEditar->setEnabled(true);
        ui->campExcluir->setEnabled(true);
    }
    else
    {
        ui->campEditar->setDisabled(true);
        ui->campExcluir->setDisabled(true);
    }

    //Temporada:
    if(ui->tempTableWidget->selectedItems().size() > 0)
    {
        ui->tempEditar->setEnabled(true);
        ui->tempExcluir->setEnabled(true);
        ui->equipesParticipantesAdicionar->setEnabled(true);
        ui->tempEstruturaTemporada->setEnabled(true);
        ui->tempAbrirTemporada->setEnabled(true);
    }
    else
    {
        ui->tempEditar->setDisabled(true);
        ui->tempExcluir->setDisabled(true);
        ui->equipesParticipantesAdicionar->setDisabled(true);
        ui->tempEstruturaTemporada->setDisabled(true);
        ui->tempAbrirTemporada->setDisabled(true);
    }

    //Estádio:
    if(ui->estTableWidget->selectedItems().size() > 0)
    {
        ui->estEditar->setEnabled(true);
        ui->estExcluir->setEnabled(true);
    }
    else
    {
        ui->estEditar->setDisabled(true);
        ui->estExcluir->setDisabled(true);
    }

    //Árbitro:
    if(ui->arbTableWidget->selectedItems().size() > 0)
    {
        ui->arbEditar->setEnabled(true);
        ui->arbExcluir->setEnabled(true);
    }
    else
    {
        ui->arbEditar->setDisabled(true);
        ui->arbExcluir->setDisabled(true);
    }

    //Equipe:
    if(ui->equTableWidget->selectedItems().size() > 0)
    {
        ui->equEditar->setEnabled(true);
        ui->equExcluir->setEnabled(true);
    }
    else
    {
        ui->equEditar->setDisabled(true);
        ui->equExcluir->setDisabled(true);
    }

    //Jogador:
    if(ui->jogTableWidget->selectedItems().size() > 0)
    {
        ui->jogEditar->setEnabled(true);
        ui->jogExcluir->setEnabled(true);
    }
    else
    {
        ui->jogEditar->setDisabled(true);
        ui->jogExcluir->setDisabled(true);
    }
}

/**
 * @brief MainWindow::gatheringData
 * Esta função insere uma nova linha para cada item e preenche esta linha com os campos ID e NOME.
 * Funciona para todas as abas.
 */
void MainWindow::gatheringData()
{
    //Campeonato:
    QSqlQuery query;
    if(!query.exec("SELECT codcampeonato, nome FROM campeonato ORDER BY codcampeonato"))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
        return;
    }
    while(query.next())
    {
        ui->campTableWidget->insertRow(ui->campTableWidget->rowCount());
        ui->campTableWidget->setItem(ui->campTableWidget->rowCount()-1, 0, new QTableWidgetItem(query.value(0).toString()));
        ui->campTableWidget->setItem(ui->campTableWidget->rowCount()-1, 1, new QTableWidgetItem(query.value(1).toString()));
    }

    //Temporada:

    if(!query.exec("SELECT codtemporada, nometemporada FROM temporada ORDER BY codtemporada"))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
        return;
    }
    while(query.next())
    {
        ui->tempTableWidget->insertRow(ui->tempTableWidget->rowCount());
        ui->tempTableWidget->setItem(ui->tempTableWidget->rowCount()-1, 0, new QTableWidgetItem(query.value(0).toString()));
        ui->tempTableWidget->setItem(ui->tempTableWidget->rowCount()-1, 1, new QTableWidgetItem(query.value(1).toString()));
    }

    //Estádio:
    if(!query.exec("SELECT codestadio, nomeestadio FROM estadio ORDER BY codestadio"))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
        return;
    }
    while(query.next())
    {
        ui->estTableWidget->insertRow(ui->estTableWidget->rowCount());
        ui->estTableWidget->setItem(ui->estTableWidget->rowCount()-1, 0, new QTableWidgetItem(query.value(0).toString()));
        ui->estTableWidget->setItem(ui->estTableWidget->rowCount()-1, 1, new QTableWidgetItem(query.value(1).toString()));
    }

    //Árbitro:
    if(!query.exec("SELECT codarbitro, nomearbitro FROM arbitro ORDER BY codarbitro"))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
        return;
    }
    while(query.next())
    {
        ui->arbTableWidget->insertRow(ui->arbTableWidget->rowCount());
        ui->arbTableWidget->setItem(ui->arbTableWidget->rowCount()-1, 0, new QTableWidgetItem(query.value(0).toString()));
        ui->arbTableWidget->setItem(ui->arbTableWidget->rowCount()-1, 1, new QTableWidgetItem(query.value(1).toString()));
    }

    //Equipe:
    if(!query.exec("SELECT codequipe, nomeequipe FROM equipe WHERE nomeequipe != '(sem nome)' ORDER BY codequipe"))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
        return;
    }
    while(query.next())
    {
        ui->equTableWidget->insertRow(ui->equTableWidget->rowCount());
        ui->equTableWidget->setItem(ui->equTableWidget->rowCount()-1, 0, new QTableWidgetItem(query.value(0).toString()));
        ui->equTableWidget->setItem(ui->equTableWidget->rowCount()-1, 1, new QTableWidgetItem(query.value(1).toString()));
    }

    //Jogador:
    if(!query.exec("SELECT codjogador, nomejogador FROM jogador ORDER BY codjogador"))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
        return;
    }
    while(query.next())
    {
        ui->jogTableWidget->insertRow(ui->jogTableWidget->rowCount());
        ui->jogTableWidget->setItem(ui->jogTableWidget->rowCount()-1, 0, new QTableWidgetItem(query.value(0).toString()));
        ui->jogTableWidget->setItem(ui->jogTableWidget->rowCount()-1, 1, new QTableWidgetItem(query.value(1).toString()));
    }
}

void MainWindow::atualizar()
{
    //Campeonato:
    while(ui->campTableWidget->rowCount() > 0)
    {
        ui->campTableWidget->removeRow(0);
    }

    //Temporada:
    while(ui->tempTableWidget->rowCount() > 0)
    {
        ui->tempTableWidget->removeRow(0);
    }

    //Estadio:
    while(ui->estTableWidget->rowCount() > 0)
    {
        ui->estTableWidget->removeRow(0);
    }

    //Árbitro:
    while(ui->arbTableWidget->rowCount() > 0)
    {
        ui->arbTableWidget->removeRow(0);
    }

    //Equipe:
    while(ui->equTableWidget->rowCount() > 0)
    {
        ui->equTableWidget->removeRow(0);
    }

    //Jogador:
    while(ui->jogTableWidget->rowCount() > 0)
    {
        ui->jogTableWidget->removeRow(0);
    }

    gatheringData();
}

/**
 * @brief MainWindow::on_pushButton_3_clicked
 * Esta função é executada quando se clica no botão "Editar...", ao clicar-se nessa função é
 * aberta uma janela já preenchida com os dados atuais da entrada, onde será possível alterar e
 * salvar novamente.
 */
void MainWindow::on_campEditar_clicked()
{
    QString selectedId = ui->campTableWidget->selectedItems().first()->text();
    QSqlQuery query("SELECT tipocampeonato.nometipocampeonato, campeonato.nome, campeonato.pais, campeonato.escudo FROM tipocampeonato INNER JOIN campeonato ON (tipocampeonato.codtipocampeonato = campeonato.codtipocampeonato) WHERE campeonato.codcampeonato = " + selectedId);
    query.next();

    if(!query.value(3).toString().isEmpty())
    {
        QString path;
        path = getenv("LOCALAPPDATA");
        path.append("/cadastrofutebol/imagens/campeonato/" + query.value(3).toString());

        QPixmap* pixmap = new QPixmap;
        pixmap->load(path);
        camp = new cadastroCampeonato(selectedId, query.value(0).toString(), query.value(1).toString(), query.value(2).toString(), pixmap);
    }
    else
    {
        camp = new cadastroCampeonato(selectedId, query.value(0).toString(), query.value(1).toString(), query.value(2).toString(), NULL);
    }
    connect(camp, SIGNAL(destroyed()), this, SLOT(atualizar()));
    camp->show();
}

/**
 * @brief MainWindow::on_actionFazer_Backup_triggered
 * Esta função é chamada quando se aperta no botão "Fazer Backup..."
 * Ela cria um arquivo tempo na pasta appdata/cadastrofutebol/temp e depois
 * copia para o diretório que usuário pediu com o nome digitado.
 */
void MainWindow::on_actionFazer_Backup_triggered()
{
    //Para achar o diretório do programa que faz o backup:

    QSqlQuery query;

    if(!query.exec("SHOW data_directory"))
    {
        QMessageBox::critical(0,"Erro!", query.lastError().text());
        return;
    }

    query.next();

    QString path;
    path = query.value(0).toString();
    path = path.mid(0,path.size()-5);
    path.append("/bin/pg_dump.exe");
    path = "\"" + path + "\"";

    //Para pegar o diretório em que o backup será salvo:

    QString filters("Arquivos de texto (*.txt);;All files (*.*)");
    QString defaultFilter("Arquivos de texto (*.txt)");

    path.append(" -U postgres cadastrofutebol > %localappdata%/cadastrofutebol/temp/backup.txt");
    QString file = QFileDialog::getSaveFileName(0, "Salvar arquivo", QDir::currentPath(), filters, &defaultFilter, QFileDialog::DontUseNativeDialog);

    if(!file.isEmpty())
    {
        file.append(".txt");

        system(path.toStdString().c_str());

        QFile arquivo;
        QString temporaryfile = getenv("LOCALAPPDATA");
        temporaryfile.append("/cadastrofutebol/temp/backup.txt");
        if(QFile::exists(temporaryfile))
        {
            if(arquivo.copy(temporaryfile, file))
            {
                if(!QFile::remove(temporaryfile))
                {
                    QMessageBox::critical(0,"Error!", "Não foi possível remover o arquivo temporário criado ao fazer o backup!");
                    return;
                }
            }
            else
            {
                QMessageBox::critical(0, "Erro!", "Não foi possível gerar o arquivo de backup a partir do arquivo temporário!");
                return;
            }
        }
        else
        {
            QMessageBox::critical(0, "Erro!", "Não foi possível criar arquivo de backup!");
            return;
        }
    }
}

void MainWindow::on_actionCarregar_arquivo_de_Backup_triggered()
{
    QSqlQuery query;

    //Para pegar o caminho do programa que faz a restauração do banco:
    if(!query.exec("SHOW data_directory"))
    {
        QMessageBox::critical(0,"Erro!", query.lastError().text());
        return;
    }

    query.next();

    QString path;
    path = query.value(0).toString();
    path = path.mid(0,path.size()-5);
    path.append("/bin/psql.exe");
    path = "\"" + path + "\"";



    //Para pegar o caminho do arquivo de backup:
    QString filters("Arquivos de texto (*.txt);;All files (*.*)");
    QString defaultFilter("Arquivos de texto (*.txt)");

    path.append(" -U postgres cadastrofutebol < %localappdata%/cadastrofutebol/temp/backup.txt");
    QString file = QFileDialog::getOpenFileName(0, "Save file", QDir::currentPath(), filters, &defaultFilter, QFileDialog::DontUseNativeDialog);

    //Para pegar o caminho do arquivo temporário que ainda será criado na pasta temp do localappdata:
    QString tempPath = getenv("LOCALAPPDATA");
    tempPath.append("/cadastrofutebol/temp/backup.txt");

    if(!file.isEmpty())
    {
        //Para copiar o arquivo de backup para a pasta temporária:
        QFile arquivo;
        if(QFile::exists(file))
        {
            if(!arquivo.copy(file, tempPath))
            {
                QMessageBox::critical(0, "Erro!", arquivo.errorString());
                return;
            }
        }
        else
        {
            QMessageBox::critical(0, "Erro!", "Não foi possível encontrar o arquivo " + file);
            return;
        }

        //Para apagar os itens do banco de dados:
        if(!query.exec("DELETE FROM arbitro WHERE codarbitro > 0"))
        {
            QMessageBox::critical(0, "Erro!", query.lastError().text());
            return;
        }
        if(!query.exec("DELETE FROM temporada WHERE codtemporada > 0"))
        {
            QMessageBox::critical(0, "Erro!", query.lastError().text());
            return;
        }
        if(!query.exec("DELETE FROM campeonato WHERE codcampeonato > 0"))
        {
            QMessageBox::critical(0, "Erro!", query.lastError().text());
            return;
        }
        if(!query.exec("DELETE FROM estadio WHERE codestadio > 0"))
        {
            QMessageBox::critical(0, "Erro!", query.lastError().text());
            return;
        }
        if(!query.exec("DELETE FROM classificacao WHERE codclassificacao > 0"))
        {
            QMessageBox::critical(0, "Erro!", query.lastError().text());
            return;
        }
        if(!query.exec("DELETE FROM equipe WHERE codequipe > 0"))
        {
            QMessageBox::critical(0, "Erro!", query.lastError().text());
            return;
        }
        if(!query.exec("DELETE FROM equipecompetetemporada WHERE codequipe > 0"))
        {
            QMessageBox::critical(0, "Erro!", query.lastError().text());
            return;
        }
        if(!query.exec("DELETE FROM escalacaojogo WHERE codjogo > 0"))
        {
            QMessageBox::critical(0, "Erro!", query.lastError().text());
            return;
        }
        if(!query.exec("DELETE FROM estruturatemporada WHERE codestruturatemporada > 0"))
        {
            QMessageBox::critical(0, "Erro!", query.lastError().text());
            return;
        }
        if(!query.exec("DELETE FROM gerador WHERE oid > 0"))
        {
            QMessageBox::critical(0, "Erro!", query.lastError().text());
            return;
        }
        if(!query.exec("DELETE FROM jogador WHERE codjogador > 0"))
        {
            QMessageBox::critical(0, "Erro!", query.lastError().text());
            return;
        }
        if(!query.exec("DELETE FROM jogo WHERE codjogo > 0"))
        {
            QMessageBox::critical(0, "Erro!", query.lastError().text());
            return;
        }
        if(!query.exec("DELETE FROM lancepartida WHERE codlancepartida > 0"))
        {
            QMessageBox::critical(0, "Erro!", query.lastError().text());
            return;
        }
        if(!query.exec("DELETE FROM narracao WHERE codnarracao > 0"))
        {
            QMessageBox::critical(0, "Erro!", query.lastError().text());
            return;
        }
        if(!query.exec("DELETE FROM punicao WHERE codpunicao > 0"))
        {
            QMessageBox::critical(0, "Erro!", query.lastError().text());
            return;
        }

        //Para fazer a restauração propriamente dita:
        system(path.toStdString().c_str());

        //Para remover o arquivo temporário criado na pasta temp:
        if(!QFile::remove(tempPath))
        {
            QMessageBox::critical(0,"Error!", "Não foi possível remover o arquivo temporário criado ao fazer o backup!");
            return;
        }

        //Para atualizar a tabela do mainWindow com as novas informações:
        atualizar();
    }
}

/*void MainWindow::on_actionCarregar_arquivo_de_Backup_triggered()
{
    QSqlQuery query;

    if(!query.exec("SHOW data_directory"))
    {
        QMessageBox::critical(0,"Erro!", query.lastError().text());
    }

    query.next();

    QString path;
    path = query.value(0).toString();
    path = path.mid(0,path.size()-5);
    path.append("/bin/psql.exe");

    QString filters("Arquivos de texto (*.txt);;All files (*.*)");
    QString defaultFilter("Arquivos de texto (*.txt)");

    path.append(" -U postgres cadastrofutebol < ");
    QString file = QFileDialog::getOpenFileName(0, "Save file", QDir::currentPath(), filters, &defaultFilter, QFileDialog::DontUseNativeDialog);

    if(!file.isEmpty())
    {
        path.append("\"" + file + "\"");

        cout << path.toStdString() << endl;

        db->close();
        db = new Conexao("localhost", "postgres", "postgres", senha);

        QSqlQuery query;
        if(!query.exec("SELECT pg_terminate_backend(pg_stat_activity.pid) FROM pg_stat_activity WHERE pg_stat_activity.datname = 'cadastrofutebol' AND pid <> pg_backend_pid();"))
        {
            QMessageBox::critical(0, "Erro!", query.lastError().text());
            return;
        }
        if(!query.exec("DROP DATABASE cadastrofutebol"))
        {
            QMessageBox::critical(0, "Erro!", query.lastError().text());
            return;
        }
        if(!query.exec("CREATE DATABASE cadastrofutebol"))
        {
            QMessageBox::critical(0, "Erro!", query.lastError().text());
            return;
        }

        db->close();
        db = new Conexao("localhost", "cadastrofutebol", "postgres", senha);

        system(path.toStdString().c_str());
    }

    atualizar();
}*/

void MainWindow::on_actionSobre_o_Cadastro_do_Futebol_triggered()
{
    QMessageBox::information(0, "Sobre o Cadastro do Futebol...", "Criado por Gabriel Rocha de Oliveira\nTestado por Ingo Frana Kunz");
}

/**
 * @brief MainWindow::showSelectedItemInformations
 * Esta função é ativada quando um determinado item é selecionado, em qualquer aba.
 */
void MainWindow::showSelectedItemInformations()
{
    QString selectedId;
    QSqlQuery query;

    //Campeonato:
    if(ui->campTableWidget->selectedItems().size() == 0)
    {
        ui->campNomeLabel->setText("<html><head/><body><p align=\"right\">-</p></body></html>");
        ui->campTipoLabel->setText("<html><head/><body><p align=\"right\">-</p></body></html>");
        ui->campPaisLabel->setText("<html><head/><body><p align=\"right\">-</p></body></html>");
        ui->campImageLabel->clear();
    }
    else
    {
        selectedId = ui->campTableWidget->selectedItems().first()->text();

        if(!query.exec("SELECT campeonato.nome, tipocampeonato.nometipocampeonato, campeonato.pais, campeonato.escudo FROM tipocampeonato INNER JOIN campeonato ON (tipocampeonato.codtipocampeonato = campeonato.codtipocampeonato) WHERE codcampeonato = '" + selectedId + "'"))
        {
            QMessageBox::critical(0, "Erro!", query.lastError().text());
            return;
        }

        query.next();

        if(!query.value(0).isNull() && !query.value(1).isNull() && !query.value(2).isNull())
        {
            ui->campNomeLabel->setText("<html><head/><body><p align=\"right\">" + query.value(0).toString() + "</p></body></html>");
            ui->campTipoLabel->setText("<html><head/><body><p align=\"right\">" + query.value(1).toString() + "</p></body></html>");
            ui->campPaisLabel->setText("<html><head/><body><p align=\"right\">" + query.value(2).toString() + "</p></body></html>");

            if(query.value(3).toString().size() > 0)
            {
                QString path = getenv("LOCALAPPDATA");
                path.append("/cadastrofutebol/imagens/campeonato/" + query.value(3).toString());

                QPixmap pixmap(path);
                ui->campImageLabel->setPixmap(pixmap.scaled(200, 200));
            }
            else
            {
                ui->campImageLabel->clear();
            }
        }
    }

    //Temporada:

    if(ui->tempTableWidget->selectedItems().size() == 0)
    {
        /*ui->tempCampeonatoRelacionado->setText("<html><head/><body><p align=\"right\"><b>-</b></p></body></html>");
        ui->tempNomeLabel->setText("<html><head/><body><p align=\"right\">-</p></body></html>");
        ui->tempPontosVitoriaLabel->setText("<html><head/><body><p align=\"right\">-</p></body></html>");
        ui->tempPontosEmpateLabel->setText("<html><head/><body><p align=\"right\">-</p></body></html>");
        ui->tempPontosVitoriaProrrogacaoLabel->setText("<html><head/><body><p align=\"right\">-</p></body></html>");
        ui->tempPontosVitoriaPenaltisLabel->setText("<html><head/><body><p align=\"right\">-</p></body></html>");
        ui->tempPontosDerrotaProrrogacaoLabel->setText("<html><head/><body><p align=\"right\">-</p></body></html>");
        ui->tempPontosDerrotaPenaltisLabel->setText("<html><head/><body><p align=\"right\">-</p></body></html>");
        ui->tempDescricaoLabel->setText("<html><head/><body><p align=\"justify\">-</p></body></html>");
        ui->tempNumeroTimesRebaixados->setText("<html><head/><body><p align=\"right\">-</p></body></html>");
        ui->tempNumeroTimesPromovidos->setText("<html><head/><body><p align=\"right\">-</p></body></html>");
        ui->tempPontosEmpateProrrogacaoLabel->setText("<html><head/><body><p align=\"right\">-</p></body></html>");
        ui->tempCriteriosDesempateLabel->setText("<html><head/><body><p align=\"justify\">-</p></body></html>");
        ui->tempNumTimesCompet1Label->setText("<html><head/><body><p align=\"right\">-</p></body></html>");
        ui->tempNumTimesCompet2Label->setText("<html><head/><body><p align=\"right\">-</p></body></html>");
        ui->tempNumeroTimesPorRebaixamentoLabel->setText("<html><head/><body><p align=\"right\">-</p></body></html>");*/
        while(ui->equipesParticipantesTableWidget->rowCount() > 0)
        {
            ui->equipesParticipantesTableWidget->removeRow(0);
        }
    }
    else
    {
        selectedId = ui->tempTableWidget->selectedItems().first()->text();

        if(!query.exec("SELECT campeonato.nome, temporada.nometemporada, temporada.pontosvitoria, temporada.pontosempate, temporada.pontosvitoriaprorrogacao, temporada.pontosvitoriapenaltis, temporada.pontosderrotaprorrogacao, temporada.pontosderrotapenaltis, temporada.descricao, temporada.numtimerebaixado, temporada.numtimepromovido, temporada.pontosempateprorrogacao, temporada.sqldesempate, temporada.numtimecompet1, temporada.numtimecompet2, temporada.numtimeporrebaixamento FROM campeonato INNER JOIN temporada ON (temporada.codcampeonato = campeonato.codcampeonato) WHERE codtemporada = '" + selectedId + "'"))
        {
            QMessageBox::critical(0, "Erro!", query.lastError().text());
            return;
        }

        query.next();

        if(!query.value(0).isNull() && !query.value(1).isNull() && !query.value(2).isNull() && !query.value(3).isNull() && !query.value(4).isNull() && !query.value(5).isNull() && !query.value(6).isNull() && !query.value(7).isNull() && !query.value(8).isNull() && !query.value(9).isNull() && !query.value(10).isNull() && !query.value(11).isNull() && !query.value(12).isNull() && !query.value(13).isNull() && !query.value(14).isNull() && !query.value(15).isNull())
        {
            /*ui->tempCampeonatoRelacionado->setText("<html><head/><body><p align=\"right\"><b>" + query.value(0).toString() + "</b></p></body></html>");
            ui->tempNomeLabel->setText("<html><head/><body><p align=\"right\">" + query.value(1).toString() + "</p></body></html>");
            ui->tempPontosVitoriaLabel->setText("<html><head/><body><p align=\"right\">" + query.value(2).toString() + "</p></body></html>");
            ui->tempPontosEmpateLabel->setText("<html><head/><body><p align=\"right\">" + query.value(3).toString() + "</p></body></html>");
            ui->tempPontosVitoriaProrrogacaoLabel->setText("<html><head/><body><p align=\"right\">" + query.value(4).toString() + "</p></body></html>");
            ui->tempPontosVitoriaPenaltisLabel->setText("<html><head/><body><p align=\"right\">" + query.value(5).toString() + "</p></body></html>");
            ui->tempPontosDerrotaProrrogacaoLabel->setText("<html><head/><body><p align=\"right\">" + query.value(6).toString() + "</p></body></html>");
            ui->tempPontosDerrotaPenaltisLabel->setText("<html><head/><body><p align=\"right\">" + query.value(7).toString() + "</p></body></html>");
            ui->tempDescricaoLabel->setText("<html><head/><body><p align=\"justify\">" + query.value(8).toString() + "</p></body></html>");
            ui->tempNumeroTimesRebaixados->setText("<html><head/><body><p align=\"right\">" + query.value(9).toString() + "</p></body></html>");
            ui->tempNumeroTimesPromovidos->setText("<html><head/><body><p align=\"right\">" + query.value(10).toString() + "</p></body></html>");
            ui->tempPontosEmpateProrrogacaoLabel->setText("<html><head/><body><p align=\"right\">" + query.value(11).toString() + "</p></body></html>");
            ui->tempCriteriosDesempateLabel->setText("<html><head/><body><p align=\"justify\">" + query.value(12).toString() + "</p></body></html>");
            ui->tempNumTimesCompet1Label->setText("<html><head/><body><p align=\"right\">" + query.value(13).toString() + "</p></body></html>");
            ui->tempNumTimesCompet2Label->setText("<html><head/><body><p align=\"right\">" + query.value(14).toString() + "</p></body></html>");
            ui->tempNumeroTimesPorRebaixamentoLabel->setText("<html><head/><body><p align=\"right\">" + query.value(15).toString() + "</p></body></html>");*/
        }
        while(ui->equipesParticipantesTableWidget->rowCount() > 0)
        {
            ui->equipesParticipantesTableWidget->removeRow(0);
        }
        if(!query.exec("SELECT equipe.codequipe, equipe.nomeequipe, equipe.tipoequipe FROM equipe LEFT JOIN equipecompetetemporada ON (equipe.codequipe = equipecompetetemporada.codequipe) WHERE equipecompetetemporada.codtemporada = " + selectedId))
        {
            QMessageBox::critical(0, "Erro!", query.lastError().text());
            return;
        }
        while(query.next())
        {
            ui->equipesParticipantesTableWidget->insertRow(0);
            ui->equipesParticipantesTableWidget->setItem(0, 0, new QTableWidgetItem(query.value(0).toString()));
            ui->equipesParticipantesTableWidget->setItem(0, 1, new QTableWidgetItem(query.value(1).toString()));
            ui->equipesParticipantesTableWidget->setItem(0, 2, new QTableWidgetItem(query.value(2).toString()));
        }
    }

    //Estadios:
    if(ui->estTableWidget->selectedItems().size() == 0)
    {
        ui->EstNomeLabel->setText("<html><head/><body><p align=\"right\"><b>-</b></p></body></html>");
        ui->EstNomeOficialLabel->setText("<html><head/><body><p align=\"right\"><b>-</b></p></body></html>");
        ui->EstCapacidadeLabel->setText("<html><head/><body><p align=\"right\"><b>-</b></p></body></html>");
        ui->EstCidadeLabel->setText("<html><head/><body><p align=\"right\"><b>-</b></p></body></html>");
        ui->EstPixmapLabel->clear();
        ui->EstPaisLabel->setText("<html><head/><body><p align=\"right\"><b>-</b></p></body></html>");
    }
    else
    {
        selectedId = ui->estTableWidget->selectedItems().first()->text();

        if(!query.exec("SELECT * FROM estadio WHERE codestadio = " + selectedId))
        {
            QMessageBox::critical(0, "Erro!", query.lastError().text());
            return;
        }

        query.next();

        ui->EstNomeLabel->setText("<html><head/><body><p align=\"right\">" + query.value(1).toString() + "</p></body></html>");
        ui->EstNomeOficialLabel->setText("<html><head/><body><p align=\"right\">" + query.value(2).toString() + "</p></body></html>");
        ui->EstCapacidadeLabel->setText("<html><head/><body><p align=\"right\">" + query.value(3).toString() + "</p></body></html>");
        ui->EstCidadeLabel->setText("<html><head/><body><p align=\"right\">" + query.value(4).toString() + "</p></body></html>");
        if(query.value(5).toString().size() > 0)
        {
            QString path;
            path = getenv("LOCALAPPDATA");
            path.append("\\cadastrofutebol\\imagens\\estadio\\" + query.value(5).toString());

            QPixmap pixmap;
            pixmap.load(path);
            ui->EstPixmapLabel->setPixmap(pixmap.scaled(200,200));
        }
        else
        {
            ui->EstPixmapLabel->clear();
        }
        ui->EstPaisLabel->setText("<html><head/><body><p align=\"right\">" + query.value(6).toString() + "</p></body></html>");
    }

    //Árbitro:
    if(ui->arbTableWidget->selectedItems().size() == 0)
    {
        ui->arbTemporadaRelacionada->setText("<html><head/><body><p align=\"right\"><b>-</b></p></body></html>");
        ui->arbNomeArbitro->setText("<html><head/><body><p align=\"right\"><b>-</b></p></body></html>");
        ui->arbDataNascimento->setText("<html><head/><body><p align=\"right\"><b>-</b></p></body></html>");
        ui->ArbPixmap->clear();
    }
    else
    {
        selectedId = ui->arbTableWidget->selectedItems().first()->text();

        if(!query.exec("SELECT arbitro.codarbitro, temporada.nometemporada, arbitro.nomearbitro, arbitro.datanascimento, arbitro.foto FROM temporada INNER JOIN arbitro ON (temporada.codtemporada = arbitro.codtemporada) WHERE codarbitro = " + selectedId))
        {
            QMessageBox::critical(0, "Erro!", query.lastError().text());
            return;
        }
        query.next();
        ui->arbTemporadaRelacionada->setText("<html><head/><body><p align=\"right\"><b>" + query.value(1).toString() + "</b></p></body></html>");
        ui->arbNomeArbitro->setText("<html><head/><body><p align=\"right\">" + query.value(2).toString() + "</p></body></html>");
        ui->arbDataNascimento->setText("<html><head/><body><p align=\"right\">" + query.value(3).toString() + "</p></body></html>");

        if(!query.value(4).toString().isEmpty())
        {
            QString path = getenv("LOCALAPPDATA");
            path.append("\\cadastrofutebol\\imagens\\arbitro\\" + query.value(4).toString());
            QPixmap temp;
            temp.load(path);
            ui->ArbPixmap->setPixmap(temp.scaled(200, 200));
        }
        else
        {
            ui->ArbPixmap->clear();
        }
    }

    //Equipe:
    if(ui->equTableWidget->selectedItems().size() == 0)
    {
        ui->equNome->setText("<html><head/><body><p align=\"right\"><b>-</b></p></body></html>");
        ui->equNomeCompleto->setText("<html><head/><body><p align=\"right\"><b>-</b></p></body></html>");
        ui->equDataFundacao->setText("<html><head/><body><p align=\"right\"><b>-</b></p></body></html>");
        ui->equCidade->setText("<html><head/><body><p align=\"right\"><b>-</b></p></body></html>");
        ui->equPais->setText("<html><head/><body><p align=\"right\"><b>-</b></p></body></html>");
        ui->equTipo->setText("<html><head/><body><p align=\"right\"><b>-</b></p></body></html>");
        ui->equTipo_2->setText("<html><head/><body><p align=\"right\"><b>-</b></p></body></html>");
        ui->equPixmap->clear();
    }
    else
    {
        selectedId = ui->equTableWidget->selectedItems().first()->text();

        if(!query.exec("SELECT equipe.codequipe, equipe.nomeequipe, equipe.nomecompletoequipe, equipe.datafundacao, equipe.cidade, equipe.pais, tipoequipe.nometipoequipe, equipe.escudo, estadio.nomeestadio FROM equipe LEFT JOIN estadio ON equipe.codestadio = estadio.codestadio INNER JOIN tipoequipe ON equipe.tipoequipe = tipoequipe.codtipoequipe WHERE equipe.codequipe = " + selectedId))
        {
            QMessageBox::critical(0, "Erro!", query.lastError().text());
            return;
        }

        query.next();

        ui->equNome->setText("<html><head/><body><p align=\"right\">" + query.value(1).toString() + "</p></body></html>");
        ui->equNomeCompleto->setText("<html><head/><body><p align=\"right\">" + query.value(2).toString() + "</p></body></html>");
        ui->equDataFundacao->setText("<html><head/><body><p align=\"right\">" + query.value(3).toString() + "</p></body></html>");
        ui->equCidade->setText("<html><head/><body><p align=\"right\">" + query.value(4).toString() + "</p></body></html>");
        ui->equPais->setText("<html><head/><body><p align=\"right\">" + query.value(5).toString() + "</p></body></html>");
        ui->equTipo->setText("<html><head/><body><p align=\"right\">" + query.value(6).toString() + "</p></body></html>");
        ui->equTipo_2->setText("<html><head/><body><p align=\"right\"><b>" + query.value(8).toString() + "</b></p></body></html>");

        if(!query.value(7).toString().isEmpty())
        {
            QString path = getenv("LOCALAPPDATA");
            path.append("\\cadastrofutebol\\imagens\\equipe\\" + query.value(7).toString());
            QPixmap temp;
            temp.load(path);
            ui->equPixmap->setPixmap(temp.scaled(200, 200));
        }
        else
        {
            ui->equPixmap->clear();
        }
    }

    //Jogador:
    if(ui->jogTableWidget->selectedItems().size() == 0)
    {
        ui->jogEquipeRelacionada->setText("<html><head/><body><p align=\"right\"><b>-</b></p></body></html>");
        ui->jogTemporadaRelacionada->setText("<html><head/><body><p align=\"right\"><b>-</b></p></body></html>");
        ui->jogApelido->setText("<html><head/><body><p align=\"right\"><b>-</b></p></body></html>");
        ui->jogNome->setText("<html><head/><body><p align=\"right\"><b>-</b></p></body></html>");
        ui->jogNumeroCamisa->setText("<html><head/><body><p align=\"right\"><b>-</b></p></body></html>");
        ui->jogDataNascimento->setText("<html><head/><body><p align=\"right\"><b>-</b></p></body></html>");
        ui->jogNacionalidade->setText("<html><head/><body><p align=\"right\"><b>-</b></p></body></html>");
        ui->jogPosicao->setText("<html><head/><body><p align=\"right\"><b>-</b></p></body></html>");
        ui->jogStatus->setText("<html><head/><body><p align=\"right\"><b>-</b></p></body></html>");
        ui->jogEmail->setText("<html><head/><body><p align=\"right\"><b>-</b></p></body></html>");
        ui->jogPixmap->clear();
    }
    else
    {
        selectedId = ui->jogTableWidget->selectedItems().first()->text();

        if(!query.exec("SELECT jogador.codjogador, equipe.nomeequipe, temporada.nometemporada, jogador.apelidojogador, jogador.nomejogador, jogador.numerocamisa, jogador.datanascimento, jogador.nacionalidade, jogador.posicao, jogador.status, jogador.email, jogador.foto FROM jogador LEFT JOIN equipe ON equipe.codequipe = jogador.codequipe LEFT JOIN temporada ON temporada.codtemporada = jogador.codtemporada WHERE jogador.codjogador = " + selectedId))
        {
            QMessageBox::critical(0, "Erro!", query.lastError().text());
            return;
        }

        query.next();

        ui->jogEquipeRelacionada->setText("<html><head/><body><p align=\"right\">" + query.value(1).toString() + "</p></body></html>");
        ui->jogTemporadaRelacionada->setText("<html><head/><body><p align=\"right\">" + query.value(2).toString() + "</p></body></html>");
        ui->jogApelido->setText("<html><head/><body><p align=\"right\">" + query.value(3).toString() + "</p></body></html>");
        ui->jogNome->setText("<html><head/><body><p align=\"right\">" + query.value(4).toString() + "</p></body></html>");
        ui->jogNumeroCamisa->setText("<html><head/><body><p align=\"right\">" + query.value(5).toString() + "</p></body></html>");
        ui->jogDataNascimento->setText("<html><head/><body><p align=\"right\">" + query.value(6).toString() + "</p></body></html>");
        ui->jogNacionalidade->setText("<html><head/><body><p align=\"right\">" + query.value(7).toString() + "</p></body></html>");
        ui->jogPosicao->setText("<html><head/><body><p align=\"right\">" + query.value(8).toString() + "</p></body></html>");
        ui->jogStatus->setText("<html><head/><body><p align=\"right\">" + query.value(9).toString() + "</p></body></html>");
        ui->jogEmail->setText("<html><head/><body><p align=\"right\">" + query.value(10).toString() + "</p></body></html>");

        if(!query.value(11).toString().isEmpty())
        {
            QString path = getenv("LOCALAPPDATA");
            path.append("\\cadastrofutebol\\imagens\\jogador\\" + query.value(11).toString());
            QPixmap temp;
            temp.load(path);
            ui->jogPixmap->setPixmap(temp.scaled(200, 200));
        }
        else
        {
            ui->jogPixmap->clear();
        }
    }
}

/**
 * @brief MainWindow::activateWidgetsUpdates
 * Esta função faz a ligação para permitir que os botões de Editar e Excluir sejam ativados na hora que um item
 * do TableWidget estiver selecionado. Também faz a ligação para que as informações da tela sejam atualizadas
 * com as informações do item selecionado.
 */
void MainWindow::activateWidgetsUpdates()
{
    //Campeonato:
    connect(ui->campTableWidget, SIGNAL(itemSelectionChanged()), this, SLOT(isSelected()));
    connect(ui->campTableWidget, SIGNAL(itemSelectionChanged()), this, SLOT(showSelectedItemInformations()));

    //Temporada:
    connect(ui->tempTableWidget, SIGNAL(itemSelectionChanged()), this, SLOT(isSelected()));
    connect(ui->tempTableWidget, SIGNAL(itemSelectionChanged()), this, SLOT(showSelectedItemInformations()));

    //Estádio:
    connect(ui->estTableWidget, SIGNAL(itemSelectionChanged()), this, SLOT(isSelected()));
    connect(ui->estTableWidget, SIGNAL(itemSelectionChanged()), this, SLOT(showSelectedItemInformations()));

    //Árbitro:
    connect(ui->arbTableWidget, SIGNAL(itemSelectionChanged()), this, SLOT(isSelected()));
    connect(ui->arbTableWidget, SIGNAL(itemSelectionChanged()), this, SLOT(showSelectedItemInformations()));

    //Equipe:
    connect(ui->equTableWidget, SIGNAL(itemSelectionChanged()), this, SLOT(isSelected()));
    connect(ui->equTableWidget, SIGNAL(itemSelectionChanged()), this, SLOT(showSelectedItemInformations()));

    //Jogador:
    connect(ui->jogTableWidget, SIGNAL(itemSelectionChanged()), this, SLOT(isSelected()));
    connect(ui->jogTableWidget, SIGNAL(itemSelectionChanged()), this, SLOT(showSelectedItemInformations()));
}

void MainWindow::on_tempNovo_clicked()
{
    temp = new cadastroTemporada();
    connect(temp, SIGNAL(destroyed()), this, SLOT(atualizar()));
    temp->show();
}

void MainWindow::resizeTableWidgets()
{
    //campeonato:
    ui->campTableWidget->resizeColumnToContents(0);
    ui->campTableWidget->setColumnWidth(1,240);

    //Temporadas:
    ui->tempTableWidget->resizeColumnToContents(0);
    ui->tempTableWidget->setColumnWidth(1,240);

    //Estádios:
    ui->estTableWidget->resizeColumnToContents(0);
    ui->estTableWidget->setColumnWidth(1, 240);

    //Árbitros:
    ui->arbTableWidget->resizeColumnToContents(0);
    ui->arbTableWidget->setColumnWidth(1, 240);

    //Equipe:
    ui->equTableWidget->resizeColumnToContents(0);
    ui->equTableWidget->setColumnWidth(1, 240);

    //Jogador:
    ui->jogTableWidget->resizeColumnToContents(0);
    ui->jogTableWidget->setColumnWidth(1, 240);
}

QString MainWindow::dicioJogPosicao(int num)
{
    switch(num)
    {
        case 0:
            return "Zagueiro";
            break;
        case 1:
            return "Lateral";
            break;
        case 2:
            return "Líbero";
            break;
        case 3:
            return "Volante";
            break;
        case 4:
            return "Ala";
            break;
        case 5:
            return "Apoiador";
            break;
        case 6:
            return "Médio Centro";
            break;
        case 7:
            return "Ponta";
            break;
        case 8:
            return "Segundo Atacante";
            break;
        case 9:
            return "Centro Avante";
            break;
        case 10:
            return "Goleiro";
            break;
    }

    return "ERROR";
}

void MainWindow::changeFrameStyle()
{
    ui->CampScrollArea->setFrameShape(QFrame::NoFrame);
    ui->EstadioScrollArea->setFrameShape(QFrame::NoFrame);
    ui->ArbitroScrollArea->setFrameShape(QFrame::NoFrame);
    ui->EquipesScrollArea->setFrameShape(QFrame::NoFrame);
    ui->JogadoresScrollArea->setFrameShape(QFrame::NoFrame);
}

bool MainWindow::doesFileExist(const wchar_t *filename)
{
    return GetFileAttributes((LPCWSTR)filename) != INVALID_FILE_ATTRIBUTES;
}

bool MainWindow::create_pgpassconf()
{
    QString path;

    //Verifica o diretório primeiro, caso não exista, ele cria o diretório "postgresql" na pasta Roaming de APPDATA:
    path = getenv("APPDATA");
    path = path + "\\postgresql";

    if(!doesFileExist(path.toStdWString().c_str()))
    {
        if(!CreateDirectory(path.toStdWString().c_str(), NULL))
        {
            cout << "Não conseguiu criar a pasta!" << endl;
            return false;
        }
    }

    //Verifica se o arquivo existe:
    path = path + "\\pgpass.conf";

    if(!doesFileExist(path.toStdWString().c_str()))
    {
        ofstream file(path.toStdString().c_str());

        if(!doesFileExist(path.toStdWString().c_str()))
        {
            QMessageBox::critical(0, "Erro!", "Não foi possível criar o arquivo. Favor executar novamente este programa em modo de administrador.");
            QMessageBox::critical(0, "Erro!", "Para executar este programa em modo administrador, clique com o botão direito em cima dele, e selecione a opção: \"Executar em modo de Administrador\".\n");
            return false;
        }
        else
        {
            QMessageBox::information(0, "Concluído!", "pg_pass.conf não encontrado. Arquivo criado com sucesso.");
            return true;
        }
    }

    return true;
}

void MainWindow::on_tempEditar_clicked()
{
    QString sCode = ui->tempTableWidget->selectedItems().first()->text();
    QSqlQuery query;
    if(!query.exec("SELECT "
                   "codtemporada, "
                   "campeonato.nome, "
                   "nometemporada, "
                   "pontosvitoria, "
                   "pontosempate, "
                   "pontosvitoriaprorrogacao, "
                   "pontosvitoriapenaltis, "
                   "pontosderrotaprorrogacao, "
                   "pontosderrotapenaltis, "
                   "descricao, "
                   "numtimerebaixado, "
                   "numtimepromovido, "
                   "pontosempateprorrogacao, "
                   "sqldesempate, "
                   "numtimecompet1, "
                   "numtimecompet2, "
                   "numtimeporrebaixamento "
                   "FROM campeonato INNER JOIN temporada ON (temporada.codcampeonato = campeonato.codcampeonato) WHERE codtemporada = " + sCode ))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
        return;
    }
    query.next();
    temp = new cadastroTemporada(query.value(0).toString(), query.value(1).toString(), query.value(2).toString(), query.value(3).toString(), query.value(4).toString(), query.value(5).toString(), query.value(6).toString(), query.value(7).toString(), query.value(8).toString(), query.value(9).toString(), query.value(10).toString(), query.value(11).toString(), query.value(12).toString(), query.value(13).toString(), query.value(14).toString(), query.value(15).toString(), query.value(16).toString());
    connect(temp, SIGNAL(destroyed()), this, SLOT(atualizar()));
    temp->show();
}

/**
 * @brief MainWindow::on_tempExcluir_clicked
 * Esta função é executada quando é pressionado o botão "Excluir" da aba de Temporadas.
 */
void MainWindow::on_tempExcluir_clicked()
{
    if(QMessageBox::Yes == QMessageBox(QMessageBox::Information,"Atenção!","Deseja realmente excluir o campeonato selecionado? Esta operação não poderá ser desfeita.", QMessageBox::Yes | QMessageBox::No).exec())
    {
        QString item = ui->tempTableWidget->selectedItems().first()->text();

        QSqlQuery query;
        if(!query.exec("DELETE FROM temporada WHERE codtemporada = " + item))
        {
            QMessageBox::critical(0, "Erro!", query.lastError().text());
            return;
        }

        this->atualizar();
    }
}

void MainWindow::on_estNovo_clicked()
{
    est = new cadastroEstadio();
    connect(est, SIGNAL(destroyed()), this, SLOT(atualizar()));
    est->show();
}

void MainWindow::on_estEditar_clicked()
{
    QSqlQuery query;
    QString editCode = ui->estTableWidget->selectedItems().first()->text();

    if(!query.exec("SELECT * FROM estadio WHERE codestadio = " + editCode))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
        return;
    }
    else
    {
        query.next();
        if(query.value(5).toString().isEmpty())
        {
            est = new cadastroEstadio(query.value(0).toString(), query.value(1).toString(), query.value(2).toString(), query.value(3).toString(), query.value(4).toString(), NULL, query.value(6).toString());
            connect(est, SIGNAL(destroyed()), this, SLOT(atualizar()));
            est->show();
        }
        else
        {
            QString path = getenv("LOCALAPPDATA");
            path.append("\\cadastrofutebol\\imagens\\estadio\\" + query.value(5).toString());
            QPixmap *pixmap = new QPixmap;
            pixmap->load(path);
            est = new cadastroEstadio(query.value(0).toString(), query.value(1).toString(), query.value(2).toString(), query.value(3).toString(), query.value(4).toString(), pixmap, query.value(6).toString());
            connect(est, SIGNAL(destroyed()), this, SLOT(atualizar()));
            est->show();
        }
    }
}

void MainWindow::on_estExcluir_clicked()
{
    if(QMessageBox::No == QMessageBox(QMessageBox::Information,"Atenção!","Deseja realmente excluir o estádio selecionado? Esta operação não poderá ser desfeita.", QMessageBox::Yes | QMessageBox::No).exec())
    {
        return;
    }

    QString id = ui->estTableWidget->selectedItems().first()->text();

    QSqlQuery query;
    if(!query.exec("DELETE FROM estadio WHERE codestadio = " + id + "RETURNING foto"))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
        return;
    }

    if(query.next())
    {
        if(!query.value(0).toString().isEmpty())
        {
            QString path = getenv("LOCALAPPDATA");
            path.append("\\cadastrofutebol\\imagens\\estadio\\" + query.value(0).toString());

            QFile file;
            if(!file.remove(path))
            {
                QMessageBox::critical(0, "Erro!", file.errorString());
                return;
            }
        }
    }

    atualizar();
}

void MainWindow::on_arbNovo_clicked()
{
    arb = new cadastroArbitro();
    connect(arb, SIGNAL(destroyed()), this, SLOT(atualizar()));
    arb->show();
}

void MainWindow::on_arbEditar_clicked()
{
    QSqlQuery query;
    QString editCode = ui->arbTableWidget->selectedItems().first()->text();

    if(!query.exec("SELECT arbitro.codarbitro, temporada.nometemporada, arbitro.nomearbitro, arbitro.datanascimento, arbitro.foto FROM temporada INNER JOIN arbitro ON (temporada.codtemporada = arbitro.codtemporada) WHERE codarbitro = " + editCode))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
        return;
    }
    else
    {
        query.next();
        arb = new cadastroArbitro(query.value(0).toString(), query.value(1).toString(), query.value(2).toString(), query.value(3).toString(), query.value(4).toString());
        connect(arb, SIGNAL(destroyed()), this, SLOT(atualizar()));
        arb->show();
    }
}

void MainWindow::on_arbExcluir_clicked()
{
    if(QMessageBox::No == QMessageBox(QMessageBox::Information,"Atenção!","Deseja realmente excluir o árbitro selecionado? Esta operação não poderá ser desfeita.", QMessageBox::Yes | QMessageBox::No).exec())
    {
        return;
    }

    QString id = ui->arbTableWidget->selectedItems().first()->text();

    QSqlQuery query;
    if(!query.exec("DELETE FROM arbitro WHERE codarbitro = " + id + "RETURNING foto"))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
        return;
    }

    if(query.next())
    {
        if(!query.value(0).toString().isEmpty())
        {
            QString path = getenv("LOCALAPPDATA");
            path.append("\\cadastrofutebol\\imagens\\arbitro\\" + query.value(0).toString());

            QFile file;
            if(!file.remove(path))
            {
                QMessageBox::critical(0, "Erro!", file.errorString());
                return;
            }
        }
    }

    atualizar();
}

void MainWindow::on_equNovo_clicked()
{
    equ = new cadastroEquipe();
    connect(equ, SIGNAL(destroyed()), this, SLOT(atualizar()));
    equ->show();
}

void MainWindow::on_equEditar_clicked()
{
    QSqlQuery query;
    QString editCode = ui->equTableWidget->selectedItems().first()->text();

    if(!query.exec("SELECT equipe.codequipe, equipe.nomeequipe, equipe.nomecompletoequipe, equipe.datafundacao, equipe.cidade, equipe.pais, tipoequipe.nometipoequipe, equipe.escudo, estadio.nomeestadio FROM equipe LEFT JOIN tipoequipe ON equipe.tipoequipe = tipoequipe.codtipoequipe LEFT JOIN estadio ON equipe.codestadio = estadio.codestadio WHERE codequipe = " + editCode))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
        return;
    }
    else
    {
        query.next();
        equ = new cadastroEquipe(query.value(0).toString(), query.value(1).toString(), query.value(2).toString(), query.value(3).toString(), query.value(4).toString(), query.value(5).toString(), query.value(6).toString(), query.value(7).toString(), query.value(8).toString());
        connect(equ, SIGNAL(destroyed()), this, SLOT(atualizar()));
        equ->show();
    }
}

void MainWindow::on_equExcluir_clicked()
{
    if(QMessageBox::No == QMessageBox(QMessageBox::Information,"Atenção!","Deseja realmente excluir o árbitro selecionado? Esta operação não poderá ser desfeita.", QMessageBox::Yes | QMessageBox::No).exec())
    {
        return;
    }

    QString id = ui->equTableWidget->selectedItems().first()->text();

    QSqlQuery query;
    if(!query.exec("DELETE FROM equipe WHERE codequipe = " + id + "RETURNING escudo"))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
        return;
    }

    if(query.next())
    {
        if(!query.value(0).toString().isEmpty())
        {
            QString path = getenv("LOCALAPPDATA");
            path.append("\\cadastrofutebol\\imagens\\equipe\\" + query.value(0).toString());

            QFile file;
            if(!file.remove(path))
            {
                QMessageBox::critical(0, "Erro!", file.errorString());
                return;
            }
        }
    }

    atualizar();
}

void MainWindow::on_jogEditar_clicked()
{
    QSqlQuery query;
    QString editCode = ui->jogTableWidget->selectedItems().first()->text();

    if(!query.exec("SELECT jogador.codjogador, jogador.codequipe, jogador.codtemporada, jogador.apelidojogador, jogador.nomejogador, jogador.numerocamisa, jogador.datanascimento, jogador.nacionalidade, jogador.posicao, jogador.status, jogador.email, jogador.foto FROM jogador LEFT JOIN equipe ON equipe.codequipe = jogador.codequipe LEFT JOIN temporada ON temporada.codtemporada = jogador.codtemporada WHERE jogador.codjogador = " + editCode))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
        return;
    }
    else
    {
        query.next();
        jog = new cadastroJogador(query.value(0).toString(), query.value(1).toString(), query.value(2).toString(), query.value(3).toString(), query.value(4).toString(), query.value(5).toString(), query.value(6).toString(), query.value(7).toString(), query.value(8).toString(), query.value(9).toString(), query.value(10).toString(), query.value(11).toString());
        connect(jog, SIGNAL(destroyed()), this, SLOT(atualizar()));
        jog->show();
    }
}



void MainWindow::on_jogExcluir_clicked()
{
    if(QMessageBox::No == QMessageBox(QMessageBox::Information,"Atenção!","Deseja realmente excluir o jogador selecionado? Esta operação não poderá ser desfeita.", QMessageBox::Yes | QMessageBox::No).exec())
    {
        return;
    }

    QString id = ui->jogTableWidget->selectedItems().first()->text();

    QSqlQuery query;
    if(!query.exec("DELETE FROM jogador WHERE codjogador = " + id + "RETURNING foto"))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
        return;
    }

    if(query.next())
    {
        if(!query.value(0).toString().isEmpty())
        {
            QString path = getenv("LOCALAPPDATA");
            path.append("\\cadastrofutebol\\imagens\\jogador\\" + query.value(0).toString());

            QFile file;
            if(!file.remove(path))
            {
                QMessageBox::critical(0, "Erro!", file.errorString());
                return;
            }
        }
    }

    atualizar();
}

void MainWindow::on_equipesParticipantesAdicionar_clicked()
{
    equipesparticipantes = new equipesParticipantes(ui->tempTableWidget->selectedItems().first()->text());
    connect(equipesparticipantes, SIGNAL(destroyed(QObject*)), this, SLOT(atualizar()));
    equipesparticipantes->show();
}

void MainWindow::on_tempAbrirTemporada_clicked()
{
    QString codtemporada = ui->tempTableWidget->selectedItems().first()->text();
    selecionarFase = new SelecionarFase(codtemporada);
    connect(selecionarFase, SIGNAL(destroyed(QObject*)), this, SLOT(atualizar()));
    selecionarFase->show();
}

void MainWindow::on_tempEstruturaTemporada_clicked()
{
    estt = new cadastroEstruturaTemporada(ui->tempTableWidget->selectedItems().first()->text());
    connect(estt, SIGNAL(destroyed(QObject*)), this, SLOT(atualizar()));
    estt->show();
}

void MainWindow::on_jogNovo_clicked()
{
    jog = new cadastroJogador();
    connect(jog, SIGNAL(destroyed(QObject*)), this, SLOT(atualizar()));
    jog->show();
}

void MainWindow::on_actionAtualizar_Banco_de_Dados_triggered()
{
    db->close();
    db = new Conexao("localhost", "postgres", "postgres", senha);

    QSqlQuery query;
    if(!query.exec("SELECT pg_terminate_backend(pg_stat_activity.pid) FROM pg_stat_activity WHERE pg_stat_activity.datname = 'cadastrofutebol' AND pid <> pg_backend_pid();"))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
        return;
    }
    if(!query.exec("DROP DATABASE cadastrofutebol"))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
        return;
    }
    if(!query.exec("CREATE DATABASE cadastrofutebol"))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
        return;
    }

    db->close();
    db = new Conexao("localhost", "cadastrofutebol", "postgres", senha);

    QMessageBox::information(0, "Finalizado!", "Operação realizada com sucesso! O programa será fechado agora, das próximas vezes não será mais necessário atualizar o banco de dados.");

    this->close();
}
