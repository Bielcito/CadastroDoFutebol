/********************************************************************************
** Form generated from reading UI file 'cadastroCampeonato.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CADASTROCAMPEONATO_H
#define UI_CADASTROCAMPEONATO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_cadastroCampeonato
{
public:
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout_2;
    QComboBox *comboBox;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit_3;
    QSpacerItem *verticalSpacer_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_8;
    QLabel *label_3;
    QPushButton *pushButton_3;
    QFrame *line;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton;
    QPushButton *pushButton_4;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_4;

    void setupUi(QWidget *cadastroCampeonato)
    {
        if (cadastroCampeonato->objectName().isEmpty())
            cadastroCampeonato->setObjectName(QStringLiteral("cadastroCampeonato"));
        cadastroCampeonato->resize(505, 381);
        QIcon icon;
        icon.addFile(QStringLiteral("../../../../../Downloads/favicon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        cadastroCampeonato->setWindowIcon(icon);
        horizontalLayout = new QHBoxLayout(cadastroCampeonato);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        comboBox = new QComboBox(cadastroCampeonato);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy);
        comboBox->setMinimumSize(QSize(0, 25));
        comboBox->setIconSize(QSize(20, 20));

        gridLayout_2->addWidget(comboBox, 1, 0, 1, 3);

        horizontalSpacer_7 = new QSpacerItem(60, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_7, 13, 0, 1, 1);

        pushButton_2 = new QPushButton(cadastroCampeonato);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(pushButton_2, 13, 1, 1, 1);

        lineEdit_3 = new QLineEdit(cadastroCampeonato);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        sizePolicy.setHeightForWidth(lineEdit_3->sizePolicy().hasHeightForWidth());
        lineEdit_3->setSizePolicy(sizePolicy);
        lineEdit_3->setMinimumSize(QSize(0, 25));
        lineEdit_3->setMaxLength(150);

        gridLayout_2->addWidget(lineEdit_3, 6, 0, 1, 3);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 8, 0, 2, 3);

        label = new QLabel(cadastroCampeonato);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(label, 2, 0, 1, 3);

        horizontalSpacer_2 = new QSpacerItem(60, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 14, 2, 1, 1);

        label_2 = new QLabel(cadastroCampeonato);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy2.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(label_2, 0, 0, 1, 3);

        lineEdit = new QLineEdit(cadastroCampeonato);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        sizePolicy.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy);
        lineEdit->setMinimumSize(QSize(0, 25));
        lineEdit->setMaxLength(150);

        gridLayout_2->addWidget(lineEdit, 3, 0, 1, 3);

        horizontalSpacer = new QSpacerItem(60, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 14, 0, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(60, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_8, 13, 2, 1, 1);

        label_3 = new QLabel(cadastroCampeonato);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy2.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(label_3, 5, 0, 1, 3);

        pushButton_3 = new QPushButton(cadastroCampeonato);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setEnabled(true);
        sizePolicy1.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(pushButton_3, 14, 1, 1, 1);


        horizontalLayout->addLayout(gridLayout_2);

        line = new QFrame(cadastroCampeonato);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 1, 0, 1, 1);

        pushButton = new QPushButton(cadastroCampeonato);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(pushButton, 1, 1, 1, 1);

        pushButton_4 = new QPushButton(cadastroCampeonato);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        gridLayout->addWidget(pushButton_4, 2, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 1, 2, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 2, 2, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 2, 0, 1, 1);

        label_4 = new QLabel(cadastroCampeonato);
        label_4->setObjectName(QStringLiteral("label_4"));
        QSizePolicy sizePolicy4(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy4.setHorizontalStretch(10);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy4);
        label_4->setStyleSheet(QStringLiteral("background-color: rgb(216, 216, 216);"));

        gridLayout->addWidget(label_4, 0, 0, 1, 3);


        horizontalLayout->addLayout(gridLayout);

        QWidget::setTabOrder(comboBox, lineEdit);
        QWidget::setTabOrder(lineEdit, lineEdit_3);
        QWidget::setTabOrder(lineEdit_3, pushButton_2);
        QWidget::setTabOrder(pushButton_2, pushButton_3);
        QWidget::setTabOrder(pushButton_3, pushButton);
        QWidget::setTabOrder(pushButton, pushButton_4);

        retranslateUi(cadastroCampeonato);
        QObject::connect(pushButton_3, SIGNAL(clicked()), cadastroCampeonato, SLOT(close()));
        QObject::connect(lineEdit_3, SIGNAL(returnPressed()), pushButton_2, SLOT(click()));
        QObject::connect(lineEdit, SIGNAL(returnPressed()), pushButton_2, SLOT(click()));

        QMetaObject::connectSlotsByName(cadastroCampeonato);
    } // setupUi

    void retranslateUi(QWidget *cadastroCampeonato)
    {
        cadastroCampeonato->setWindowTitle(QApplication::translate("cadastroCampeonato", "Cadastro de Campeonato", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("cadastroCampeonato", "Gerenciar tipos...", 0)
        );
        pushButton_2->setText(QApplication::translate("cadastroCampeonato", "Confirmar", 0));
        label->setText(QApplication::translate("cadastroCampeonato", "Nome:", 0));
        label_2->setText(QApplication::translate("cadastroCampeonato", "Tipo:", 0));
        lineEdit->setText(QString());
        label_3->setText(QApplication::translate("cadastroCampeonato", "Pa\303\255s:", 0));
        pushButton_3->setText(QApplication::translate("cadastroCampeonato", "Cancelar", 0));
        pushButton->setText(QApplication::translate("cadastroCampeonato", "Selecionar Imagem...", 0));
        pushButton_4->setText(QApplication::translate("cadastroCampeonato", "Remover Imagem", 0));
        label_4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class cadastroCampeonato: public Ui_cadastroCampeonato {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CADASTROCAMPEONATO_H
