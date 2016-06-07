#include "tipocampeonatosecondwindow.h"
#include "ui_tipocampeonatosecondwindow.h"

tipoCampeonatoSecondWindow::tipoCampeonatoSecondWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tipoCampeonatoSecondWindow)
{
    ui->setupUi(this);

    setWindowModality(Qt::ApplicationModal);
    editMode = false;
    ui->nome->setFocus();
}

tipoCampeonatoSecondWindow::tipoCampeonatoSecondWindow(QString item, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tipoCampeonatoSecondWindow)
{
    ui->setupUi(this);

    setWindowModality(Qt::ApplicationModal);
    editMode = true;

    // Achando o valor do editCode:
    QSqlQuery query;
    query.exec("SELECT codtipocampeonato FROM tipocampeonato WHERE nometipocampeonato = '" + item + "'");
    query.next();
    editCode = query.value(0).toString();

    //Inicializando o campo com o valor do item:
    ui->nome->setText(item);
    ui->nome->setFocus();
}

tipoCampeonatoSecondWindow::~tipoCampeonatoSecondWindow()
{
    delete ui;
}

void tipoCampeonatoSecondWindow::on_ok_clicked()
{
    if(ui->nome->text().size() == 0)
    {
        QMessageBox::critical(0, "Erro!", "Por favor, preencha o campo nome para continuar.");
    }
    else
    {
        QSqlQuery query;

        //Testa para ver se o nome já existe:
        if(!query.exec("SELECT * FROM tipocampeonato WHERE nometipocampeonato = '" + ui->nome->text() + "'"))
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
                    QMessageBox::critical(0, "Erro!", "Já existe um tipo de campeonato com esse nome.");
                    return;
                }
                else if(!editMode)
                {
                    QMessageBox::critical(0, "Erro!", "Já existe um tipo de campeonato com esse nome.");
                    return;
                }
            }
        }

        if(editMode)
        {
            if(!query.exec("UPDATE tipocampeonato SET nometipocampeonato = '" + ui->nome->text() + "' WHERE codtipocampeonato = " + editCode))
            {
                QMessageBox::critical(0, "Erro!", query.lastError().text());
            }
        }
        else
        {
            if(!query.exec("INSERT INTO tipocampeonato VALUES(DEFAULT, '" + ui->nome->text() + "')"))
            {
                QMessageBox::critical(0, "Erro!", query.lastError().text());
            }
        }
        delete this;
    }
}

void tipoCampeonatoSecondWindow::on_cancelar_clicked()
{
    delete this;
}
