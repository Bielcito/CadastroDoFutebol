#ifndef INFORMACAOTEMPORADA_H
#define INFORMACAOTEMPORADA_H

#include <QWidget>

namespace Ui {
class informacaoTemporada;
}

class informacaoTemporada : public QWidget
{
    Q_OBJECT

public:
    explicit informacaoTemporada(QWidget *parent = 0);
    ~informacaoTemporada();

private:
    Ui::informacaoTemporada *ui;
};

#endif // INFORMACAOTEMPORADA_H
