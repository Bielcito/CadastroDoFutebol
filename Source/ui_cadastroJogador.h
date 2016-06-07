/********************************************************************************
** Form generated from reading UI file 'cadastroJogador.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CADASTROJOGADOR_H
#define UI_CADASTROJOGADOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
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

class Ui_cadastroJogador
{
public:
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout_3;
    QLabel *label_34;
    QLabel *label_33;
    QLineEdit *Apelido;
    QLabel *label_35;
    QLabel *C_9;
    QComboBox *EquipeRelacionada;
    QSpinBox *NumeroCamisa;
    QComboBox *TemporadaRelacionada;
    QPushButton *Cancelar;
    QPushButton *Confirmar;
    QLineEdit *Nome;
    QSpacerItem *horizontalSpacer_4;
    QLabel *C_8;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer_6;
    QGridLayout *gridLayout_2;
    QLineEdit *Nacionalidade;
    QDateEdit *DataNascimento;
    QLabel *C_11;
    QLabel *C_10;
    QLabel *C_12;
    QLineEdit *Status;
    QLineEdit *Email;
    QSpacerItem *verticalSpacer;
    QLabel *label_36;
    QComboBox *Posicao;
    QLabel *C_13;
    QSpacerItem *horizontalSpacer_9;
    QGridLayout *gridLayout;
    QPushButton *SelecionarImagem;
    QPushButton *RemoverImagem;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer_8;
    QLabel *Pixmap;

    void setupUi(QWidget *cadastroJogador)
    {
        if (cadastroJogador->objectName().isEmpty())
            cadastroJogador->setObjectName(QStringLiteral("cadastroJogador"));
        cadastroJogador->resize(774, 381);
        horizontalLayout = new QHBoxLayout(cadastroJogador);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label_34 = new QLabel(cadastroJogador);
        label_34->setObjectName(QStringLiteral("label_34"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_34->sizePolicy().hasHeightForWidth());
        label_34->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(label_34, 6, 0, 1, 3);

        label_33 = new QLabel(cadastroJogador);
        label_33->setObjectName(QStringLiteral("label_33"));
        sizePolicy.setHeightForWidth(label_33->sizePolicy().hasHeightForWidth());
        label_33->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(label_33, 4, 0, 1, 3);

        Apelido = new QLineEdit(cadastroJogador);
        Apelido->setObjectName(QStringLiteral("Apelido"));
        QSizePolicy sizePolicy1(QSizePolicy::Ignored, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Apelido->sizePolicy().hasHeightForWidth());
        Apelido->setSizePolicy(sizePolicy1);
        Apelido->setMinimumSize(QSize(0, 25));

        gridLayout_3->addWidget(Apelido, 5, 0, 1, 3);

        label_35 = new QLabel(cadastroJogador);
        label_35->setObjectName(QStringLiteral("label_35"));
        sizePolicy.setHeightForWidth(label_35->sizePolicy().hasHeightForWidth());
        label_35->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(label_35, 8, 0, 1, 3);

        C_9 = new QLabel(cadastroJogador);
        C_9->setObjectName(QStringLiteral("C_9"));
        sizePolicy.setHeightForWidth(C_9->sizePolicy().hasHeightForWidth());
        C_9->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(C_9, 0, 0, 1, 3);

        EquipeRelacionada = new QComboBox(cadastroJogador);
        EquipeRelacionada->setObjectName(QStringLiteral("EquipeRelacionada"));
        sizePolicy1.setHeightForWidth(EquipeRelacionada->sizePolicy().hasHeightForWidth());
        EquipeRelacionada->setSizePolicy(sizePolicy1);
        EquipeRelacionada->setMinimumSize(QSize(0, 25));

        gridLayout_3->addWidget(EquipeRelacionada, 1, 0, 1, 3);

        NumeroCamisa = new QSpinBox(cadastroJogador);
        NumeroCamisa->setObjectName(QStringLiteral("NumeroCamisa"));
        sizePolicy1.setHeightForWidth(NumeroCamisa->sizePolicy().hasHeightForWidth());
        NumeroCamisa->setSizePolicy(sizePolicy1);
        NumeroCamisa->setMinimumSize(QSize(0, 25));

        gridLayout_3->addWidget(NumeroCamisa, 9, 0, 1, 3);

        TemporadaRelacionada = new QComboBox(cadastroJogador);
        TemporadaRelacionada->setObjectName(QStringLiteral("TemporadaRelacionada"));
        sizePolicy1.setHeightForWidth(TemporadaRelacionada->sizePolicy().hasHeightForWidth());
        TemporadaRelacionada->setSizePolicy(sizePolicy1);
        TemporadaRelacionada->setMinimumSize(QSize(0, 25));

        gridLayout_3->addWidget(TemporadaRelacionada, 3, 0, 1, 3);

        Cancelar = new QPushButton(cadastroJogador);
        Cancelar->setObjectName(QStringLiteral("Cancelar"));
        Cancelar->setEnabled(true);

        gridLayout_3->addWidget(Cancelar, 16, 1, 1, 1);

        Confirmar = new QPushButton(cadastroJogador);
        Confirmar->setObjectName(QStringLiteral("Confirmar"));
        Confirmar->setEnabled(true);

        gridLayout_3->addWidget(Confirmar, 15, 1, 1, 1);

        Nome = new QLineEdit(cadastroJogador);
        Nome->setObjectName(QStringLiteral("Nome"));
        sizePolicy1.setHeightForWidth(Nome->sizePolicy().hasHeightForWidth());
        Nome->setSizePolicy(sizePolicy1);
        Nome->setMinimumSize(QSize(0, 25));

        gridLayout_3->addWidget(Nome, 7, 0, 1, 3);

        horizontalSpacer_4 = new QSpacerItem(60, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_4, 16, 2, 1, 1);

        C_8 = new QLabel(cadastroJogador);
        C_8->setObjectName(QStringLiteral("C_8"));
        sizePolicy.setHeightForWidth(C_8->sizePolicy().hasHeightForWidth());
        C_8->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(C_8, 2, 0, 1, 3);

        horizontalSpacer_2 = new QSpacerItem(60, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 16, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(60, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 15, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(60, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_3, 15, 2, 1, 1);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_6, 10, 0, 5, 3);


        horizontalLayout->addLayout(gridLayout_3);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        Nacionalidade = new QLineEdit(cadastroJogador);
        Nacionalidade->setObjectName(QStringLiteral("Nacionalidade"));
        sizePolicy1.setHeightForWidth(Nacionalidade->sizePolicy().hasHeightForWidth());
        Nacionalidade->setSizePolicy(sizePolicy1);
        Nacionalidade->setMinimumSize(QSize(0, 25));

        gridLayout_2->addWidget(Nacionalidade, 3, 0, 1, 1);

        DataNascimento = new QDateEdit(cadastroJogador);
        DataNascimento->setObjectName(QStringLiteral("DataNascimento"));
        sizePolicy1.setHeightForWidth(DataNascimento->sizePolicy().hasHeightForWidth());
        DataNascimento->setSizePolicy(sizePolicy1);
        DataNascimento->setMinimumSize(QSize(0, 25));

        gridLayout_2->addWidget(DataNascimento, 1, 0, 1, 1);

        C_11 = new QLabel(cadastroJogador);
        C_11->setObjectName(QStringLiteral("C_11"));
        sizePolicy.setHeightForWidth(C_11->sizePolicy().hasHeightForWidth());
        C_11->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(C_11, 4, 0, 1, 1);

        C_10 = new QLabel(cadastroJogador);
        C_10->setObjectName(QStringLiteral("C_10"));
        sizePolicy.setHeightForWidth(C_10->sizePolicy().hasHeightForWidth());
        C_10->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(C_10, 2, 0, 1, 1);

        C_12 = new QLabel(cadastroJogador);
        C_12->setObjectName(QStringLiteral("C_12"));
        sizePolicy.setHeightForWidth(C_12->sizePolicy().hasHeightForWidth());
        C_12->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(C_12, 6, 0, 1, 1);

        Status = new QLineEdit(cadastroJogador);
        Status->setObjectName(QStringLiteral("Status"));
        sizePolicy1.setHeightForWidth(Status->sizePolicy().hasHeightForWidth());
        Status->setSizePolicy(sizePolicy1);
        Status->setMinimumSize(QSize(0, 25));

        gridLayout_2->addWidget(Status, 7, 0, 1, 1);

        Email = new QLineEdit(cadastroJogador);
        Email->setObjectName(QStringLiteral("Email"));
        sizePolicy1.setHeightForWidth(Email->sizePolicy().hasHeightForWidth());
        Email->setSizePolicy(sizePolicy1);
        Email->setMinimumSize(QSize(0, 25));

        gridLayout_2->addWidget(Email, 9, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 10, 0, 1, 1);

        label_36 = new QLabel(cadastroJogador);
        label_36->setObjectName(QStringLiteral("label_36"));
        sizePolicy.setHeightForWidth(label_36->sizePolicy().hasHeightForWidth());
        label_36->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(label_36, 0, 0, 1, 1);

        Posicao = new QComboBox(cadastroJogador);
        Posicao->setObjectName(QStringLiteral("Posicao"));
        sizePolicy1.setHeightForWidth(Posicao->sizePolicy().hasHeightForWidth());
        Posicao->setSizePolicy(sizePolicy1);
        Posicao->setMinimumSize(QSize(0, 25));

        gridLayout_2->addWidget(Posicao, 5, 0, 1, 1);

        C_13 = new QLabel(cadastroJogador);
        C_13->setObjectName(QStringLiteral("C_13"));
        sizePolicy.setHeightForWidth(C_13->sizePolicy().hasHeightForWidth());
        C_13->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(C_13, 8, 0, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(195, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_9, 11, 0, 1, 1);


        horizontalLayout->addLayout(gridLayout_2);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        SelecionarImagem = new QPushButton(cadastroJogador);
        SelecionarImagem->setObjectName(QStringLiteral("SelecionarImagem"));

        gridLayout->addWidget(SelecionarImagem, 1, 1, 1, 1);

        RemoverImagem = new QPushButton(cadastroJogador);
        RemoverImagem->setObjectName(QStringLiteral("RemoverImagem"));

        gridLayout->addWidget(RemoverImagem, 2, 1, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 1, 0, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_7, 1, 2, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 2, 0, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_8, 2, 2, 1, 1);

        Pixmap = new QLabel(cadastroJogador);
        Pixmap->setObjectName(QStringLiteral("Pixmap"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(Pixmap->sizePolicy().hasHeightForWidth());
        Pixmap->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(Pixmap, 0, 0, 1, 3);


        horizontalLayout->addLayout(gridLayout);

#ifndef QT_NO_SHORTCUT
        label_34->setBuddy(Nome);
        label_33->setBuddy(Apelido);
        C_10->setBuddy(Nacionalidade);
        C_12->setBuddy(Status);
        C_13->setBuddy(Email);
        Pixmap->setBuddy(SelecionarImagem);
#endif // QT_NO_SHORTCUT

        retranslateUi(cadastroJogador);

        Posicao->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(cadastroJogador);
    } // setupUi

    void retranslateUi(QWidget *cadastroJogador)
    {
        cadastroJogador->setWindowTitle(QApplication::translate("cadastroJogador", "Form", 0));
        label_34->setText(QApplication::translate("cadastroJogador", "Nome:", 0));
        label_33->setText(QApplication::translate("cadastroJogador", "Apelido:", 0));
        label_35->setText(QApplication::translate("cadastroJogador", "N\303\272mero da Camisa:", 0));
        C_9->setText(QApplication::translate("cadastroJogador", "Equipe Relacionada:", 0));
        Cancelar->setText(QApplication::translate("cadastroJogador", "Cancelar", 0));
        Confirmar->setText(QApplication::translate("cadastroJogador", "Confirmar", 0));
        C_8->setText(QApplication::translate("cadastroJogador", "Temporada Relacionada:", 0));
        C_11->setText(QApplication::translate("cadastroJogador", "Posi\303\247\303\243o:", 0));
        C_10->setText(QApplication::translate("cadastroJogador", "Nacionalidade:", 0));
        C_12->setText(QApplication::translate("cadastroJogador", "Status:", 0));
        label_36->setText(QApplication::translate("cadastroJogador", "Data de Nascimento:", 0));
        Posicao->clear();
        Posicao->insertItems(0, QStringList()
         << QApplication::translate("cadastroJogador", "Zagueiro", 0)
         << QApplication::translate("cadastroJogador", "Lateral", 0)
         << QApplication::translate("cadastroJogador", "L\303\255bero", 0)
         << QApplication::translate("cadastroJogador", "Volante", 0)
         << QApplication::translate("cadastroJogador", "Ala", 0)
         << QApplication::translate("cadastroJogador", "Apoiador", 0)
         << QApplication::translate("cadastroJogador", "M\303\251dio Centro", 0)
         << QApplication::translate("cadastroJogador", "Ponta", 0)
         << QApplication::translate("cadastroJogador", "Segundo Atacante", 0)
         << QApplication::translate("cadastroJogador", "CentroAvante", 0)
        );
        C_13->setText(QApplication::translate("cadastroJogador", "Email:", 0));
        SelecionarImagem->setText(QApplication::translate("cadastroJogador", "Selecionar Imagem...", 0));
        RemoverImagem->setText(QApplication::translate("cadastroJogador", "Remover Imagem", 0));
        Pixmap->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class cadastroJogador: public Ui_cadastroJogador {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CADASTROJOGADOR_H
