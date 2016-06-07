#include "informacaoTemporada.h"
#include "ui_informacaoTemporada.h"

informacaoTemporada::informacaoTemporada(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::informacaoTemporada)
{
    ui->setupUi(this);
}

informacaoTemporada::~informacaoTemporada()
{
    delete ui;
}
