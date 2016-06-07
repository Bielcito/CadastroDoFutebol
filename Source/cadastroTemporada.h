#ifndef CADASTROTEMPORADA_H
#define CADASTROTEMPORADA_H

#include <QWidget>
#include <QTextCursor>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <iostream>
using std::cout;
using std::endl;

namespace Ui {
class cadastroTemporada;
}

class cadastroTemporada : public QWidget
{
    Q_OBJECT

public:
    explicit cadastroTemporada(QWidget *parent = 0);
    explicit cadastroTemporada(QString sCode,
            QString s0, QString s1, QString s2,
            QString s3, QString s4, QString s5,
            QString s6, QString s7, QString s8,
            QString s9, QString s10, QString s11,
            QString s12, QString s13, QString s14,
            QString s15,
            QWidget *parent = 0);
    ~cadastroTemporada();

private slots:

    //void on_tempDescricao_textChanged();

    void on_confirmar_clicked();

    void on_cancelar_clicked();

    void on_tempCima_clicked();

    void on_tempBaixo_clicked();

private:
    Ui::cadastroTemporada *ui;
    void initiateComboBox();
    bool editMode;
    QString editCode;
    void initiateListWidget(QString criterios);
};

#endif // CADASTROTEMPORADA_H
