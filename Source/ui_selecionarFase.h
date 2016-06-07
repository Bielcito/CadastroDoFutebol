/********************************************************************************
** Form generated from reading UI file 'selecionarFase.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECIONARFASE_H
#define UI_SELECIONARFASE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SelecionarFase
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QComboBox *comboBox;
    QPushButton *confirmar;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QWidget *SelecionarFase)
    {
        if (SelecionarFase->objectName().isEmpty())
            SelecionarFase->setObjectName(QStringLiteral("SelecionarFase"));
        SelecionarFase->resize(197, 113);
        gridLayout_2 = new QGridLayout(SelecionarFase);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 3, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 3, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 0, 2, 1, 1);

        comboBox = new QComboBox(SelecionarFase);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setMinimumSize(QSize(165, 20));

        gridLayout->addWidget(comboBox, 2, 1, 1, 3);

        confirmar = new QPushButton(SelecionarFase);
        confirmar->setObjectName(QStringLiteral("confirmar"));
        confirmar->setEnabled(false);

        gridLayout->addWidget(confirmar, 4, 2, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 1, 4, 1, 1);

        label = new QLabel(SelecionarFase);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 1, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 1, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 5, 2, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(SelecionarFase);

        QMetaObject::connectSlotsByName(SelecionarFase);
    } // setupUi

    void retranslateUi(QWidget *SelecionarFase)
    {
        SelecionarFase->setWindowTitle(QApplication::translate("SelecionarFase", "Form", 0));
        confirmar->setText(QApplication::translate("SelecionarFase", "Confirmar", 0));
        label->setText(QApplication::translate("SelecionarFase", "Selecione uma fase:", 0));
    } // retranslateUi

};

namespace Ui {
    class SelecionarFase: public Ui_SelecionarFase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECIONARFASE_H
