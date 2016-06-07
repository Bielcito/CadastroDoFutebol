#ifndef TIPOCAMPEONATOSECONDWINDOW_H
#define TIPOCAMPEONATOSECONDWINDOW_H

#include <QWidget>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>

namespace Ui {
class tipoCampeonatoSecondWindow;
}

class tipoCampeonatoSecondWindow : public QWidget
{
    Q_OBJECT

public:
    explicit tipoCampeonatoSecondWindow(QWidget *parent = 0);
    explicit tipoCampeonatoSecondWindow(QString item, QWidget *parent = 0);
    ~tipoCampeonatoSecondWindow();

private slots:

    void on_ok_clicked();

    void on_cancelar_clicked();

private:
    Ui::tipoCampeonatoSecondWindow *ui;
    QString editCode;
    bool editMode;
};

#endif // TIPOCAMPEONATOSECONDWINDOW_H
