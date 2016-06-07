/********************************************************************************
** Form generated from reading UI file 'telaTorneio.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TELATORNEIO_H
#define UI_TELATORNEIO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_telaTorneio
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_2;
    QTabWidget *tabWidget;
    QGridLayout *gridLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *InserirJogo;
    QPushButton *Excluir;
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QWidget *telaTorneio)
    {
        if (telaTorneio->objectName().isEmpty())
            telaTorneio->setObjectName(QStringLiteral("telaTorneio"));
        telaTorneio->resize(597, 397);
        verticalLayout = new QVBoxLayout(telaTorneio);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        tabWidget = new QTabWidget(telaTorneio);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));

        gridLayout_2->addWidget(tabWidget, 0, 0, 1, 1);


        verticalLayout->addLayout(gridLayout_2);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        horizontalSpacer = new QSpacerItem(243, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 0, 0, 1, 1);

        InserirJogo = new QPushButton(telaTorneio);
        InserirJogo->setObjectName(QStringLiteral("InserirJogo"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(InserirJogo->sizePolicy().hasHeightForWidth());
        InserirJogo->setSizePolicy(sizePolicy);
        InserirJogo->setMinimumSize(QSize(0, 35));

        gridLayout_3->addWidget(InserirJogo, 0, 1, 1, 1);

        Excluir = new QPushButton(telaTorneio);
        Excluir->setObjectName(QStringLiteral("Excluir"));
        Excluir->setMinimumSize(QSize(0, 35));

        gridLayout_3->addWidget(Excluir, 0, 2, 1, 1);


        verticalLayout->addLayout(gridLayout_3);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButton = new QPushButton(telaTorneio);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(0, 35));

        gridLayout->addWidget(pushButton, 0, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 0, 0, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 0, 2, 1, 1);


        verticalLayout->addLayout(gridLayout);


        retranslateUi(telaTorneio);

        tabWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(telaTorneio);
    } // setupUi

    void retranslateUi(QWidget *telaTorneio)
    {
        telaTorneio->setWindowTitle(QApplication::translate("telaTorneio", "Form", 0));
        InserirJogo->setText(QApplication::translate("telaTorneio", "Inserir Jogo...", 0));
        Excluir->setText(QApplication::translate("telaTorneio", "Excluir", 0));
        pushButton->setText(QApplication::translate("telaTorneio", "Fechar", 0));
    } // retranslateUi

};

namespace Ui {
    class telaTorneio: public Ui_telaTorneio {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TELATORNEIO_H
