#ifndef SELECIONARFASE_H
#define SELECIONARFASE_H

#include <QWidget>
#include "telaTemporada.h"
#include "telaTorneio.h"

namespace Ui {
class SelecionarFase;
}

class SelecionarFase : public QWidget
{
    Q_OBJECT

public:
    explicit SelecionarFase(QString codtemporada, QWidget *parent = 0);
    ~SelecionarFase();

private slots:
    void abrirCorrespondente();

    void on_confirmar_clicked();

    void atualizarComboBox();

private:
    Ui::SelecionarFase *ui;
    QString codtemporada;
    telaTemporada* telatemporada;
    telaTorneio* telatorneio;
    QString codfase;
};

#endif // SELECIONARFASE_H
