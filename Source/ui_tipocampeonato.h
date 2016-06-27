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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_tipoCampeonato
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QPushButton *novo_2;
    QPushButton *excluir;
    QPushButton *editar;
    QSpacerItem *horizontalSpacer;
    QPushButton *novo;
    QSpacerItem *horizontalSpacer_2;
    QTableWidget *tabela;

    void setupUi(QWidget *tipoCampeonato)
    {
        if (tipoCampeonato->objectName().isEmpty())
            tipoCampeonato->setObjectName(QStringLiteral("tipoCampeonato"));
        tipoCampeonato->resize(269, 257);
        gridLayout_2 = new QGridLayout(tipoCampeonato);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        novo_2 = new QPushButton(tipoCampeonato);
        novo_2->setObjectName(QStringLiteral("novo_2"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(novo_2->sizePolicy().hasHeightForWidth());
        novo_2->setSizePolicy(sizePolicy);
        novo_2->setMinimumSize(QSize(0, 35));

        gridLayout->addWidget(novo_2, 4, 2, 1, 1);

        excluir = new QPushButton(tipoCampeonato);
        excluir->setObjectName(QStringLiteral("excluir"));
        excluir->setEnabled(false);
        sizePolicy.setHeightForWidth(excluir->sizePolicy().hasHeightForWidth());
        excluir->setSizePolicy(sizePolicy);

        gridLayout->addWidget(excluir, 3, 3, 1, 1);

        editar = new QPushButton(tipoCampeonato);
        editar->setObjectName(QStringLiteral("editar"));
        editar->setEnabled(false);
        sizePolicy.setHeightForWidth(editar->sizePolicy().hasHeightForWidth());
        editar->setSizePolicy(sizePolicy);

        gridLayout->addWidget(editar, 3, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 3, 0, 1, 1);

        novo = new QPushButton(tipoCampeonato);
        novo->setObjectName(QStringLiteral("novo"));
        sizePolicy.setHeightForWidth(novo->sizePolicy().hasHeightForWidth());
        novo->setSizePolicy(sizePolicy);

        gridLayout->addWidget(novo, 3, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 3, 4, 1, 1);

        tabela = new QTableWidget(tipoCampeonato);
        if (tabela->columnCount() < 1)
            tabela->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tabela->setHorizontalHeaderItem(0, __qtablewidgetitem);
        tabela->setObjectName(QStringLiteral("tabela"));
        tabela->setEnabled(true);
        tabela->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tabela->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        tabela->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tabela->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);

        gridLayout->addWidget(tabela, 2, 0, 1, 5);


        gridLayout_2->addLayout(gridLayout, 0, 0, 8, 6);


        retranslateUi(tipoCampeonato);

        QMetaObject::connectSlotsByName(tipoCampeonato);
    } // setupUi

    void retranslateUi(QWidget *tipoCampeonato)
    {
        tipoCampeonato->setWindowTitle(QApplication::translate("tipoCampeonato", "Gerenciar Tipos de Campeonato", 0));
        novo_2->setText(QApplication::translate("tipoCampeonato", "Conclu\303\255do", 0));
        excluir->setText(QApplication::translate("tipoCampeonato", "Excluir", 0));
        editar->setText(QApplication::translate("tipoCampeonato", "Editar...", 0));
        novo->setText(QApplication::translate("tipoCampeonato", "Novo...", 0));
        QTableWidgetItem *___qtablewidgetitem = tabela->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("tipoCampeonato", "Nome", 0));
    } // retranslateUi

};

namespace Ui {
    class tipoCampeonato: public Ui_tipoCampeonato {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIPOCAMPEONATO_H
