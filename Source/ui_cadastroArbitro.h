/********************************************************************************
** Form generated from reading UI file 'cadastroArbitro.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CADASTROARBITRO_H
#define UI_CADASTROARBITRO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_cadastroArbitro
{
public:
    QGridLayout *gridLayout;
    QGridLayout *gridLayout_2;
    QPushButton *Confirmar;
    QPushButton *Cancelar;
    QComboBox *comboBox;
    QLabel *label_3;
    QDateEdit *dateEdit;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QSpacerItem *verticalSpacer;
    QGridLayout *gridLayout_3;
    QPushButton *RemoverImg;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *SelecionarImg;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *horizontalSpacer_8;
    QLabel *pixmap;
    QFrame *line;

    void setupUi(QWidget *cadastroArbitro)
    {
        if (cadastroArbitro->objectName().isEmpty())
            cadastroArbitro->setObjectName(QStringLiteral("cadastroArbitro"));
        cadastroArbitro->resize(536, 311);
        gridLayout = new QGridLayout(cadastroArbitro);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        Confirmar = new QPushButton(cadastroArbitro);
        Confirmar->setObjectName(QStringLiteral("Confirmar"));
        Confirmar->setEnabled(true);

        gridLayout_2->addWidget(Confirmar, 8, 1, 1, 1);

        Cancelar = new QPushButton(cadastroArbitro);
        Cancelar->setObjectName(QStringLiteral("Cancelar"));
        Cancelar->setEnabled(true);

        gridLayout_2->addWidget(Cancelar, 9, 1, 1, 1);

        comboBox = new QComboBox(cadastroArbitro);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(comboBox, 1, 0, 1, 3);

        label_3 = new QLabel(cadastroArbitro);
        label_3->setObjectName(QStringLiteral("label_3"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(label_3, 4, 0, 1, 3);

        dateEdit = new QDateEdit(cadastroArbitro);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        sizePolicy.setHeightForWidth(dateEdit->sizePolicy().hasHeightForWidth());
        dateEdit->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(dateEdit, 5, 0, 1, 3);

        horizontalSpacer_2 = new QSpacerItem(60, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 9, 0, 1, 1);

        label = new QLabel(cadastroArbitro);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(label, 0, 0, 1, 3);

        horizontalSpacer = new QSpacerItem(60, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 8, 0, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(60, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 9, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(60, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 8, 2, 1, 1);

        label_2 = new QLabel(cadastroArbitro);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(label_2, 2, 0, 1, 3);

        lineEdit = new QLineEdit(cadastroArbitro);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        sizePolicy.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(lineEdit, 3, 0, 1, 3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 6, 0, 1, 3);


        gridLayout->addLayout(gridLayout_2, 0, 0, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        RemoverImg = new QPushButton(cadastroArbitro);
        RemoverImg->setObjectName(QStringLiteral("RemoverImg"));

        gridLayout_3->addWidget(RemoverImg, 2, 1, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_5, 1, 0, 1, 1);

        SelecionarImg = new QPushButton(cadastroArbitro);
        SelecionarImg->setObjectName(QStringLiteral("SelecionarImg"));

        gridLayout_3->addWidget(SelecionarImg, 1, 1, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_6, 2, 0, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_7, 1, 2, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_8, 2, 2, 1, 1);

        pixmap = new QLabel(cadastroArbitro);
        pixmap->setObjectName(QStringLiteral("pixmap"));
        QSizePolicy sizePolicy2(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pixmap->sizePolicy().hasHeightForWidth());
        pixmap->setSizePolicy(sizePolicy2);

        gridLayout_3->addWidget(pixmap, 0, 0, 1, 3);


        gridLayout->addLayout(gridLayout_3, 0, 2, 1, 1);

        line = new QFrame(cadastroArbitro);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 0, 1, 1, 1);


        retranslateUi(cadastroArbitro);
        QObject::connect(lineEdit, SIGNAL(returnPressed()), Confirmar, SLOT(click()));

        QMetaObject::connectSlotsByName(cadastroArbitro);
    } // setupUi

    void retranslateUi(QWidget *cadastroArbitro)
    {
        cadastroArbitro->setWindowTitle(QApplication::translate("cadastroArbitro", "Form", 0));
        Confirmar->setText(QApplication::translate("cadastroArbitro", "Confirmar", 0));
        Cancelar->setText(QApplication::translate("cadastroArbitro", "Cancelar", 0));
        label_3->setText(QApplication::translate("cadastroArbitro", "Data de Nascimento:", 0));
        label->setText(QApplication::translate("cadastroArbitro", "Temporada Relacionada:", 0));
        label_2->setText(QApplication::translate("cadastroArbitro", "Nome:", 0));
        RemoverImg->setText(QApplication::translate("cadastroArbitro", "Remover Imagem", 0));
        SelecionarImg->setText(QApplication::translate("cadastroArbitro", "Selecionar Imagem...", 0));
        pixmap->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class cadastroArbitro: public Ui_cadastroArbitro {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CADASTROARBITRO_H
