#ifndef CADASTROEQUIPE_H
#define CADASTROEQUIPE_H

#include <QWidget>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QFileDialog>
#include <windows.h>
#include "tipoequipe.h"

namespace Ui {
class cadastroEquipe;
}

class cadastroEquipe : public QWidget
{
    Q_OBJECT

public:
    explicit cadastroEquipe(QWidget *parent = 0);
    explicit cadastroEquipe(QString codequipe, QString nomeequipe, QString nomecompletoequipe, QString datafundacao, QString cidade, QString pais, QString tipoequipe, QString escudo, QString estadio, QWidget *parent = 0);
    ~cadastroEquipe();

private slots:
    void on_Tipo_activated(const QString &arg1);

    void atualizarComboBox();

    void on_Confirmar_clicked();

    void on_SelecionarImagem_clicked();

    void on_RemoverImagem_clicked();

    void resizeEvent(QResizeEvent* e);

    void on_Cancelar_clicked();

private:
    Ui::cadastroEquipe *ui;
    QString editCode;
    QPixmap* pixmap = NULL;
    bool editMode;
    bool imageIsChanged;
    QString file;
    void keyPressEvent(QKeyEvent *e);
    void setPixmap();
    bool doesFileExist(const wchar_t *filename);
};

#endif // CADASTROEQUIPE_H
