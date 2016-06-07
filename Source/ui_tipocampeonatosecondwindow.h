/********************************************************************************
** Form generated from reading UI file 'tipocampeonatosecondwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIPOCAMPEONATOSECONDWINDOW_H
#define UI_TIPOCAMPEONATOSECONDWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_tipoCampeonatoSecondWindow
{
public:
    QLineEdit *nome;
    QLabel *label;
    QPushButton *ok;
    QPushButton *cancelar;

    void setupUi(QWidget *tipoCampeonatoSecondWindow)
    {
        if (tipoCampeonatoSecondWindow->objectName().isEmpty())
            tipoCampeonatoSecondWindow->setObjectName(QStringLiteral("tipoCampeonatoSecondWindow"));
        tipoCampeonatoSecondWindow->resize(317, 112);
        nome = new QLineEdit(tipoCampeonatoSecondWindow);
        nome->setObjectName(QStringLiteral("nome"));
        nome->setGeometry(QRect(80, 20, 201, 20));
        nome->setMaxLength(150);
        label = new QLabel(tipoCampeonatoSecondWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 20, 47, 13));
        ok = new QPushButton(tipoCampeonatoSecondWindow);
        ok->setObjectName(QStringLiteral("ok"));
        ok->setGeometry(QRect(40, 70, 75, 23));
        cancelar = new QPushButton(tipoCampeonatoSecondWindow);
        cancelar->setObjectName(QStringLiteral("cancelar"));
        cancelar->setGeometry(QRect(190, 70, 75, 23));
        QWidget::setTabOrder(nome, ok);
        QWidget::setTabOrder(ok, cancelar);

        retranslateUi(tipoCampeonatoSecondWindow);
        QObject::connect(nome, SIGNAL(returnPressed()), ok, SLOT(click()));

        QMetaObject::connectSlotsByName(tipoCampeonatoSecondWindow);
    } // setupUi

    void retranslateUi(QWidget *tipoCampeonatoSecondWindow)
    {
        tipoCampeonatoSecondWindow->setWindowTitle(QApplication::translate("tipoCampeonatoSecondWindow", "Cadastrar Tipo de Campeonato", 0));
        label->setText(QApplication::translate("tipoCampeonatoSecondWindow", "Nome:", 0));
        ok->setText(QApplication::translate("tipoCampeonatoSecondWindow", "Confirmar", 0));
        cancelar->setText(QApplication::translate("tipoCampeonatoSecondWindow", "Cancelar", 0));
    } // retranslateUi

};

namespace Ui {
    class tipoCampeonatoSecondWindow: public Ui_tipoCampeonatoSecondWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIPOCAMPEONATOSECONDWINDOW_H
