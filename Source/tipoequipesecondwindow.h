#ifndef TIPOEQUIPESECONDWINDOW_H
#define TIPOEQUIPESECONDWINDOW_H

#include <QWidget>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>

namespace Ui {
class tipoequipesecondwindow;
}

class tipoequipesecondwindow : public QWidget
{
    Q_OBJECT

public:
    explicit tipoequipesecondwindow(QWidget *parent = 0);
    explicit tipoequipesecondwindow(QString item, QWidget *parent = 0);
    ~tipoequipesecondwindow();

private slots:
    void on_ok_clicked();

private:
    Ui::tipoequipesecondwindow *ui;
    bool editMode;
    QString editCode;
};

#endif // TIPOEQUIPESECONDWINDOW_H
