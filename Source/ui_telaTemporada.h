/********************************************************************************
** Form generated from reading UI file 'telaTemporada.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TELATEMPORADA_H
#define UI_TELATEMPORADA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_telaTemporada
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_2;
    QComboBox *grupo;
    QLabel *label_3;
    QComboBox *rodada;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_4;
    QTableWidget *tableWidget;
    QLineEdit *pesquisa;
    QLabel *label_2;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *Alterar;
    QPushButton *Excluir;
    QPushButton *Incluir;
    QPushButton *MostrarTabela;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QGridLayout *gridLayout_4;
    QPushButton *Fechar;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_6;

    void setupUi(QWidget *telaTemporada)
    {
        if (telaTemporada->objectName().isEmpty())
            telaTemporada->setObjectName(QStringLiteral("telaTemporada"));
        telaTemporada->resize(690, 426);
        verticalLayout = new QVBoxLayout(telaTemporada);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        grupo = new QComboBox(telaTemporada);
        grupo->setObjectName(QStringLiteral("grupo"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(grupo->sizePolicy().hasHeightForWidth());
        grupo->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(grupo, 1, 0, 1, 1);

        label_3 = new QLabel(telaTemporada);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_3, 0, 0, 1, 1);

        rodada = new QComboBox(telaTemporada);
        rodada->setObjectName(QStringLiteral("rodada"));

        gridLayout_2->addWidget(rodada, 1, 1, 1, 1);

        label_4 = new QLabel(telaTemporada);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_4, 0, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 1, 2, 1, 1);

        tableWidget = new QTableWidget(telaTemporada);
        if (tableWidget->columnCount() < 6)
            tableWidget->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setTextAlignment(Qt::AlignCenter);
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setTextAlignment(Qt::AlignCenter);
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setTextAlignment(Qt::AlignCenter);
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setTextAlignment(Qt::AlignCenter);
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setTextAlignment(Qt::AlignCenter);
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setTextAlignment(Qt::AlignCenter);
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget->horizontalHeader()->setVisible(false);
        tableWidget->verticalHeader()->setVisible(false);

        gridLayout_2->addWidget(tableWidget, 3, 0, 1, 3);

        pesquisa = new QLineEdit(telaTemporada);
        pesquisa->setObjectName(QStringLiteral("pesquisa"));

        gridLayout_2->addWidget(pesquisa, 2, 2, 1, 1);

        label_2 = new QLabel(telaTemporada);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 2, 0, 1, 2);


        verticalLayout->addLayout(gridLayout_2);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 0, 3, 1, 1);

        Alterar = new QPushButton(telaTemporada);
        Alterar->setObjectName(QStringLiteral("Alterar"));
        Alterar->setEnabled(false);
        Alterar->setMinimumSize(QSize(0, 35));

        gridLayout->addWidget(Alterar, 0, 1, 1, 1);

        Excluir = new QPushButton(telaTemporada);
        Excluir->setObjectName(QStringLiteral("Excluir"));
        Excluir->setEnabled(false);
        Excluir->setMinimumSize(QSize(0, 35));

        gridLayout->addWidget(Excluir, 0, 2, 1, 1);

        Incluir = new QPushButton(telaTemporada);
        Incluir->setObjectName(QStringLiteral("Incluir"));
        Incluir->setEnabled(false);
        Incluir->setMinimumSize(QSize(0, 35));

        gridLayout->addWidget(Incluir, 0, 0, 1, 1);

        MostrarTabela = new QPushButton(telaTemporada);
        MostrarTabela->setObjectName(QStringLiteral("MostrarTabela"));
        MostrarTabela->setEnabled(true);
        MostrarTabela->setMinimumSize(QSize(0, 35));

        gridLayout->addWidget(MostrarTabela, 0, 6, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 4, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 5, 1, 1);


        verticalLayout->addLayout(gridLayout);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        Fechar = new QPushButton(telaTemporada);
        Fechar->setObjectName(QStringLiteral("Fechar"));
        Fechar->setMinimumSize(QSize(0, 35));

        gridLayout_4->addWidget(Fechar, 0, 1, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_5, 0, 0, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_6, 0, 2, 1, 1);


        verticalLayout->addLayout(gridLayout_4);


        retranslateUi(telaTemporada);

        QMetaObject::connectSlotsByName(telaTemporada);
    } // setupUi

    void retranslateUi(QWidget *telaTemporada)
    {
        telaTemporada->setWindowTitle(QApplication::translate("telaTemporada", "Form", 0));
        label_3->setText(QApplication::translate("telaTemporada", "Selecione um grupo:", 0));
        label_4->setText(QApplication::translate("telaTemporada", "Selecione uma rodada:", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("telaTemporada", "Data", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("telaTemporada", "Time Casa", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("telaTemporada", "G", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("telaTemporada", "X", 0));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("telaTemporada", "G", 0));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("telaTemporada", "Time Fora", 0));
        pesquisa->setText(QString());
        pesquisa->setPlaceholderText(QApplication::translate("telaTemporada", "Pesquisa por Time", 0));
        label_2->setText(QApplication::translate("telaTemporada", "Tabela de jogos para a fase, o grupo e a rodada selecionados:", 0));
        Alterar->setText(QApplication::translate("telaTemporada", "Alterar...", 0));
        Excluir->setText(QApplication::translate("telaTemporada", "Excluir", 0));
        Incluir->setText(QApplication::translate("telaTemporada", "Incluir...", 0));
        MostrarTabela->setText(QApplication::translate("telaTemporada", "Mostrar tabela de classifica\303\247\303\243o...", 0));
        Fechar->setText(QApplication::translate("telaTemporada", "Fechar", 0));
    } // retranslateUi

};

namespace Ui {
    class telaTemporada: public Ui_telaTemporada {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TELATEMPORADA_H
