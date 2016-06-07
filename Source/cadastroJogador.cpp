#include "cadastroJogador.h"
#include "ui_cadastroJogador.h"

cadastroJogador::cadastroJogador(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::cadastroJogador)
{
    ui->setupUi(this);

    inicializar_sem_jogador();

    atualizarComboBox();

    editMode = false;

    imageIsChanged = false;
}

cadastroJogador::cadastroJogador(QString codjogador, QString codequipe, QString codtemporada,
                                 QString apelidojogador, QString nomejogador, QString numerocamisa,
                                 QString datanascimento, QString nacionalidade, QString posicao,
                                 QString status, QString email, QString foto, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::cadastroJogador)
{
    ui->setupUi(this);

    setWindowModality(Qt::ApplicationModal);

    editMode = true;

    editCode = codjogador;

    atualizarComboBox();

    QSqlQuery query;
    if(!query.exec("SELECT nomeequipe FROM equipe WHERE codequipe = '" + codequipe + "'"))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
    }
    query.next();
    ui->EquipeRelacionada->setCurrentText(query.value(0).toString());

    if(!query.exec("SELECT nometemporada FROM temporada WHERE codtemporada = '" + codtemporada + "'"))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
    }
    query.next();
    ui->TemporadaRelacionada->setCurrentText(query.value(0).toString());

    ui->Apelido->setText(apelidojogador);
    ui->Nome->setText(nomejogador);
    ui->NumeroCamisa->setValue(numerocamisa.toInt());

    QString day, month, year;
    int i;

    for(i = 0; i < datanascimento.size(); i++)
    {
        if(datanascimento[i] != '-')
        {
            year = year + datanascimento[i];
        }
        else
        {
            break;
        }
    }
    for(i++; i < datanascimento.size(); i++)
    {
        if(datanascimento[i] != '-')
        {
            day = day + datanascimento[i];
        }
        else
        {
            break;
        }
    }
    for(i++; i < datanascimento.size(); i++)
    {
        month = month + datanascimento[i];
    }

    QDate date;
    date.setDate(year.toInt(), month.toInt(), day.toInt());
    ui->DataNascimento->setDate(date);

    ui->Nacionalidade->setText(nacionalidade);
    ui->Posicao->setCurrentIndex(posicao.toInt());
    ui->Status->setText(status);
    ui->Email->setText(email);

    if(!foto.isEmpty())
    {
        QString path = getenv("LOCALAPPDATA");
        path.append("\\cadastrofutebol\\imagens\\jogador\\" + foto);
        QPixmap temp;
        temp.load(path);
        ui->Pixmap->setPixmap(temp.scaled(150, 150));
    }

    imageIsChanged = false;
}

void cadastroJogador::atualizarComboBox()
{
    QSqlQuery query;

    // Equipe Relacionada:
    ui->EquipeRelacionada->clear();
    ui->EquipeRelacionada->addItem("");

    if(!query.exec("SELECT nomeequipe FROM equipe ORDER BY nomeequipe DESC"))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
    }

    while(query.next())
    {
        ui->EquipeRelacionada->insertItem(0, query.value(0).toString());
    }

    // Temporada Relacionada:
    ui->TemporadaRelacionada->clear();
    ui->TemporadaRelacionada->addItem("");

    if(!query.exec("SELECT nometemporada FROM temporada ORDER BY nometemporada DESC"))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
    }

    while(query.next())
    {
        ui->TemporadaRelacionada->insertItem(0, query.value(0).toString());
    }

    ui->Posicao->setCurrentIndex(0);
}

void cadastroJogador::inicializar_sem_jogador()
{
    QSqlQuery query;

    //Verifica se já existe o tipo "(sem tipo)", se não existir, ele cria:
    if(!query.exec("SELECT * FROM tipoequipe WHERE tipoequipe.nometipoequipe = '(sem tipo)'"))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
        return;
    }
    if(!query.next())
    {
        if(!query.exec("INSERT INTO tipoequipe VALUES (default, '(sem tipo)')"))
        {
            QMessageBox::critical(0, "Erro!", query.lastError().text());
            return;
        }
    }

    //Verifica se já existe a equipe "(sem nome)", se não existe, ele cria:
    if(!query.exec("SELECT * FROM equipe WHERE equipe.nomeequipe = '(sem nome)'"))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
        return;
    }
    if(!query.next())
    {
        QString codsemtipo;
        //Pega o id do tipo "(sem tipo)":
        if(!query.exec("SELECT codtipoequipe FROM tipoequipe WHERE nometipoequipe = '(sem tipo)'"))
        {
            QMessageBox::critical(0, "Erro!", query.lastError().text());
        }
        if(query.next())
        {
            codsemtipo = query.value(0).toString();
        }
        else
        {
            QMessageBox::critical(0, "Erro!", "Contate o desenvolvedor e diga que a ordem das coisas está incorreta na criação do cadastro de jogador.");
            return;
        }

        if(!query.exec("INSERT INTO equipe VALUES(default, '(sem nome)', '(sem nome)', NULL, NULL, NULL, " + codsemtipo + ", NULL, NULL)"))
        {
            QMessageBox::critical(0, "Erro!", query.lastError().text());
            return;
        }
    }
}

cadastroJogador::~cadastroJogador()
{
    delete ui;
}

void cadastroJogador::on_Confirmar_clicked()
{
    QSqlQuery query;

    //Verificação dos campos:
    if(ui->Nome->text().isEmpty())
    {
        QMessageBox::critical(0, "Erro!", "Por favor, preencha o campo \"Nome\".");
        return;
    }
    if(ui->EquipeRelacionada->currentText().isEmpty())
    {
        QMessageBox::critical(0, "Erro!", "Por favor, preencha o campo \"Equipe Relacionada\".");
        return;
    }
    if(ui->TemporadaRelacionada->currentText().isEmpty())
    {
        QMessageBox::critical(0, "Erro!", "Por favor, preencha o campo \"Temporada Relacionada\".");
        return;
    }

    //Verificar se já existe jogador com o mesmo nome:
    if(!query.exec("SELECT * FROM jogador WHERE nomejogador = '" + ui->Nome->text() + "'"))
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
                QMessageBox::critical(0, "Erro!", "Já existe um jogador com esse nome.");
                return;
            }
            else if(!editMode)
            {
                QMessageBox::critical(0, "Erro!", "Já existe um jogador com esse nome.");
                return;
            }
        }
    }

    //Adicionando ao banco de dados:
    if(editMode) // Se estiver em modo de edição:
    {
        QString codequipe, codtemporada;
        if(!ui->EquipeRelacionada->currentText().isEmpty())
        {
            if(!query.exec("SELECT equipe.codequipe FROM equipe WHERE equipe.nomeequipe = '" + ui->EquipeRelacionada->currentText() + "'"))
            {
                QMessageBox::critical(0, "Erro!", query.lastError().text());
                return;
            }
            query.next();
            codequipe = query.value(0).toString();
        }
        else
        {
            codequipe = "NULL";
        }
        if(!ui->TemporadaRelacionada->currentText().isEmpty())
        {
            if(!query.exec("SELECT temporada.codtemporada FROM temporada WHERE temporada.nometemporada = '" + ui->TemporadaRelacionada->currentText() + "'"))
            {
                QMessageBox::critical(0, "Erro!", query.lastError().text());
                return;
            }
            query.next();
            codtemporada = query.value(0).toString();
        }
        else
        {
            codtemporada = "NULL";
        }

        query.next();
        if(!query.exec("UPDATE jogador SET "
                       "codequipe = " + codequipe + ", " +
                       "codtemporada = " + codtemporada + ", " +
                       "apelidojogador = '" + ui->Apelido->text() + "', " +
                       "nomejogador = '" + ui->Nome->text() + "', " +
                       "numerocamisa = " + ui->NumeroCamisa->text() + ", " +
                       "datanascimento = '" + QString::number(ui->DataNascimento->date().year()) + "-" + QString::number(ui->DataNascimento->date().month()) + "-" + QString::number(ui->DataNascimento->date().day()) + "', " +
                       "nacionalidade = '" + ui->Nacionalidade->text() + "', " +
                       "posicao = " + QString::number(ui->Posicao->currentIndex()) + ", " +
                       "status = '" + ui->Status->text() + "', " +
                       "email = '" + ui->Email->text() + "' "
                       "WHERE codjogador = " + editCode + " RETURNING foto"))
        {
            QMessageBox::critical(0, "Erro!", query.lastError().text());
            return;
        }

        query.next();

        if(imageIsChanged) //Se a imagem tiver sido alterada, pressionando-se o botão "Selecionar imagem".
        {
            //Pegando a string do caminho + nome do arquivo que será criado.
            QString path;
            QString nomeDoArquivo = editCode + file.right(4);
            path = getenv("LOCALAPPDATA");
            path.append("\\cadastrofutebol\\imagens\\jogador\\" + nomeDoArquivo);

            //Deletando o arquivo anterior ao novo arquivo colocado, caso exista:
            QFile arquivo;
            if(query.value(0).toString().size() > 0)
            {
                QString fileToBeDeleted = getenv("LOCALAPPDATA");
                fileToBeDeleted.append("\\cadastrofutebol\\imagens\\jogador\\" + query.value(0).toString());
                if(!arquivo.remove(fileToBeDeleted))
                {
                    QMessageBox::critical(0, "Erro!", arquivo.errorString());
                    return;
                }
            }

            //Copiando o novo arquivo para o seu devido local:
            if(!arquivo.copy(file, path))
            {
                QMessageBox::critical(0, "Erro!", arquivo.errorString());
                return;
            }
            if(!query.exec("UPDATE jogador SET foto = '" + nomeDoArquivo + "' WHERE codjogador = " + editCode))
            {
                QMessageBox::critical(0, "Erro!", query.lastError().text());
                return;
            }
        }
        else if(!ui->Pixmap->pixmap() && !query.value(0).toString().isEmpty()) // Caso não exista imagem selecionada, mas o campo de foto no banco de dados existir:
        {
            //Deletando o arquivo anterior ao novo arquivo colocado:
            QFile arquivo;
            QString fileToBeDeleted = getenv("LOCALAPPDATA");
            fileToBeDeleted.append("\\cadastrofutebol\\imagens\\jogador\\" + query.value(0).toString());
            if(!arquivo.remove(fileToBeDeleted))
            {
                QMessageBox::critical(0, "Erro!", arquivo.errorString());
            }

            //Atualizar o banco informando que não há mais foto no arquivo:
            if(!query.exec("UPDATE jogador SET foto = '' WHERE codjogador = " + editCode))
            {
                QMessageBox::critical(0, "Erro!", query.lastError().text());
            }
        }
        else // Caso exista uma imagem, mas ela não tenha sido alterada:
        {

        }
    }
    else // Se não estiver em modo de edição:
    {
        QString codequipe, codtemporada;
        if(!ui->EquipeRelacionada->currentText().isEmpty())
        {
            if(!query.exec("SELECT equipe.codequipe FROM equipe WHERE equipe.nomeequipe = '" + ui->EquipeRelacionada->currentText() + "'"))
            {
                QMessageBox::critical(0, "Erro!", query.lastError().text());
                return;
            }
            query.next();
            codequipe = query.value(0).toString();
        }
        else
        {
            codequipe = "NULL";
        }
        if(!ui->TemporadaRelacionada->currentText().isEmpty())
        {
            if(!query.exec("SELECT temporada.codtemporada FROM temporada WHERE temporada.nometemporada = '" + ui->TemporadaRelacionada->currentText() + "'"))
            {
                QMessageBox::critical(0, "Erro!", query.lastError().text());
                return;
            }
            query.next();
            codtemporada = query.value(0).toString();
        }
        else
        {
            codtemporada = "NULL";
        }

        if(!query.exec("INSERT INTO jogador VALUES (default, " +
                       codequipe + ", " +
                       codtemporada + ", '" +
                       ui->Apelido->text() + "', '" +
                       ui->Nome->text() + "', " +
                       ui->NumeroCamisa->text() + ", '" +
                       QString::number(ui->DataNascimento->date().year()) + "-" + QString::number(ui->DataNascimento->date().month()) + "-" + QString::number(ui->DataNascimento->date().day()) + "', '" +
                       ui->Nacionalidade->text() + "', " +
                       QString::number(ui->Posicao->currentIndex()) + ", '" +
                       ui->Status->text() + "', '" +
                       ui->Email->text() + "', " +
                       "'' " + ") RETURNING codjogador"))
        {
            QMessageBox::critical(0, "Erro!", query.lastError().text());
            return;
        }

        query.next();

        QString lastEntry = query.value(0).toString();

        if(file.size() > 0)
        {
            //Copiando a imagem para a sua devida pasta no localappdata:
            QString path;
            QString nomeDoArquivo = query.value(0).toString() + file.right(4);
            path = getenv("LOCALAPPDATA");
            path.append("\\cadastrofutebol\\imagens\\jogador\\" + nomeDoArquivo);

            QFile arquivo;

            //copia o arquivo original para a pasta imagens/jogador/ com o nome igual a filename.
            if(!arquivo.copy(file, path))
            {
                QMessageBox::critical(0, "Erro!", arquivo.errorString());
                return;
            }
            if(!query.exec("UPDATE jogador SET foto = '" + nomeDoArquivo + "' WHERE codjogador = " + lastEntry))
            {
                QMessageBox::critical(0, "Erro!", query.lastError().text());
                return;
            }
        }

    }
    delete this;
}

void cadastroJogador::keyPressEvent(QKeyEvent *e)
{
    if(e->key() == Qt::Key_Return)
    {
        ui->Confirmar->click();
    }
}

void cadastroJogador::on_SelecionarImagem_clicked()
{
    QString aux = QFileDialog::getOpenFileName(this, "Selecione uma imagem", "/home", "Images (*.png *.jpg)", NULL, QFileDialog::DontUseNativeDialog);
    if(!aux.isEmpty())
    {
        file = aux;
    }

    if(!file.isEmpty())
    {
        QPixmap pixmap;
        if(!pixmap.load(file))
        {
            QMessageBox::critical(0, "Erro!", "Não foi possível carregar a imagem " + file + ".");
            return;
        }

        ui->Pixmap->setPixmap(pixmap.scaled(150, 150));
        imageIsChanged = true;
    }
    else
    {
        imageIsChanged = false;
    }
}

void cadastroJogador::on_RemoverImagem_clicked()
{
    ui->Pixmap->clear();

    file.clear();

    imageIsChanged = false;
}

void cadastroJogador::on_Cancelar_clicked()
{
    close();
}
