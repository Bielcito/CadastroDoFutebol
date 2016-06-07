#include "cadastroEquipe.h"
#include "ui_cadastroEquipe.h"

cadastroEquipe::cadastroEquipe(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::cadastroEquipe)
{
    ui->setupUi(this);

    setWindowModality(Qt::ApplicationModal);

    atualizarComboBox();

    editMode = false;

    imageIsChanged = false;
}

cadastroEquipe::cadastroEquipe(QString codequipe, QString nomeequipe, QString nomecompletoequipe, QString datafundacao, QString cidade, QString pais, QString tipoequipe, QString escudo, QString estadio, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::cadastroEquipe)
{
    ui->setupUi(this);

    setWindowModality(Qt::ApplicationModal);

    editMode = true;

    editCode = codequipe;

    atualizarComboBox();

    ui->Nome->setText(nomeequipe);
    ui->NomeCompleto->setText(nomecompletoequipe);

    QString day, month, year;
    int i;

    for(i = 0; i < datafundacao.size(); i++)
    {
        if(datafundacao[i] != '-')
        {
            year = year + datafundacao[i];
        }
        else
        {
            break;
        }
    }
    for(i++; i < datafundacao.size(); i++)
    {
        if(datafundacao[i] != '-')
        {
            day = day + datafundacao[i];
        }
        else
        {
            break;
        }
    }
    for(i++; i < datafundacao.size(); i++)
    {
        month = month + datafundacao[i];
    }

    QDate date;
    date.setDate(year.toInt(), month.toInt(), day.toInt());
    ui->DataFundacao->setDate(date);

    ui->Cidade->setText(cidade);
    ui->Pais->setText(pais);
    ui->Tipo->setCurrentText(tipoequipe);

    if(!escudo.isEmpty())
    {
        QString path = getenv("LOCALAPPDATA");
        path.append("\\cadastrofutebol\\imagens\\equipe\\" + escudo);
        QPixmap* temp = new QPixmap;
        temp->load(path);
        this->pixmap = temp;
        resizeEvent(NULL);
    }

    ui->EstadioRelacionado->setCurrentText(estadio);

    imageIsChanged = false;
}

cadastroEquipe::~cadastroEquipe()
{
    delete ui;
}

void cadastroEquipe::on_Tipo_activated(const QString &arg1)
{
    if(arg1 == "Gerenciar tipos...")
    {
        tipoequipe *tipoWindow = new tipoequipe;
        connect(tipoWindow, SIGNAL(destroyed()), this, SLOT(atualizarComboBox()));
        tipoWindow->show();
    }
}

/**
 * @brief cadastroCampeonato::atualizarComboBox
 * Esta função atualiza o campo de tipos para que apareçam os mesmos tipos já criados no banco de dados.
 */
void cadastroEquipe::atualizarComboBox()
{
    // Tipo:
    ui->Tipo->clear();
    ui->Tipo->addItem("");
    ui->Tipo->addItem("Gerenciar tipos...");

    QSqlQuery query;
    if(!query.exec("SELECT nometipoequipe FROM tipoequipe ORDER BY nometipoequipe DESC"))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
    }

    while(query.next())
    {
        ui->Tipo->insertItem(0, query.value(0).toString());
    }

    // Estadio Relacionado:
    ui->EstadioRelacionado->clear();
    ui->EstadioRelacionado->addItem("");

    if(!query.exec("SELECT nomeestadio FROM estadio ORDER BY nomeestadio DESC"))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
    }

    while(query.next())
    {
        ui->EstadioRelacionado->insertItem(0, query.value(0).toString());
    }
}

void cadastroEquipe::on_Confirmar_clicked()
{
    QSqlQuery query;

    //Verificação dos campos:
    if(ui->Nome->text().isEmpty())
    {
        QMessageBox::critical(0, "Erro!", "Por favor, preencha o campo \"Nome\".");
        return;
    }
    if(ui->Tipo->currentText().isEmpty())
    {
        QMessageBox::critical(0, "Erro!", "Por favor, preencha o campo \"Tipo\".");
        return;
    }

    //Verificar se já existe equipe com o mesmo nome:
    if(!query.exec("SELECT * FROM equipe WHERE nomeequipe = '" + ui->Nome->text() + "'"))
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
                QMessageBox::critical(0, "Erro!", "Já existe uma equipe com esse nome.");
                return;
            }
            else if(!editMode)
            {
                QMessageBox::critical(0, "Erro!", "Já existe uma equipe com esse nome.");
                return;
            }
        }
    }

    //Adicionando ao banco de dados:
    if(editMode) // Se estiver em modo de edição:
    {
        QString codtipoequipe, codestadio;
        if(!ui->Tipo->currentText().isEmpty())
        {
            if(!query.exec("SELECT tipoequipe.codtipoequipe FROM tipoequipe WHERE tipoequipe.nometipoequipe = '" + ui->Tipo->currentText() + "'"))
            {
                QMessageBox::critical(0, "Erro!", query.lastError().text());
                return;
            }
            query.next();
            codtipoequipe = query.value(0).toString();
        }
        else
        {
            codtipoequipe = "NULL";
        }
        if(!ui->EstadioRelacionado->currentText().isEmpty())
        {
            if(!query.exec("SELECT estadio.codestadio FROM estadio WHERE nomeestadio = '" + ui->EstadioRelacionado->currentText() + "'"))
            {
                QMessageBox::critical(0, "Erro!", query.lastError().text());
                return;
            }
            query.next();
            codestadio = query.value(0).toString();
        }
        else
        {
            codestadio = "NULL";
        }

        if(!query.exec("UPDATE equipe SET "
                       "nomeequipe = '" + ui->Nome->text() + "', " +
                       "nomecompletoequipe = '" + ui->NomeCompleto->text() + "', " +
                       "datafundacao = '" + QString::number(ui->DataFundacao->date().year()) + "-" + QString::number(ui->DataFundacao->date().month()) + "-" + QString::number(ui->DataFundacao->date().day()) + "', " +
                       "cidade = '" + ui->Cidade->text() + "', " +
                       "pais = '" + ui->Pais->text() + "', " +
                       "tipoequipe = " + codtipoequipe + ", " +
                       "codestadio = " + codestadio + " " +
                       "WHERE codequipe = " + editCode + " RETURNING escudo"))
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
            path.append("\\cadastrofutebol\\imagens\\equipe\\" + nomeDoArquivo);

            //Deletando o arquivo anterior ao novo arquivo colocado, caso exista:
            QFile arquivo;
            if(query.value(0).toString().size() > 0)
            {
                QString fileToBeDeleted = getenv("LOCALAPPDATA");
                fileToBeDeleted.append("\\cadastrofutebol\\imagens\\equipe\\" + query.value(0).toString());
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
            if(!query.exec("UPDATE equipe SET escudo = '" + nomeDoArquivo + "' WHERE codequipe = " + editCode))
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
            fileToBeDeleted.append("\\cadastrofutebol\\imagens\\equipe\\" + query.value(0).toString());
            if(!arquivo.remove(fileToBeDeleted))
            {
                QMessageBox::critical(0, "Erro!", arquivo.errorString());
            }

            //Atualizar o banco informando que não há mais foto no arquivo:
            if(!query.exec("UPDATE equipe SET escudo = '' WHERE codequipe = " + editCode))
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
        QString codtipoequipe, codestadio;
        if(!ui->Tipo->currentText().isEmpty())
        {
            if(!query.exec("SELECT tipoequipe.codtipoequipe FROM tipoequipe WHERE tipoequipe.nometipoequipe = '" + ui->Tipo->currentText() + "'"))
            {
                QMessageBox::critical(0, "Erro!", query.lastError().text());
                return;
            }
            query.next();
            codtipoequipe = query.value(0).toString();
        }
        else
        {
            codtipoequipe = "NULL";
        }
        if(!ui->EstadioRelacionado->currentText().isEmpty())
        {
            if(!query.exec("SELECT estadio.codestadio FROM estadio WHERE nomeestadio = '" + ui->EstadioRelacionado->currentText() + "'"))
            {
                QMessageBox::critical(0, "Erro!", query.lastError().text());
                return;
            }
            query.next();
            codestadio = query.value(0).toString();
        }
        else
        {
            codestadio = "NULL";
        }

        if(!query.exec("INSERT INTO equipe VALUES (default, '" +
                       ui->Nome->text() + "', '" +
                       ui->NomeCompleto->text() + "', '" +
                       QString::number(ui->DataFundacao->date().year()) + "-" + QString::number(ui->DataFundacao->date().month()) + "-" + QString::number(ui->DataFundacao->date().day()) + "', '" +
                       ui->Cidade->text() + "', '" +
                       ui->Pais->text() + "', " +
                       codtipoequipe + ", '', " +
                       codestadio + ") RETURNING codequipe"))
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
            path.append("\\cadastrofutebol\\imagens\\equipe\\" + nomeDoArquivo);

            QFile arquivo;

            //copia o arquivo original para a pasta imagens/equipe/ com o nome igual a filename.
            if(!arquivo.copy(file, path))
            {
                QMessageBox::critical(0, "Erro!", arquivo.errorString());
                return;
            }
            if(!query.exec("UPDATE equipe SET escudo = '" + nomeDoArquivo + "' WHERE codequipe = " + lastEntry))
            {
                QMessageBox::critical(0, "Erro!", query.lastError().text());
                QMessageBox::information(0, "2", "");
                return;
            }
        }

    }
    delete this;
}

void cadastroEquipe::on_SelecionarImagem_clicked()
{
    QString aux = QFileDialog::getOpenFileName(this, "Selecione uma imagem", "/home", "Images (*.png *.jpg)", NULL, QFileDialog::DontUseNativeDialog);
    if(!aux.isEmpty())
    {
        file = aux;
    }

    if(!file.isEmpty())
    {
        QPixmap* pixmap = new QPixmap;
        if(!pixmap->load(file))
        {
            QMessageBox::critical(0, "Erro!", "Não foi possível carregar a imagem " + file + ".");
            return;
        }

        this->pixmap = pixmap;
        resizeEvent(NULL);
        imageIsChanged = true;
    }
    else
    {
        imageIsChanged = false;
    }
}

void cadastroEquipe::on_RemoverImagem_clicked()
{
    ui->Pixmap->clear();
    file.clear();
    this->pixmap = NULL;

    imageIsChanged = false;
}

void cadastroEquipe::resizeEvent(QResizeEvent *e)
{
    setPixmap();
}

void cadastroEquipe::keyPressEvent(QKeyEvent *e)
{
    if(e->key() == Qt::Key_Return)
    {
        ui->Confirmar->click();
    }
}

void cadastroEquipe::setPixmap()
{
    if(this->pixmap != NULL)
    {
        ui->Pixmap->setPixmap(pixmap->scaled(ui->Pixmap->width(), ui->Pixmap->height()));
    }
}
