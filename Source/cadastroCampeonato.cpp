#include "cadastroCampeonato.h"
#include "ui_cadastroCampeonato.h"
#include "mainwindow.h"

cadastroCampeonato::cadastroCampeonato(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::cadastroCampeonato)
{
    ui->setupUi(this);
    this->imageIsChanged = false;
    this->imageIsRemoved = false;

    setWindowModality(Qt::ApplicationModal);

    atualizarComboBox();

    editMode = false;
}

cadastroCampeonato::cadastroCampeonato(QString editCode, QString tipo, QString nome, QString pais, QPixmap* pixmap, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::cadastroCampeonato)
{
    ui->setupUi(this);
    this->imageIsChanged = false;
    this->imageIsRemoved = false;

    setWindowModality(Qt::ApplicationModal);

    atualizarComboBox();

    ui->lineEdit->setText(nome);
    ui->comboBox->setCurrentText(tipo);
    ui->lineEdit_3->setText(pais);
    editMode = true;
    this->editCode = editCode;
    this->pixmap = pixmap;
}

cadastroCampeonato::~cadastroCampeonato()
{
    this->destroy();
    delete ui;
}

/**
 * @brief cadastroCampeonato::on_pushButton_clicked
 * Esta função é executada quando o usuário clica no botão "Selecionar Imagem..."
 */
void cadastroCampeonato::on_pushButton_clicked()
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
        imageIsChanged = true;
        imageIsRemoved = false;
        resizeEvent(NULL);
    }
    else
    {
        imageIsChanged = false;
    }
}

bool cadastroCampeonato::doesFileExist(const wchar_t *filename)
{
    return GetFileAttributes((LPCWSTR)filename) != INVALID_FILE_ATTRIBUTES;
}

/**
 * @brief cadastroCampeonato::on_pushButton_2_clicked
 * Esta função é executada quando é apertado do botão "CONFIRMAR" do "cadastroCampeonato.ui".
 * Ela adiciona as entradas ao banco, copia a imagem selecionada para o diretório \imagens\campeonato\ e altera
 * o nome dela para ter o mesmo ID da entrada inserida.
 * As entradas só são adicionadas se todos os campos forem preenchidos, e se a houver alguma imagem selecionada.
 *
 * É verificado aqui também se a janela foi aberta no modo de edição.
 * Nesse caso, ela já estará parcialmente preenchida e pode já conter, ou não, uma imagem.
 * Nesse caso, a informação não vai ser inserida no banco, e sim, será feito um Update sobre
 * um dado já existente no banco, já que estou editando.
 */
void cadastroCampeonato::on_pushButton_2_clicked()
{
    QSqlQuery query;
    QSqlQuery query2;

    //Verificação dos campos:
    if(ui->lineEdit->text().isEmpty() || ui->lineEdit_3->text().isEmpty() || ui->comboBox->currentText() == "" || ui->comboBox->currentText() == "Gerenciar tipos...")
    {
        QMessageBox messagebox;
        messagebox.critical(0, "Erro!", "Por favor, preencha todos os campos antes de confirmar.");
        return;
    }

    //Verificar se já existe entrada com o mesmo nome:
    if(!query.exec("SELECT * FROM campeonato WHERE nome = '" + ui->lineEdit->text() + "'"))
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
                QMessageBox::critical(0, "Erro!", "Já existe um campeonato com esse nome.");
                return;
            }
            else if(!editMode)
            {
                QMessageBox::critical(0, "Erro!", "Já existe um campeonato com esse nome.");
                return;
            }
        }
    }

    QString tipoText = "(SELECT codtipocampeonato FROM tipocampeonato WHERE nometipocampeonato = '" + ui->comboBox->currentText() + "')";

    if(editMode)
    {
        if(!query.exec("UPDATE campeonato SET nome = '" + ui->lineEdit->text() + "', codtipocampeonato = " + tipoText + ", pais = '" + ui->lineEdit_3->text() + "' WHERE codcampeonato = '" + editCode + "' RETURNING codcampeonato"))
        {
            QMessageBox messagebox;
            messagebox.critical(0, "Erro!", query.lastError().text());
        }
    }
    else
    {   
        if(!query.exec("INSERT INTO campeonato VALUES(default, " + tipoText + ", '" + ui->lineEdit->text() + "', '" + ui->lineEdit_3->text() + "', '') RETURNING codcampeonato"))
        {
            QMessageBox messagebox;
            messagebox.critical(0, "Erro!", query.lastError().text());
        }
    }

    query.next();

    QString filename;
    QString path;

    if(imageIsChanged) // Caso o usuário selecione alguma imagem apertando no botão "Selecionar imagem..."
    {   
        //Verifica se o diretório existe, se não existir, ele cria:
        QString dir = getenv("LOCALAPPDATA");
        dir.append("/cadastrofutebol/imagens/campeonato/");
        if(!doesFileExist(dir.toStdWString().c_str()))
        {
            if(!CreateDirectory(dir.toStdWString().c_str(), NULL))
            {
                QMessageBox::critical(0, "Erro!", "Não conseguiu criar a pasta!\n" + dir);
                return;
            }
        }

        //filename recebe o codcampeonato + extensão do arquivo original.
        filename = query.value(0).toString() + file.right(4);

        //path recebe o diretório da aplicação + nome do arquivo copiado.
        path = getenv("LOCALAPPDATA");
        path.append("/cadastrofutebol/imagens/campeonato/" + filename);

        //caso exista um arquivo com o nome do arquivo copiado na pasta, remove ele.
        if(QFile::exists(path))
        {
            QFile::remove(path);
        }

        QFile arquivo;

        //copia o arquivo original para a pasta imagens/campeonato/ com o nome igual a filename.
        if(!arquivo.copy(file, path))
        {
            QMessageBox messagebox;
            messagebox.critical(0, "Erro!", arquivo.errorString());
            return;
        }

        //adiciona o caminho da imagem ao banco
        if(!query2.exec("UPDATE campeonato SET escudo = '" + filename + "' WHERE codcampeonato = '" + query.value(0).toString() + "'"))
        {
            QMessageBox messagebox;
            messagebox.critical(0, "Erro!", query2.lastError().text());
        }
    }
    else if(!editMode)
    {

    }
    else
    {   
        //query2 recebe o caminho da imagem que está no banco.
        if(!query2.exec("SELECT escudo FROM campeonato WHERE codcampeonato = '" + editCode + "'"))
        {
            QMessageBox::critical(0, "Erro!", query2.lastError().text());
        }

        query2.next();

        //caso o campo escudo da tabela de campeonato não estiver vazia...
        if(!query2.value(0).toString().isEmpty() && imageIsRemoved)
        {
            //Verifica se o diretório existe, se não existir, ele cria:
            QString dir = getenv("LOCALAPPDATA");
            dir.append("/cadastrofutebol/imagens/campeonato/");
            if(!doesFileExist(dir.toStdWString().c_str()))
            {
                if(!CreateDirectory(dir.toStdWString().c_str(), NULL))
                {
                    QMessageBox::critical(0, "Erro!", "Não conseguiu criar a pasta!\n" + dir);
                    return;
                }
            }

            path = getenv("LOCALAPPDATA");
            path.append("/cadastrofutebol/imagens/campeonato/" + query2.value(0).toString());

            if(QFile::exists(path))
            {
                QFile::remove(path);
            }

            if(!query2.exec("UPDATE campeonato SET escudo = '' WHERE codcampeonato = '" + query.value(0).toString() + "'"))
            {
                QMessageBox messagebox;
                messagebox.critical(0, "Erro!", query2.lastError().text());
            }
        }
    }

    delete this;
}

/**
 * @brief cadastroCampeonato::on_pushButton_4_clicked
 * Esta função é executada quando o usuário aperta no botão "Remover imagem..."
 */
void cadastroCampeonato::on_pushButton_4_clicked()
{
    ui->label_4->clear();
    this->pixmap = NULL;
    file.clear();
    imageIsChanged = false;
    imageIsRemoved = true;
}

/**
 * @brief cadastroCampeonato::on_comboBox_activated
 * @param arg1
 * Esta função é ativada quando é clicado no botão "Gerenciar Tipos..."
 */
void cadastroCampeonato::on_comboBox_activated(const QString &arg1)
{
    if(arg1 == "Gerenciar tipos...")
    {
        tipoCampeonato *tipoWindow = new tipoCampeonato;
        connect(tipoWindow, SIGNAL(destroyed()), this, SLOT(atualizarComboBox()));
        tipoWindow->show();
    }
}

/**
 * @brief cadastroCampeonato::atualizarComboBox
 * Esta função atualiza o campo de tipos para que apareçam os mesmos tipos já criados no banco de dados.
 */
void cadastroCampeonato::atualizarComboBox()
{
    ui->comboBox->clear();
    ui->comboBox->addItem("");
    ui->comboBox->addItem("Gerenciar tipos...");

    QSqlQuery query;
    if(!query.exec("SELECT nometipocampeonato FROM tipocampeonato ORDER BY nometipocampeonato DESC"))
    {
        QMessageBox::critical(0, "Erro!", query.lastError().text());
    }

    while(query.next())
    {
        ui->comboBox->insertItem(0, query.value(0).toString());
    }
}

void cadastroCampeonato::resizeEvent(QResizeEvent* e)
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

void cadastroCampeonato::setPixmap()
{
    if(this->pixmap != NULL)
    {
        ui->label_4->setPixmap(pixmap->scaled(ui->label_4->width(), ui->label_4->height()));
    }
}
