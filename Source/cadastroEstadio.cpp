#include "cadastroEstadio.h"
#include "ui_cadastroEstadio.h"

cadastroEstadio::cadastroEstadio(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::cadastroEstadio)
{
    ui->setupUi(this);

    setWindowModality(Qt::ApplicationModal);

    editMode = false;

    imageIsChanged = false;
}

cadastroEstadio::cadastroEstadio(QString sCode, QString nome, QString nomecompleto, QString capacidade, QString cidade, QPixmap *pixmap, QString pais, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::cadastroEstadio)
{
    ui->setupUi(this);

    setWindowModality(Qt::ApplicationModal);

    editMode = true;
    editCode = sCode;

    ui->estNome->setText(nome);
    ui->estNomeCompleto->setText(nomecompleto);
    ui->estCapacidade->setValue(capacidade.toInt());
    ui->estCidade->setText(cidade);

    this->pixmap = pixmap;

    resizeEvent(NULL);

    imageIsChanged = false;
}

cadastroEstadio::~cadastroEstadio()
{
    this->destroy();
    delete ui;
}

void cadastroEstadio::on_SelecionarImg_clicked()
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

void cadastroEstadio::on_Confirmar_clicked()
{
    QSqlQuery query;

    //Verificação dos campos:
    if(ui->estNome->text().isEmpty())
    {
        QMessageBox::critical(0, "Erro!", "Por favor, preencha o campo \"Nome\".");
        return;
    }

    //Verificar se já existe estadio com o mesmo nome:
    if(!query.exec("SELECT * FROM estadio WHERE nomeestadio = '" + ui->estNome->text() + "'"))
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
                QMessageBox::critical(0, "Erro!", "Já existe um estádio com esse nome.");
                return;
            }
            else if(!editMode)
            {
                QMessageBox::critical(0, "Erro!", "Já existe um estádio com esse nome.");
                return;
            }
        }
    }

    //Adicionando ao banco de dados:
    if(editMode) // Se estiver em modo de edição:
    {
        if(!query.exec("UPDATE estadio SET "
                       "nomeestadio = '" + ui->estNome->text() + "', " +
                       "nomecompletoestadio = '" + ui->estNomeCompleto->text() + "', " +
                       "capacidadeestadio = " + ui->estCapacidade->text() + ", " +
                       "cidadeestadio = '" + ui->estCidade->text() + "', " +
                       "pais = '" + ui->estPais->text() + "' " +
                       "WHERE codestadio = " + editCode + " RETURNING foto"))
        {
            QMessageBox::critical(0, "Erro!", query.lastError().text());
            return;
        }

        query.next();


        if(imageIsChanged) //Se a imagem tiver sido alterada, pressionando-se o botão "Selecionar imagem".
        {
            //verificando se o diretório para as imagens já está criado, se não estiver, cria.
            {
                QString path;
                path = getenv("LOCALAPPDATA");
                path.append("\\cadastrofutebol\\imagens\\estadio\\");

                if(!doesFileExist(path.toStdWString().c_str()))
                {
                    if(!CreateDirectory(path.toStdWString().c_str(), NULL))
                    {
                        QMessageBox::critical(0, "Erro!", "Não conseguiu criar a pasta!\n" + path);
                        return;
                    }
                }
            }

            //Pegando a string do caminho + nome do arquivo que será criado.
            QString path;
            QString nomeDoArquivo = editCode + file.right(4);
            path = getenv("LOCALAPPDATA");
            path.append("\\cadastrofutebol\\imagens\\estadio\\" + nomeDoArquivo);

            //Deletando o arquivo anterior ao novo arquivo colocado, caso exista:
            QFile arquivo;
            if(query.value(0).toString().size() > 0)
            {
                QString fileToBeDeleted = getenv("LOCALAPPDATA");
                fileToBeDeleted.append("\\cadastrofutebol\\imagens\\estadio\\" + query.value(0).toString());
                if(!arquivo.remove(fileToBeDeleted))
                {
                    QMessageBox::critical(0, "Erro!", arquivo.errorString());
                }
            }

            //Copiando o novo arquivo para o seu devido local:
            if(!arquivo.copy(file, path))
            {
                QMessageBox::critical(0, "Erro!", arquivo.errorString());
                return;
            }
            if(!query.exec("UPDATE estadio SET foto = '" + nomeDoArquivo + "' WHERE codestadio = " + editCode))
            {
                QMessageBox::critical(0, "Erro!", query.lastError().text());
                return;
            }
        }
        else if(!ui->estPixmap->pixmap() && !query.value(0).toString().isEmpty()) // Caso não exista imagem selecionada, mas o campo de foto no banco de dados existir:
        {
            //Deletando o arquivo anterior ao novo arquivo colocado:
            QFile arquivo;
            QString fileToBeDeleted = getenv("LOCALAPPDATA");
            fileToBeDeleted.append("\\cadastrofutebol\\imagens\\estadio\\" + query.value(0).toString());
            if(!arquivo.remove(fileToBeDeleted))
            {
                QMessageBox::critical(0, "Erro!", arquivo.errorString());
            }

            //Atualizar o banco informando que não há mais foto no arquivo:
            if(!query.exec("UPDATE estadio SET foto = '' WHERE codestadio = " + editCode))
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
        if(!query.exec("INSERT INTO estadio VALUES (default, '" +
                       ui->estNome->text() + "', '" +
                       ui->estNomeCompleto->text() + "', " +
                       ui->estCapacidade->text() + ", '" +
                       ui->estCidade->text() + "', '', '" +
                       ui->estPais->text() + "') RETURNING codestadio"))
        {
            QMessageBox::critical(0, "Erro!", query.lastError().text());
            return;
        }

        query.next();

        QString lastEntry = query.value(0).toString();

        if(file.size() > 0)
        {
            //verificando se o diretório para as imagens já está criado, se não estiver, cria.
            {
                QString path;
                path = getenv("LOCALAPPDATA");
                path.append("\\cadastrofutebol\\imagens\\estadio\\");

                if(!doesFileExist(path.toStdWString().c_str()))
                {
                    if(!CreateDirectory(path.toStdWString().c_str(), NULL))
                    {
                        QMessageBox::critical(0, "Erro!", "Não conseguiu criar a pasta!\n" + path);
                        return;
                    }
                }
            }

            QMessageBox::information(0, "Chegou!", "");

            //Copiando a imagem para a sua devida pasta no localappdata:
            QString path;
            QString nomeDoArquivo = query.value(0).toString() + file.right(4);
            path = getenv("LOCALAPPDATA");
            path.append("\\cadastrofutebol\\imagens\\estadio\\" + nomeDoArquivo);

            QFile arquivo;

            //copia o arquivo original para a pasta imagens/campeonato/ com o nome igual a filename.
            if(!arquivo.copy(file, path))
            {
                QMessageBox::critical(0, "Erro!", arquivo.errorString());
                return;
            }
            if(!query.exec("UPDATE estadio SET foto = '" + nomeDoArquivo + "' WHERE codestadio = " + lastEntry))
            {
                QMessageBox::critical(0, "Erro!", query.lastError().text());
                return;
            }
        }

    }
    delete this;
}

void cadastroEstadio::on_RemoverImg_clicked()
{
    ui->estPixmap->clear();
    file.clear();

    this->pixmap = NULL;

    imageIsChanged = false;
}

void cadastroEstadio::on_Cancelar_clicked()
{
    this->close();
}

void cadastroEstadio::resizeEvent(QResizeEvent *e)
{
    setPixmap();
}

bool cadastroEstadio::doesFileExist(const wchar_t *filename)
{
    return GetFileAttributes((LPCWSTR)filename) != INVALID_FILE_ATTRIBUTES;
}

void cadastroEstadio::setPixmap()
{
    if(pixmap != NULL)
    {
        ui->estPixmap->setPixmap(pixmap->scaled(ui->estPixmap->width(), ui->estPixmap->height()));
    }
}
