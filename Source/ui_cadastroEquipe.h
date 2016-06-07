/********************************************************************************
** Form generated from reading UI file 'cadastroEquipe.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CADASTROEQUIPE_H
#define UI_CADASTROEQUIPE_H

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

class Ui_cadastroEquipe
{
public:
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *SelecionarImagem;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *RemoverImagem;
    QSpacerItem *horizontalSpacer_7;
    QLabel *Pixmap;
    QSpacerItem *horizontalSpacer_8;
    QFrame *line;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QLabel *label_6;
    QLineEdit *NomeCompleto;
    QDateEdit *DataFundacao;
    QLineEdit *Nome;
    QLabel *label_3;
    QLineEdit *Pais;
    QLineEdit *Cidade;
    QPushButton *Confirmar;
    QPushButton *Cancelar;
    QSpacerItem *verticalSpacer_5;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_7;
    QLabel *label_2;
    QComboBox *Tipo;
    QLabel *label_8;
    QComboBox *EstadioRelacionado;

    void setupUi(QWidget *cadastroEquipe)
    {
        if (cadastroEquipe->objectName().isEmpty())
            cadastroEquipe->setObjectName(QStringLiteral("cadastroEquipe"));
        cadastroEquipe->resize(521, 492);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(cadastroEquipe->sizePolicy().hasHeightForWidth());
        cadastroEquipe->setSizePolicy(sizePolicy);
        gridLayout_4 = new QGridLayout(cadastroEquipe);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 5, 0, 1, 1);

        SelecionarImagem = new QPushButton(cadastroEquipe);
        SelecionarImagem->setObjectName(QStringLiteral("SelecionarImagem"));

        gridLayout->addWidget(SelecionarImagem, 5, 1, 1, 2);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 5, 3, 1, 1);

        RemoverImagem = new QPushButton(cadastroEquipe);
        RemoverImagem->setObjectName(QStringLiteral("RemoverImagem"));

        gridLayout->addWidget(RemoverImagem, 6, 1, 1, 2);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_7, 6, 0, 1, 1);

        Pixmap = new QLabel(cadastroEquipe);
        Pixmap->setObjectName(QStringLiteral("Pixmap"));
        QSizePolicy sizePolicy1(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(8);
        sizePolicy1.setHeightForWidth(Pixmap->sizePolicy().hasHeightForWidth());
        Pixmap->setSizePolicy(sizePolicy1);
        Pixmap->setStyleSheet(QStringLiteral("background-color: rgb(216, 216, 216);"));

        gridLayout->addWidget(Pixmap, 4, 0, 1, 4);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_8, 6, 3, 1, 1);


        gridLayout_4->addLayout(gridLayout, 0, 2, 1, 1);

        line = new QFrame(cadastroEquipe);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_4->addWidget(line, 0, 1, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(60, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 17, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(60, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 16, 0, 1, 1);

        label = new QLabel(cadastroEquipe);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(label, 0, 0, 1, 4);

        label_6 = new QLabel(cadastroEquipe);
        label_6->setObjectName(QStringLiteral("label_6"));
        sizePolicy2.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(label_6, 6, 0, 1, 4);

        NomeCompleto = new QLineEdit(cadastroEquipe);
        NomeCompleto->setObjectName(QStringLiteral("NomeCompleto"));
        QSizePolicy sizePolicy3(QSizePolicy::Ignored, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(NomeCompleto->sizePolicy().hasHeightForWidth());
        NomeCompleto->setSizePolicy(sizePolicy3);
        NomeCompleto->setMinimumSize(QSize(0, 25));
        NomeCompleto->setMaxLength(30);

        gridLayout_2->addWidget(NomeCompleto, 3, 0, 1, 4);

        DataFundacao = new QDateEdit(cadastroEquipe);
        DataFundacao->setObjectName(QStringLiteral("DataFundacao"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(DataFundacao->sizePolicy().hasHeightForWidth());
        DataFundacao->setSizePolicy(sizePolicy4);
        DataFundacao->setMinimumSize(QSize(0, 25));

        gridLayout_2->addWidget(DataFundacao, 5, 0, 1, 4);

        Nome = new QLineEdit(cadastroEquipe);
        Nome->setObjectName(QStringLiteral("Nome"));
        sizePolicy3.setHeightForWidth(Nome->sizePolicy().hasHeightForWidth());
        Nome->setSizePolicy(sizePolicy3);
        Nome->setMinimumSize(QSize(0, 25));
        Nome->setMaxLength(150);

        gridLayout_2->addWidget(Nome, 1, 0, 1, 4);

        label_3 = new QLabel(cadastroEquipe);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy2.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(label_3, 2, 0, 1, 4);

        Pais = new QLineEdit(cadastroEquipe);
        Pais->setObjectName(QStringLiteral("Pais"));
        sizePolicy3.setHeightForWidth(Pais->sizePolicy().hasHeightForWidth());
        Pais->setSizePolicy(sizePolicy3);
        Pais->setMinimumSize(QSize(0, 25));
        Pais->setMaxLength(30);

        gridLayout_2->addWidget(Pais, 9, 0, 1, 4);

        Cidade = new QLineEdit(cadastroEquipe);
        Cidade->setObjectName(QStringLiteral("Cidade"));
        sizePolicy3.setHeightForWidth(Cidade->sizePolicy().hasHeightForWidth());
        Cidade->setSizePolicy(sizePolicy3);
        Cidade->setMinimumSize(QSize(0, 25));
        Cidade->setMaxLength(30);

        gridLayout_2->addWidget(Cidade, 7, 0, 1, 4);

        Confirmar = new QPushButton(cadastroEquipe);
        Confirmar->setObjectName(QStringLiteral("Confirmar"));
        Confirmar->setEnabled(true);

        gridLayout_2->addWidget(Confirmar, 16, 1, 1, 2);

        Cancelar = new QPushButton(cadastroEquipe);
        Cancelar->setObjectName(QStringLiteral("Cancelar"));
        Cancelar->setEnabled(true);

        gridLayout_2->addWidget(Cancelar, 17, 1, 1, 2);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_5, 14, 0, 1, 4);

        label_5 = new QLabel(cadastroEquipe);
        label_5->setObjectName(QStringLiteral("label_5"));
        sizePolicy2.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(label_5, 4, 0, 1, 4);

        horizontalSpacer_3 = new QSpacerItem(60, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 16, 3, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(60, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 17, 3, 1, 1);

        label_7 = new QLabel(cadastroEquipe);
        label_7->setObjectName(QStringLiteral("label_7"));
        sizePolicy2.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(label_7, 8, 0, 1, 4);

        label_2 = new QLabel(cadastroEquipe);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 10, 0, 1, 4);

        Tipo = new QComboBox(cadastroEquipe);
        Tipo->setObjectName(QStringLiteral("Tipo"));
        sizePolicy3.setHeightForWidth(Tipo->sizePolicy().hasHeightForWidth());
        Tipo->setSizePolicy(sizePolicy3);
        Tipo->setMinimumSize(QSize(207, 25));
        Tipo->setIconSize(QSize(20, 20));

        gridLayout_2->addWidget(Tipo, 11, 0, 1, 4);

        label_8 = new QLabel(cadastroEquipe);
        label_8->setObjectName(QStringLiteral("label_8"));
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy5);

        gridLayout_2->addWidget(label_8, 12, 0, 1, 4);

        EstadioRelacionado = new QComboBox(cadastroEquipe);
        EstadioRelacionado->setObjectName(QStringLiteral("EstadioRelacionado"));
        sizePolicy3.setHeightForWidth(EstadioRelacionado->sizePolicy().hasHeightForWidth());
        EstadioRelacionado->setSizePolicy(sizePolicy3);
        EstadioRelacionado->setMinimumSize(QSize(207, 25));
        EstadioRelacionado->setIconSize(QSize(20, 20));

        gridLayout_2->addWidget(EstadioRelacionado, 13, 0, 1, 4);


        gridLayout_4->addLayout(gridLayout_2, 0, 0, 1, 1);

        QWidget::setTabOrder(Nome, NomeCompleto);
        QWidget::setTabOrder(NomeCompleto, DataFundacao);
        QWidget::setTabOrder(DataFundacao, Cidade);
        QWidget::setTabOrder(Cidade, Pais);
        QWidget::setTabOrder(Pais, Tipo);
        QWidget::setTabOrder(Tipo, EstadioRelacionado);
        QWidget::setTabOrder(EstadioRelacionado, Confirmar);
        QWidget::setTabOrder(Confirmar, Cancelar);
        QWidget::setTabOrder(Cancelar, SelecionarImagem);
        QWidget::setTabOrder(SelecionarImagem, RemoverImagem);

        retranslateUi(cadastroEquipe);

        QMetaObject::connectSlotsByName(cadastroEquipe);
    } // setupUi

    void retranslateUi(QWidget *cadastroEquipe)
    {
        cadastroEquipe->setWindowTitle(QApplication::translate("cadastroEquipe", "Cadastro de Equipe", 0));
        SelecionarImagem->setText(QApplication::translate("cadastroEquipe", "Selecionar Imagem...", 0));
        RemoverImagem->setText(QApplication::translate("cadastroEquipe", "Remover Imagem", 0));
        Pixmap->setText(QString());
        label->setText(QApplication::translate("cadastroEquipe", "Nome:", 0));
        label_6->setText(QApplication::translate("cadastroEquipe", "Cidade:", 0));
        label_3->setText(QApplication::translate("cadastroEquipe", "Nome Completo:", 0));
        Pais->setText(QString());
        Confirmar->setText(QApplication::translate("cadastroEquipe", "Confirmar", 0));
        Cancelar->setText(QApplication::translate("cadastroEquipe", "Cancelar", 0));
        label_5->setText(QApplication::translate("cadastroEquipe", "Data da funda\303\247\303\243o:", 0));
        label_7->setText(QApplication::translate("cadastroEquipe", "Pa\303\255s:", 0));
        label_2->setText(QApplication::translate("cadastroEquipe", "Tipo:", 0));
        Tipo->clear();
        Tipo->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("cadastroEquipe", "Gerenciar tipos...", 0)
        );
        label_8->setText(QApplication::translate("cadastroEquipe", "Est\303\241dio Relacionado:", 0));
        EstadioRelacionado->clear();
        EstadioRelacionado->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("cadastroEquipe", "Gerenciar tipos...", 0)
        );
    } // retranslateUi

};

namespace Ui {
    class cadastroEquipe: public Ui_cadastroEquipe {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CADASTROEQUIPE_H
