#ifndef CADASTROARBITRO_H
#define CADASTROARBITRO_H

#include <QWidget>
#include <QTextCursor>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <iostream>
#include <QFile>
#include <QFileDialog>
#include <windows.h>
using std::cout;
using std::endl;

namespace Ui {
class cadastroArbitro;
}

class cadastroArbitro: public QWidget
{
    Q_OBJECT

public:
    explicit cadastroArbitro(QWidget *parent = 0);
    explicit cadastroArbitro(QString s0, QString s1, QString s2, QString s3, QString s4, QWidget *parent = 0);
    ~cadastroArbitro();

private slots:

    void on_Confirmar_clicked();

    void on_Cancelar_clicked();

    void on_SelecionarImg_clicked();

    void on_RemoverImg_clicked();

    void resizeEvent(QResizeEvent* e);

private:
    Ui::cadastroArbitro *ui;
    void initiateComboBox();
    bool editMode;
    QPixmap* pixmap = NULL;
    QString editCode;
    QString file;
    bool imageIsChanged;
    void setPixmap();
    bool doesFileExist(const wchar_t *filename);
};

#endif // cadastroArbitro_H
