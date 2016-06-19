#include "cadastroArbitro.h"
#include "ui_cadastroArbitro.h"

cadastroArbitro::cadastroArbitro(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::cadastroArbitro)
{
    ui->setupUi(this);

    setWindowModality(Qt::ApplicationModal);

    initiateComboBox();

    editMode = false;

    imageIsChanged = false;
}

cadastroArbitro::cadastroArbitro(QString s0, QString s1, QString s2, QString s3, QString s4, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::cadastroArbitro)
{
    ui->setupUi(this);

    setWindowModality(Qt::ApplicationModal);

    initiateComboBox();

    editMode = true;
    editCode = s0;
    ui->comboBox->setCurrentText(s1);
    ui->lineEdit->setText(s2);

    QString day, month, year;
    int i;

    for(i = 0; i < s3.size(); i++)
    {
        if(s3[i] != '-')
        {
            year = year + s3[i];
        }
        else
        {
            break;
        }
    }
    for(i++; i < s3.size(); i++)
    {
        if(s3[i] != '-')
        {
            day = day + s3[i];
        }
        else
        {
            break;
        }
    }
    for(i++; i < s3.size(); i++)
    {
        month = month + s3[i];
    }

    QDate date;
    date.setDate(year.toInt(), month.toInt(), day.toInt());
    ui->dateEdit->setDate(date);

    if(!s4.isEmpty())
    {
        QString path = getenv("LOCALAPPDATA");
        path.append("\\cadastrofutebol\\imagens\\arbitro\\" + s4);
        QPixmap* temp = new QPixmap;
        temp->load(path);
        this->pixmap = temp;
        resizeEvent(NULL);
    }

    imageIsChanged = false;
}

cadastroArbitro::~cadastroArbitro()
{
    delete ui;
}

/**
 * @brief cadastroArbitro::on_confirmar_clicked
 * Esta função é executada quando o botão "Confirmar" é clicado.
 */
void cadastroArbitro::on_Confirmar_clicked()
{
    QSqlQuery query;

    //Verifica se está tudo preenchido:
    if(ui->comboBox->currentText().isEmpty())
    {
        QMessageBox::critical(0, "Erro!", "Por favor preencha o campo \"Temporada Relacionada\".");
        return;
    }
    if(ui->lineEdit->text().isEmpty())
    {
        QMessageBox::critical(0, "Erro!", "Por favor preencha o campo \"Nome do Arbitro\".");
        return;
    }

    //Verifica se já existe árbitro com nome igual:
    if(!query.exec("SELECT * FROM arbitro WHERE nomearbitro = '" + ui->lineEdit->text() + "'"))
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
                QMessageBox::critical(0, "Erro!", "Já existe um árbitro com esse nome.");
                return;
            }
            else if(!editMode)
            {
                QMessageBox::critical(0, "Erro!", "Já existe um árbitro com esse nome.");
                return;
            }
        }
    }

    if(editMode)
    {
        if(!query.exec("SELECT codtemporada FROM temporada WHERE nometemporada = '" + ui->comboBox->currentText() + "'"))
        {
            QMessageBox::critical(0, "Erro!", query.lastError().text());
            return;
        }
        query.next();
        QString codtemporada = query.value(0).toString();
        if(!query.exec("UPDATE arbitro SET codtemporada = " + codtemporada +
                   ", nomearbitro = '" + ui->lineEdit->text() +
                   "', datanascimento = '" + QString::number(ui->dateEdit->date().year()) + "-" + QString::number(ui->dateEdit->date().month()) + "-" + QString::number(ui->dateEdit->date().day()) +
                   "' WHERE codarbitro = " + editCode + " RETURNING foto"))
        {
            QMessageBox::critical(0, "Erro!", query.lastError().text());
            return;
        }

        query.next();

        if(imageIsChanged) //Se alguma imagem tiver sido selecionada:
        {
            //Pegando a string do caminho + nome do arquivo que será criado.
            QString path;
            QString nomeDoArquivo = editCode + file.right(4);
            path = getenv("LOCALAPPDATA");
            path.append("\\cadastrofutebol\\imagens\\arbitro\\" + nomeDoArquivo);

            //Deletando o arquivo anterior ao novo arquivo colocado, caso exista:
            QFile arquivo;
            if(query.value(0).toString().size() > 0)
            {
                QString fileToBeDeleted = getenv("LOCALAPPDATA");
                fileToBeDeleted.append("\\cadastrofutebol\\imagens\\arbitro\\" + query.value(0).toString());
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
            if(!query.exec("UPDATE arbitro SET foto = '" + nomeDoArquivo + "' WHERE codarbitro = " + editCode))
            {
                QMessageBox::critical(0, "Erro!", query.lastError().text());
                return;
            }
        }
        else if(!ui->pixmap->pixmap() && !query.value(0).toString().isEmpty()) // Caso não tenha sido selecionada uma imagem, mas o campo de foto existir:
        {
            //Deletando o arquivo anterior ao novo arquivo colocado:
            QFile arquivo;
            QString fileToBeDeleted = getenv("LOCALAPPDATA");
            fileToBeDeleted.append("\\cadastrofutebol\\imagens\\arbitro\\" + query.value(0).toString());
            if(!arquivo.remove(fileToBeDeleted))
            {
                QMessageBox::critical(0, "Erro!", arquivo.errorString());
            }

            // Atualizar o banco informando que não há mais foto no arquivo:
            if(!query.exec("UPDATE arbitro SET foto = '' WHERE codarbitro = " + editCode))
            {
                QMessageBox::critical(0, "Erro!", query.lastError().text());
            }
        }
    }
    else // Se não estiver em modo de edição:
    {
        if(!query.exec("SELECT codtemporada FROM temporada WHERE nometemporada = '" + ui->comboBox->currentText() + "'"))
        {
            QMessageBox::critical(0, "Erro!", query.lastError().text());
            return;
        }
        query.next();
        if(!query.exec("INSERT INTO arbitro VALUES (default, " +
                       query.value(0).toString() + ", '" +
                       ui->lineEdit->text() + "', '" +
                       QString::number(ui->dateEdit->date().year()) +
                       "/" +
                       QString::number(ui->dateEdit->date().month()) +
                       "/" +
                       QString::number(ui->dateEdit->date().day()) +
                       "', '') RETURNING codarbitro"))
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
            path.append("\\cadastrofutebol\\imagens\\arbitro\\" + nomeDoArquivo);

            QFile arquivo;

            //copia o arquivo original para a pasta imagens/arbitro/ com o nome igual a filename.
            if(!arquivo.copy(file, path))
            {
                QMessageBox::critical(0, "Erro!", arquivo.errorString());
                return;
            }
            if(!query.exec("UPDATE arbitro SET foto = '" + nomeDoArquivo + "' WHERE codarbitro = " + lastEntry))
            {
                QMessageBox::critical(0, "Erro!", query.lastError().text());
                return;
            }
        }
    }

    delete this;
}

void cadastroArbitro::initiateComboBox()
{
    ui->comboBox->addItem("");

    QSqlQuery query;
    if(!query.exec("SELECT nometemporada FROM temporada"))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
        return;
    }

    while(query.next())
    {
        ui->comboBox->addItem(query.value(0).toString());
    }
}

void cadastroArbitro::setPixmap()
{
    if(this->pixmap != NULL)
    {
        ui->pixmap->setPixmap(this->pixmap->scaled(ui->pixmap->width(), ui->pixmap->height()));
    }
}

void cadastroArbitro::on_Cancelar_clicked()
{
    close();
}

void cadastroArbitro::on_SelecionarImg_clicked()
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

void cadastroArbitro::on_RemoverImg_clicked()
{
    ui->pixmap->clear();
    file.clear();
    this->pixmap = NULL;

    imageIsChanged = false;
}

void cadastroArbitro::resizeEvent(QResizeEvent *e)
{
    if(e)
    {
        setPixmap();
    }
    else
    {
        setPixmap();
    }
}
