/********************************************************************************
** Form generated from reading UI file 'tipoequipe.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIPOEQUIPE_H
#define UI_TIPOEQUIPE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_tipoequipe
{
public:
    QPushButton *concluido;
    QPushButton *excluir;
    QTableWidget *tabela;
    QPushButton *novo;
    QPushButton *editar;

    void setupUi(QWidget *tipoequipe)
    {
        if (tipoequipe->objectName().isEmpty())
            tipoequipe->setObjectName(QStringLiteral("tipoequipe"));
        tipoequipe->resize(400, 271);
        concluido = new QPushButton(tipoequipe);
        concluido->setObjectName(QStringLiteral("concluido"));
        concluido->setGeometry(QRect(240, 230, 131, 23));
        excluir = new QPushButton(tipoequipe);
        excluir->setObjectName(QStringLiteral("excluir"));
        excluir->setEnabled(false);
        excluir->setGeometry(QRect(300, 180, 75, 23));
        tabela = new QTableWidget(tipoequipe);
        if (tabela->columnCount() < 1)
            tabela->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tabela->setHorizontalHeaderItem(0, __qtablewidgetitem);
        tabela->setObjectName(QStringLiteral("tabela"));
        tabela->setGeometry(QRect(10, 10, 371, 161));
        novo = new QPushButton(tipoequipe);
        novo->setObjectName(QStringLiteral("novo"));
        novo->setGeometry(QRect(100, 180, 75, 23));
        editar = new QPushButton(tipoequipe);
        editar->setObjectName(QStringLiteral("editar"));
        editar->setEnabled(false);
        editar->setGeometry(QRect(200, 180, 75, 23));

        retranslateUi(tipoequipe);

        QMetaObject::connectSlotsByName(tipoequipe);
    } // setupUi

    void retranslateUi(QWidget *tipoequipe)
    {
        tipoequipe->setWindowTitle(QApplication::translate("tipoequipe", "Gerenciar Tipos de Equipe", 0));
        concluido->setText(QApplication::translate("tipoequipe", "Conclu\303\255do", 0));
        excluir->setText(QApplication::translate("tipoequipe", "Excluir", 0));
        QTableWidgetItem *___qtablewidgetitem = tabela->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("tipoequipe", "Nome", 0));
        novo->setText(QApplication::translate("tipoequipe", "Novo...", 0));
        editar->setText(QApplication::translate("tipoequipe", "Editar...", 0));
    } // retranslateUi

};

namespace Ui {
    class tipoequipe: public Ui_tipoequipe {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIPOEQUIPE_H
