/********************************************************************************
** Form generated from reading UI file 'cadastroEstadio.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CADASTROESTADIO_H
#define UI_CADASTROESTADIO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_cadastroEstadio
{
public:
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *Confirmar;
    QLineEdit *estNomeCompleto;
    QPushButton *Cancelar;
    QLabel *label_2;
    QLineEdit *estNome;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer;
    QLineEdit *estCidade;
    QSpinBox *estCapacidade;
    QLabel *label_4;
    QLabel *label_3;
    QLabel *label_5;
    QLineEdit *estPais;
    QFrame *line;
    QGridLayout *gridLayout_3;
    QPushButton *SelecionarImg;
    QPushButton *RemoverImg;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *horizontalSpacer_8;
    QLabel *estPixmap;

    void setupUi(QWidget *cadastroEstadio)
    {
        if (cadastroEstadio->objectName().isEmpty())
            cadastroEstadio->setObjectName(QStringLiteral("cadastroEstadio"));
        cadastroEstadio->resize(619, 386);
        horizontalLayout = new QHBoxLayout(cadastroEstadio);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_4, 10, 0, 1, 3);

        horizontalSpacer_2 = new QSpacerItem(60, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 11, 2, 1, 1);

        label = new QLabel(cadastroEstadio);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(label, 0, 0, 1, 3);

        horizontalSpacer_3 = new QSpacerItem(60, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 12, 0, 1, 1);

        Confirmar = new QPushButton(cadastroEstadio);
        Confirmar->setObjectName(QStringLiteral("Confirmar"));
        Confirmar->setEnabled(true);
        sizePolicy.setHeightForWidth(Confirmar->sizePolicy().hasHeightForWidth());
        Confirmar->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(Confirmar, 11, 1, 1, 1);

        estNomeCompleto = new QLineEdit(cadastroEstadio);
        estNomeCompleto->setObjectName(QStringLiteral("estNomeCompleto"));
        QSizePolicy sizePolicy1(QSizePolicy::Ignored, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(estNomeCompleto->sizePolicy().hasHeightForWidth());
        estNomeCompleto->setSizePolicy(sizePolicy1);
        estNomeCompleto->setMinimumSize(QSize(0, 25));
        estNomeCompleto->setLayoutDirection(Qt::LeftToRight);
        estNomeCompleto->setMaxLength(200);

        gridLayout_2->addWidget(estNomeCompleto, 3, 0, 1, 3);

        Cancelar = new QPushButton(cadastroEstadio);
        Cancelar->setObjectName(QStringLiteral("Cancelar"));
        Cancelar->setEnabled(true);
        sizePolicy.setHeightForWidth(Cancelar->sizePolicy().hasHeightForWidth());
        Cancelar->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(Cancelar, 12, 1, 1, 1);

        label_2 = new QLabel(cadastroEstadio);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(label_2, 2, 0, 1, 3);

        estNome = new QLineEdit(cadastroEstadio);
        estNome->setObjectName(QStringLiteral("estNome"));
        sizePolicy1.setHeightForWidth(estNome->sizePolicy().hasHeightForWidth());
        estNome->setSizePolicy(sizePolicy1);
        estNome->setMinimumSize(QSize(0, 25));
        estNome->setLayoutDirection(Qt::LeftToRight);
        estNome->setMaxLength(50);

        gridLayout_2->addWidget(estNome, 1, 0, 1, 3);

        horizontalSpacer_4 = new QSpacerItem(60, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 12, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(60, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 11, 0, 1, 1);

        estCidade = new QLineEdit(cadastroEstadio);
        estCidade->setObjectName(QStringLiteral("estCidade"));
        sizePolicy1.setHeightForWidth(estCidade->sizePolicy().hasHeightForWidth());
        estCidade->setSizePolicy(sizePolicy1);
        estCidade->setMinimumSize(QSize(0, 25));
        estCidade->setLayoutDirection(Qt::LeftToRight);
        estCidade->setMaxLength(30);

        gridLayout_2->addWidget(estCidade, 7, 0, 1, 3);

        estCapacidade = new QSpinBox(cadastroEstadio);
        estCapacidade->setObjectName(QStringLiteral("estCapacidade"));
        sizePolicy1.setHeightForWidth(estCapacidade->sizePolicy().hasHeightForWidth());
        estCapacidade->setSizePolicy(sizePolicy1);
        estCapacidade->setMinimumSize(QSize(0, 25));
        estCapacidade->setMaximum(500000);

        gridLayout_2->addWidget(estCapacidade, 5, 0, 1, 3);

        label_4 = new QLabel(cadastroEstadio);
        label_4->setObjectName(QStringLiteral("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(label_4, 6, 0, 1, 3);

        label_3 = new QLabel(cadastroEstadio);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(label_3, 4, 0, 1, 3);

        label_5 = new QLabel(cadastroEstadio);
        label_5->setObjectName(QStringLiteral("label_5"));
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(label_5, 8, 0, 1, 3);

        estPais = new QLineEdit(cadastroEstadio);
        estPais->setObjectName(QStringLiteral("estPais"));
        sizePolicy1.setHeightForWidth(estPais->sizePolicy().hasHeightForWidth());
        estPais->setSizePolicy(sizePolicy1);
        estPais->setMinimumSize(QSize(0, 25));
        estPais->setLayoutDirection(Qt::LeftToRight);
        estPais->setMaxLength(30);

        gridLayout_2->addWidget(estPais, 9, 0, 1, 3);


        horizontalLayout->addLayout(gridLayout_2);

        line = new QFrame(cadastroEstadio);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        SelecionarImg = new QPushButton(cadastroEstadio);
        SelecionarImg->setObjectName(QStringLiteral("SelecionarImg"));

        gridLayout_3->addWidget(SelecionarImg, 3, 1, 1, 1);

        RemoverImg = new QPushButton(cadastroEstadio);
        RemoverImg->setObjectName(QStringLiteral("RemoverImg"));

        gridLayout_3->addWidget(RemoverImg, 4, 1, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_6, 4, 0, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_5, 3, 0, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_7, 3, 2, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_8, 4, 2, 1, 1);

        estPixmap = new QLabel(cadastroEstadio);
        estPixmap->setObjectName(QStringLiteral("estPixmap"));
        QSizePolicy sizePolicy2(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(estPixmap->sizePolicy().hasHeightForWidth());
        estPixmap->setSizePolicy(sizePolicy2);
        estPixmap->setStyleSheet(QStringLiteral("background-color: rgb(216, 216, 216);"));
        estPixmap->setScaledContents(true);

        gridLayout_3->addWidget(estPixmap, 2, 0, 1, 3);


        horizontalLayout->addLayout(gridLayout_3);

        QWidget::setTabOrder(estNome, estNomeCompleto);
        QWidget::setTabOrder(estNomeCompleto, estCapacidade);
        QWidget::setTabOrder(estCapacidade, estCidade);
        QWidget::setTabOrder(estCidade, estPais);
        QWidget::setTabOrder(estPais, Confirmar);
        QWidget::setTabOrder(Confirmar, Cancelar);
        QWidget::setTabOrder(Cancelar, SelecionarImg);
        QWidget::setTabOrder(SelecionarImg, RemoverImg);

        retranslateUi(cadastroEstadio);
        QObject::connect(estCidade, SIGNAL(returnPressed()), Confirmar, SLOT(click()));
        QObject::connect(estNome, SIGNAL(returnPressed()), Confirmar, SLOT(click()));
        QObject::connect(estNomeCompleto, SIGNAL(returnPressed()), Confirmar, SLOT(click()));
        QObject::connect(estPais, SIGNAL(returnPressed()), Confirmar, SLOT(click()));

        QMetaObject::connectSlotsByName(cadastroEstadio);
    } // setupUi

    void retranslateUi(QWidget *cadastroEstadio)
    {
        cadastroEstadio->setWindowTitle(QApplication::translate("cadastroEstadio", "Cadastro de Estadio", 0));
        label->setText(QApplication::translate("cadastroEstadio", "Nome do est\303\241dio:", 0));
        Confirmar->setText(QApplication::translate("cadastroEstadio", "Confirmar", 0));
        Cancelar->setText(QApplication::translate("cadastroEstadio", "Cancelar", 0));
        label_2->setText(QApplication::translate("cadastroEstadio", "Nome oficial:", 0));
        label_4->setText(QApplication::translate("cadastroEstadio", "Cidade do est\303\241dio:", 0));
        label_3->setText(QApplication::translate("cadastroEstadio", "Capacidade do est\303\241dio:", 0));
        label_5->setText(QApplication::translate("cadastroEstadio", "Pa\303\255s:", 0));
        SelecionarImg->setText(QApplication::translate("cadastroEstadio", "Selecionar Imagem...", 0));
        RemoverImg->setText(QApplication::translate("cadastroEstadio", "Remover Imagem", 0));
        estPixmap->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class cadastroEstadio: public Ui_cadastroEstadio {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CADASTROESTADIO_H
