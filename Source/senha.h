#ifndef SENHA_H
#define SENHA_H

#include <QWidget>

class MainWindow;

namespace Ui {
class Senha;
}

class Senha : public QWidget
{
    Q_OBJECT

public:
    explicit Senha(MainWindow* pai, QWidget *parent = 0);
    ~Senha();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Senha *ui;
    MainWindow* pai;
};

#endif // SENHA_H
