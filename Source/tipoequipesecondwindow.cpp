#include "tipoequipesecondwindow.h"
#include "ui_tipoequipesecondwindow.h"

tipoequipesecondwindow::tipoequipesecondwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tipoequipesecondwindow)
{
    ui->setupUi(this);

    setWindowModality(Qt::ApplicationModal);
    editMode = false;
    ui->nome->setFocus();
}

tipoequipesecondwindow::tipoequipesecondwindow(QString item, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tipoequipesecondwindow)
{
    ui->setupUi(this);

    setWindowModality(Qt::ApplicationModal);
    editMode = true;

    // Achando o valor do editCode:
    QSqlQuery query;
    query.exec("SELECT codtipoequipe FROM tipoequipe WHERE nometipoequipe = '" + item + "'");
    query.next();
    editCode = query.value(0).toString();

    //Inicializando o campo com o valor do item:
    ui->nome->setText(item);
    ui->nome->setFocus();
}

tipoequipesecondwindow::~tipoequipesecondwindow()
{
    delete ui;
}

void tipoequipesecondwindow::on_ok_clicked()
{
    if(ui->nome->text().size() == 0)
    {
        QMessageBox::critical(0, "Erro!", "Por favor, preencha o campo \"Nome\" para continuar.");
    }
    else
    {
        QSqlQuery query;

        //Testa para ver se o nome já existe:
        if(!query.exec("SELECT * FROM tipoequipe WHERE nometipoequipe = '" + ui->nome->text() + "'"))
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
                    QMessageBox::critical(0, "Erro!", "Já existe um tipo de equipe com esse nome.");
                    return;
                }
                else if(!editMode)
                {
                    QMessageBox::critical(0, "Erro!", "Já existe um tipo de equipe com esse nome.");
                    return;
                }
            }
        }

        if(editMode)
        {
            if(!query.exec("UPDATE tipoequipe SET nometipoequipe = '" + ui->nome->text() + "' WHERE codtipoequipe = " + editCode))
            {
                QMessageBox::critical(0, "Erro!", query.lastError().text());
            }
        }
        else
        {
            if(!query.exec("INSERT INTO tipoequipe VALUES(DEFAULT, '" + ui->nome->text() + "')"))
            {
                QMessageBox::critical(0, "Erro!", query.lastError().text());
            }
        }
        delete this;
    }
}
