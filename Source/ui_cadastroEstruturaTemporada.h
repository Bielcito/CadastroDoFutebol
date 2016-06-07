/********************************************************************************
** Form generated from reading UI file 'cadastroEstruturaTemporada.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CADASTROESTRUTURATEMPORADA_H
#define UI_CADASTROESTRUTURATEMPORADA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_cadastroEstruturaTemporada
{
public:
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_11;
    QPushButton *cancelar;
    QSpacerItem *horizontalSpacer;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_16;
    QListWidget *fases;
    QPushButton *incluirFase;
    QPushButton *alterarFase;
    QPushButton *excluirFase;
    QCheckBox *checkBox;
    QLineEdit *nomeFase;
    QLabel *label;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_15;
    QListWidget *rodadas;
    QPushButton *adicionarRodada;
    QPushButton *diminuirRodada;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_14;
    QPushButton *excluirGrupo;
    QListWidget *grupos;
    QPushButton *alterarGrupo;
    QPushButton *incluirGrupo;
    QLineEdit *nomeGrupo;
    QLabel *label_2;

    void setupUi(QWidget *cadastroEstruturaTemporada)
    {
        if (cadastroEstruturaTemporada->objectName().isEmpty())
            cadastroEstruturaTemporada->setObjectName(QStringLiteral("cadastroEstruturaTemporada"));
        cadastroEstruturaTemporada->resize(771, 343);
        gridLayout_3 = new QGridLayout(cadastroEstruturaTemporada);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_11 = new QGridLayout();
        gridLayout_11->setObjectName(QStringLiteral("gridLayout_11"));
        cancelar = new QPushButton(cadastroEstruturaTemporada);
        cancelar->setObjectName(QStringLiteral("cancelar"));
        cancelar->setEnabled(true);
        cancelar->setMinimumSize(QSize(0, 30));

        gridLayout_11->addWidget(cancelar, 2, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_11->addItem(horizontalSpacer, 2, 1, 1, 1);

        groupBox = new QGroupBox(cadastroEstruturaTemporada);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_16 = new QGridLayout(groupBox);
        gridLayout_16->setObjectName(QStringLiteral("gridLayout_16"));
        fases = new QListWidget(groupBox);
        fases->setObjectName(QStringLiteral("fases"));

        gridLayout_16->addWidget(fases, 0, 0, 1, 4);

        incluirFase = new QPushButton(groupBox);
        incluirFase->setObjectName(QStringLiteral("incluirFase"));
        incluirFase->setEnabled(false);
        incluirFase->setMinimumSize(QSize(0, 30));

        gridLayout_16->addWidget(incluirFase, 1, 0, 1, 2);

        alterarFase = new QPushButton(groupBox);
        alterarFase->setObjectName(QStringLiteral("alterarFase"));
        alterarFase->setEnabled(false);
        alterarFase->setMinimumSize(QSize(0, 30));

        gridLayout_16->addWidget(alterarFase, 1, 2, 1, 1);

        excluirFase = new QPushButton(groupBox);
        excluirFase->setObjectName(QStringLiteral("excluirFase"));
        excluirFase->setEnabled(false);
        excluirFase->setMinimumSize(QSize(0, 30));

        gridLayout_16->addWidget(excluirFase, 1, 3, 1, 1);

        checkBox = new QCheckBox(groupBox);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setEnabled(false);

        gridLayout_16->addWidget(checkBox, 3, 0, 1, 4);

        nomeFase = new QLineEdit(groupBox);
        nomeFase->setObjectName(QStringLiteral("nomeFase"));
        nomeFase->setMinimumSize(QSize(0, 25));

        gridLayout_16->addWidget(nomeFase, 2, 2, 1, 2);

        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_16->addWidget(label, 2, 0, 1, 2);


        gridLayout_11->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_3 = new QGroupBox(cadastroEstruturaTemporada);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        gridLayout_15 = new QGridLayout(groupBox_3);
        gridLayout_15->setObjectName(QStringLiteral("gridLayout_15"));
        rodadas = new QListWidget(groupBox_3);
        new QListWidgetItem(rodadas);
        rodadas->setObjectName(QStringLiteral("rodadas"));
        rodadas->setEnabled(false);

        gridLayout_15->addWidget(rodadas, 0, 0, 1, 2);

        adicionarRodada = new QPushButton(groupBox_3);
        adicionarRodada->setObjectName(QStringLiteral("adicionarRodada"));
        adicionarRodada->setEnabled(false);
        adicionarRodada->setMinimumSize(QSize(0, 30));

        gridLayout_15->addWidget(adicionarRodada, 1, 0, 1, 1);

        diminuirRodada = new QPushButton(groupBox_3);
        diminuirRodada->setObjectName(QStringLiteral("diminuirRodada"));
        diminuirRodada->setEnabled(false);
        diminuirRodada->setMinimumSize(QSize(0, 30));

        gridLayout_15->addWidget(diminuirRodada, 1, 1, 1, 1);


        gridLayout_11->addWidget(groupBox_3, 0, 4, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_11->addItem(horizontalSpacer_2, 2, 3, 1, 1);

        groupBox_2 = new QGroupBox(cadastroEstruturaTemporada);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout_14 = new QGridLayout(groupBox_2);
        gridLayout_14->setObjectName(QStringLiteral("gridLayout_14"));
        excluirGrupo = new QPushButton(groupBox_2);
        excluirGrupo->setObjectName(QStringLiteral("excluirGrupo"));
        excluirGrupo->setEnabled(false);
        excluirGrupo->setMinimumSize(QSize(0, 30));

        gridLayout_14->addWidget(excluirGrupo, 1, 4, 1, 1);

        grupos = new QListWidget(groupBox_2);
        new QListWidgetItem(grupos);
        grupos->setObjectName(QStringLiteral("grupos"));
        grupos->setEnabled(false);

        gridLayout_14->addWidget(grupos, 0, 0, 1, 5);

        alterarGrupo = new QPushButton(groupBox_2);
        alterarGrupo->setObjectName(QStringLiteral("alterarGrupo"));
        alterarGrupo->setEnabled(false);
        alterarGrupo->setMinimumSize(QSize(0, 30));

        gridLayout_14->addWidget(alterarGrupo, 1, 3, 1, 1);

        incluirGrupo = new QPushButton(groupBox_2);
        incluirGrupo->setObjectName(QStringLiteral("incluirGrupo"));
        incluirGrupo->setEnabled(false);
        incluirGrupo->setMinimumSize(QSize(0, 30));

        gridLayout_14->addWidget(incluirGrupo, 1, 0, 1, 3);

        nomeGrupo = new QLineEdit(groupBox_2);
        nomeGrupo->setObjectName(QStringLiteral("nomeGrupo"));
        nomeGrupo->setEnabled(false);
        nomeGrupo->setMinimumSize(QSize(0, 25));

        gridLayout_14->addWidget(nomeGrupo, 2, 3, 1, 2);

        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_14->addWidget(label_2, 2, 0, 1, 3);


        gridLayout_11->addWidget(groupBox_2, 0, 1, 1, 3);


        gridLayout_3->addLayout(gridLayout_11, 0, 0, 1, 1);


        retranslateUi(cadastroEstruturaTemporada);

        QMetaObject::connectSlotsByName(cadastroEstruturaTemporada);
    } // setupUi

    void retranslateUi(QWidget *cadastroEstruturaTemporada)
    {
        cadastroEstruturaTemporada->setWindowTitle(QApplication::translate("cadastroEstruturaTemporada", "Form", 0));
        cancelar->setText(QApplication::translate("cadastroEstruturaTemporada", "Fechar", 0));
        groupBox->setTitle(QApplication::translate("cadastroEstruturaTemporada", "Fases", 0));
        incluirFase->setText(QApplication::translate("cadastroEstruturaTemporada", "Incluir", 0));
        alterarFase->setText(QApplication::translate("cadastroEstruturaTemporada", "Alterar", 0));
        excluirFase->setText(QApplication::translate("cadastroEstruturaTemporada", "Excluir", 0));
        checkBox->setText(QApplication::translate("cadastroEstruturaTemporada", "Fase de Elimina\303\247\303\243o", 0));
        label->setText(QApplication::translate("cadastroEstruturaTemporada", "Nome:", 0));
        groupBox_3->setTitle(QApplication::translate("cadastroEstruturaTemporada", "Rodadas", 0));

        const bool __sortingEnabled = rodadas->isSortingEnabled();
        rodadas->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = rodadas->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("cadastroEstruturaTemporada", "Selecione um Grupo", 0));
        rodadas->setSortingEnabled(__sortingEnabled);

        adicionarRodada->setText(QApplication::translate("cadastroEstruturaTemporada", "Adicionar", 0));
        diminuirRodada->setText(QApplication::translate("cadastroEstruturaTemporada", "Diminuir", 0));
        groupBox_2->setTitle(QApplication::translate("cadastroEstruturaTemporada", "Grupos", 0));
        excluirGrupo->setText(QApplication::translate("cadastroEstruturaTemporada", "Excluir", 0));

        const bool __sortingEnabled1 = grupos->isSortingEnabled();
        grupos->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem1 = grupos->item(0);
        ___qlistwidgetitem1->setText(QApplication::translate("cadastroEstruturaTemporada", "Selecione uma Fase", 0));
        grupos->setSortingEnabled(__sortingEnabled1);

        alterarGrupo->setText(QApplication::translate("cadastroEstruturaTemporada", "Alterar", 0));
        incluirGrupo->setText(QApplication::translate("cadastroEstruturaTemporada", "Incluir", 0));
        label_2->setText(QApplication::translate("cadastroEstruturaTemporada", "Nome:", 0));
    } // retranslateUi

};

namespace Ui {
    class cadastroEstruturaTemporada: public Ui_cadastroEstruturaTemporada {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CADASTROESTRUTURATEMPORADA_H
