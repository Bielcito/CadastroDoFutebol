#include "senha.h"
#include "mainwindow.h"
#include "ui_senha.h"

Senha::Senha(MainWindow* pai, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Senha)
{
    ui->setupUi(this);
    this->pai = pai;
}

Senha::~Senha()
{
    delete ui;
}

void Senha::on_pushButton_clicked()
{
    if(ui->lineEdit->text().isEmpty())
    {
        QMessageBox::critical(0, "Erro!", "Por favor, digite a senha.");
        return;
    }
    this->hide();
    pai->setSenha(ui->lineEdit->text());
    delete this;
}
