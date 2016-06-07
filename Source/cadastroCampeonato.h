#ifndef CADASTROCAMPEONATO_H
#define CADASTROCAMPEONATO_H

#include <QWidget>
#include <QLabel>
#include <iostream>
#include <QFileDialog>
#include <tipocampeonato.h>
using std::cout;
using std::endl;

class MainWindow;

namespace Ui {
class cadastroCampeonato;
}

class cadastroCampeonato : public QWidget
{
    Q_OBJECT

public:
    explicit cadastroCampeonato(QWidget *parent = 0);
    explicit cadastroCampeonato(QString editCode, QString tipo, QString nome, QString pais, QPixmap* pixmap, QWidget *parent = 0);
    ~cadastroCampeonato();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_comboBox_activated(const QString &arg1);

    void atualizarComboBox();

    void resizeEvent(QResizeEvent* e);

private:
    Ui::cadastroCampeonato *ui;
    QPixmap* pixmap = NULL;
    QString file;
    bool imageIsChanged;
    bool imageIsRemoved;
    bool editMode;
    QString editCode;
    void setPixmap();
};

#endif // CADASTROCAMPEONATO_H
