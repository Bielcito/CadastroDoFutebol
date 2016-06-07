/********************************************************************************
** Form generated from reading UI file 'tipocampeonato.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIPOCAMPEONATO_H
#define UI_TIPOCAMPEONATO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_tipoCampeonato
{
public:
    QTableWidget *tabela;
    QPushButton *editar;
    QPushButton *excluir;
    QPushButton *novo;
    QPushButton *novo_2;

    void setupUi(QWidget *tipoCampeonato)
    {
        if (tipoCampeonato->objectName().isEmpty())
            tipoCampeonato->setObjectName(QStringLiteral("tipoCampeonato"));
        tipoCampeonato->resize(401, 272);
        tabela = new QTableWidget(tipoCampeonato);
        if (tabela->columnCount() < 1)
            tabela->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tabela->setHorizontalHeaderItem(0, __qtablewidgetitem);
        tabela->setObjectName(QStringLiteral("tabela"));
        tabela->setGeometry(QRect(10, 10, 371, 161));
        editar = new QPushButton(tipoCampeonato);
        editar->setObjectName(QStringLiteral("editar"));
        editar->setEnabled(false);
        editar->setGeometry(QRect(200, 180, 75, 23));
        excluir = new QPushButton(tipoCampeonato);
        excluir->setObjectName(QStringLiteral("excluir"));
        excluir->setEnabled(false);
        excluir->setGeometry(QRect(300, 180, 75, 23));
        novo = new QPushButton(tipoCampeonato);
        novo->setObjectName(QStringLiteral("novo"));
        novo->setGeometry(QRect(100, 180, 75, 23));
        novo_2 = new QPushButton(tipoCampeonato);
        novo_2->setObjectName(QStringLiteral("novo_2"));
        novo_2->setGeometry(QRect(240, 230, 131, 23));

        retranslateUi(tipoCampeonato);

        QMetaObject::connectSlotsByName(tipoCampeonato);
    } // setupUi

    void retranslateUi(QWidget *tipoCampeonato)
    {
        tipoCampeonato->setWindowTitle(QApplication::translate("tipoCampeonato", "Gerenciar Tipos de Campeonato", 0));
        QTableWidgetItem *___qtablewidgetitem = tabela->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("tipoCampeonato", "Nome", 0));
        editar->setText(QApplication::translate("tipoCampeonato", "Editar...", 0));
        excluir->setText(QApplication::translate("tipoCampeonato", "Excluir", 0));
        novo->setText(QApplication::translate("tipoCampeonato", "Novo...", 0));
        novo_2->setText(QApplication::translate("tipoCampeonato", "Conclu\303\255do", 0));
    } // retranslateUi

};

namespace Ui {
    class tipoCampeonato: public Ui_tipoCampeonato {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIPOCAMPEONATO_H
