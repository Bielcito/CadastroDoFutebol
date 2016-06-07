/********************************************************************************
** Form generated from reading UI file 'senha.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SENHA_H
#define UI_SENHA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Senha
{
public:
    QGridLayout *gridLayout_3;
    QSpacerItem *verticalSpacer_2;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit;
    QLabel *label;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *Senha)
    {
        if (Senha->objectName().isEmpty())
            Senha->setObjectName(QStringLiteral("Senha"));
        Senha->resize(256, 102);
        QIcon icon;
        icon.addFile(QStringLiteral("../../../../../Downloads/favicon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        Senha->setWindowIcon(icon);
        gridLayout_3 = new QGridLayout(Senha);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_2, 2, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        lineEdit = new QLineEdit(Senha);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setMinimumSize(QSize(0, 0));
        lineEdit->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(lineEdit, 4, 0, 1, 1);

        label = new QLabel(Senha);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        pushButton = new QPushButton(Senha);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout_2->addWidget(pushButton, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 0, 2, 1, 1);


        gridLayout->addLayout(gridLayout_2, 6, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout, 1, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer, 0, 0, 1, 1);


        retranslateUi(Senha);
        QObject::connect(lineEdit, SIGNAL(returnPressed()), pushButton, SLOT(click()));

        QMetaObject::connectSlotsByName(Senha);
    } // setupUi

    void retranslateUi(QWidget *Senha)
    {
        Senha->setWindowTitle(QApplication::translate("Senha", "Bem vindo!", 0));
        lineEdit->setText(QString());
        label->setText(QApplication::translate("Senha", "Insira a senha de instala\303\247\303\243o do usu\303\241rio postgres:", 0));
        pushButton->setText(QApplication::translate("Senha", "Confirmar", 0));
    } // retranslateUi

};

namespace Ui {
    class Senha: public Ui_Senha {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SENHA_H
