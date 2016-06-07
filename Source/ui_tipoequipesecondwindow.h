/********************************************************************************
** Form generated from reading UI file 'tipoequipesecondwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIPOEQUIPESECONDWINDOW_H
#define UI_TIPOEQUIPESECONDWINDOW_H

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

class Ui_tipoequipesecondwindow
{
public:
    QPushButton *ok;
    QPushButton *cancelar;
    QLineEdit *nome;
    QLabel *label;

    void setupUi(QWidget *tipoequipesecondwindow)
    {
        if (tipoequipesecondwindow->objectName().isEmpty())
            tipoequipesecondwindow->setObjectName(QStringLiteral("tipoequipesecondwindow"));
        tipoequipesecondwindow->resize(312, 113);
        ok = new QPushButton(tipoequipesecondwindow);
        ok->setObjectName(QStringLiteral("ok"));
        ok->setGeometry(QRect(40, 70, 75, 23));
        cancelar = new QPushButton(tipoequipesecondwindow);
        cancelar->setObjectName(QStringLiteral("cancelar"));
        cancelar->setGeometry(QRect(190, 70, 75, 23));
        nome = new QLineEdit(tipoequipesecondwindow);
        nome->setObjectName(QStringLiteral("nome"));
        nome->setGeometry(QRect(80, 20, 201, 20));
        nome->setMaxLength(150);
        label = new QLabel(tipoequipesecondwindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 20, 47, 13));

        retranslateUi(tipoequipesecondwindow);
        QObject::connect(nome, SIGNAL(returnPressed()), ok, SLOT(click()));

        QMetaObject::connectSlotsByName(tipoequipesecondwindow);
    } // setupUi

    void retranslateUi(QWidget *tipoequipesecondwindow)
    {
        tipoequipesecondwindow->setWindowTitle(QApplication::translate("tipoequipesecondwindow", "Cadastrar Tipo de Equipe", 0));
        ok->setText(QApplication::translate("tipoequipesecondwindow", "Confirmar", 0));
        cancelar->setText(QApplication::translate("tipoequipesecondwindow", "Cancelar", 0));
        label->setText(QApplication::translate("tipoequipesecondwindow", "Nome:", 0));
    } // retranslateUi

};

namespace Ui {
    class tipoequipesecondwindow: public Ui_tipoequipesecondwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIPOEQUIPESECONDWINDOW_H
