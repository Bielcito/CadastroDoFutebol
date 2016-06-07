#ifndef CADASTROESTADIO_H
#define CADASTROESTADIO_H

#include <QWidget>
#include <QFileDialog>
#include <QPixmap>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <iostream>
#include <windows.h>
using std::cout;
using std::endl;

namespace Ui {
class cadastroEstadio;
}

class cadastroEstadio : public QWidget
{
    Q_OBJECT

public:
    explicit cadastroEstadio(QWidget *parent = 0);
    explicit cadastroEstadio(QString sCode, QString nome, QString nomecompleto, QString capacidade, QString cidade, QPixmap *pixmap, QString pais, QWidget *parent = 0);
    ~cadastroEstadio();

private slots:
    void on_SelecionarImg_clicked();

    void on_Confirmar_clicked();

    void on_RemoverImg_clicked();

    void on_Cancelar_clicked();

    void resizeEvent(QResizeEvent* e);

private:
    Ui::cadastroEstadio *ui;
    bool editMode;
    QString editCode;
    QString file;
    QPixmap* pixmap = NULL;
    bool imageIsChanged;
    bool doesFileExist(const wchar_t *filename);
    void setPixmap();
};

#endif // CADASTROESTADIO_H
