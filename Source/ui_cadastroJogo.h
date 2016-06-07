/********************************************************************************
** Form generated from reading UI file 'cadastroJogo.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CADASTROJOGO_H
#define UI_CADASTROJOGO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_cadastroJogo
{
public:
    QGridLayout *gridLayout_12;
    QGridLayout *gridLayout_6;
    QPushButton *Confirmar;
    QPushButton *Cancelar;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QGridLayout *gridLayout_5;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_7;
    QGridLayout *gridLayout_8;
    QLabel *label_28;
    QDateTimeEdit *dateTimeEdit;
    QComboBox *ArbitroRelacionado;
    QLabel *label_27;
    QLabel *label_16;
    QSpinBox *Publico;
    QSpacerItem *verticalSpacer;
    QGridLayout *gridLayout_9;
    QLabel *label_4;
    QLabel *label_29;
    QComboBox *EstadioRelacionado;
    QLineEdit *TV;
    QSpacerItem *verticalSpacer_2;
    QWidget *tab_2;
    QGridLayout *gridLayout_11;
    QGridLayout *gridLayout_10;
    QSpinBox *EstatChuteFora;
    QSpinBox *EstatFaltaCasa;
    QLabel *label_33;
    QSpinBox *EstatFaltaFora;
    QSpinBox *EstatImpedimentoFora;
    QLabel *label_32;
    QLabel *label_35;
    QSpinBox *EstatChuteCasa;
    QSpinBox *EstatImpedimentoCasa;
    QSpinBox *EstatEscanteioCasa;
    QLabel *label_37;
    QLabel *label_34;
    QSpinBox *EstatEscanteioFora;
    QLabel *label_38;
    QLabel *label_36;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_4;
    QWidget *tab_3;
    QGridLayout *gridLayout_13;
    QLabel *label_39;
    QTextEdit *Comentarios;
    QWidget *tab_4;
    QGridLayout *gridLayout_14;
    QLabel *label;
    QGridLayout *gridLayout_4;
    QLabel *label_19;
    QLabel *label_2;
    QLabel *label_3;
    QComboBox *EquipeForaRelacionada;
    QSpinBox *GolsTimeCasaPritem;
    QSpinBox *GolsTimeCasaProrrogacao;
    QSpinBox *GolsTimeCasa;
    QSpinBox *GolsTimeCasaPenaltis;
    QCheckBox *isTempoNormal;
    QLabel *label_23;
    QCheckBox *isProrrogacao;
    QSpinBox *GolsTimeForaPenaltis;
    QSpinBox *GolsTimeForaProrrogacao;
    QSpinBox *GolsTimeFora;
    QCheckBox *isPenaltis;
    QSpinBox *GolsTimeForaPritem;
    QComboBox *EquipeCasaRelacionada;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QWidget *cadastroJogo)
    {
        if (cadastroJogo->objectName().isEmpty())
            cadastroJogo->setObjectName(QStringLiteral("cadastroJogo"));
        cadastroJogo->resize(591, 411);
        gridLayout_12 = new QGridLayout(cadastroJogo);
        gridLayout_12->setObjectName(QStringLiteral("gridLayout_12"));
        gridLayout_6 = new QGridLayout();
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        Confirmar = new QPushButton(cadastroJogo);
        Confirmar->setObjectName(QStringLiteral("Confirmar"));

        gridLayout_6->addWidget(Confirmar, 0, 1, 1, 1);

        Cancelar = new QPushButton(cadastroJogo);
        Cancelar->setObjectName(QStringLiteral("Cancelar"));

        gridLayout_6->addWidget(Cancelar, 0, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer, 0, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_2, 0, 3, 1, 1);


        gridLayout_12->addLayout(gridLayout_6, 4, 0, 1, 2);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        tabWidget = new QTabWidget(cadastroJogo);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout_7 = new QGridLayout(tab);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        gridLayout_8 = new QGridLayout();
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        label_28 = new QLabel(tab);
        label_28->setObjectName(QStringLiteral("label_28"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_28->sizePolicy().hasHeightForWidth());
        label_28->setSizePolicy(sizePolicy);

        gridLayout_8->addWidget(label_28, 2, 0, 1, 1);

        dateTimeEdit = new QDateTimeEdit(tab);
        dateTimeEdit->setObjectName(QStringLiteral("dateTimeEdit"));
        dateTimeEdit->setMinimumSize(QSize(0, 25));

        gridLayout_8->addWidget(dateTimeEdit, 1, 0, 1, 1);

        ArbitroRelacionado = new QComboBox(tab);
        ArbitroRelacionado->setObjectName(QStringLiteral("ArbitroRelacionado"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(ArbitroRelacionado->sizePolicy().hasHeightForWidth());
        ArbitroRelacionado->setSizePolicy(sizePolicy1);
        ArbitroRelacionado->setMinimumSize(QSize(0, 25));

        gridLayout_8->addWidget(ArbitroRelacionado, 3, 0, 1, 1);

        label_27 = new QLabel(tab);
        label_27->setObjectName(QStringLiteral("label_27"));
        sizePolicy.setHeightForWidth(label_27->sizePolicy().hasHeightForWidth());
        label_27->setSizePolicy(sizePolicy);

        gridLayout_8->addWidget(label_27, 0, 0, 1, 1);

        label_16 = new QLabel(tab);
        label_16->setObjectName(QStringLiteral("label_16"));
        sizePolicy.setHeightForWidth(label_16->sizePolicy().hasHeightForWidth());
        label_16->setSizePolicy(sizePolicy);

        gridLayout_8->addWidget(label_16, 4, 0, 1, 1);

        Publico = new QSpinBox(tab);
        Publico->setObjectName(QStringLiteral("Publico"));
        Publico->setMinimumSize(QSize(0, 25));
        Publico->setButtonSymbols(QAbstractSpinBox::NoButtons);

        gridLayout_8->addWidget(Publico, 5, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_8->addItem(verticalSpacer, 6, 0, 1, 1);


        gridLayout_7->addLayout(gridLayout_8, 0, 0, 1, 1);

        gridLayout_9 = new QGridLayout();
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        label_4 = new QLabel(tab);
        label_4->setObjectName(QStringLiteral("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);

        gridLayout_9->addWidget(label_4, 0, 0, 1, 1);

        label_29 = new QLabel(tab);
        label_29->setObjectName(QStringLiteral("label_29"));
        sizePolicy.setHeightForWidth(label_29->sizePolicy().hasHeightForWidth());
        label_29->setSizePolicy(sizePolicy);

        gridLayout_9->addWidget(label_29, 2, 0, 1, 1);

        EstadioRelacionado = new QComboBox(tab);
        EstadioRelacionado->setObjectName(QStringLiteral("EstadioRelacionado"));
        sizePolicy1.setHeightForWidth(EstadioRelacionado->sizePolicy().hasHeightForWidth());
        EstadioRelacionado->setSizePolicy(sizePolicy1);
        EstadioRelacionado->setMinimumSize(QSize(0, 25));

        gridLayout_9->addWidget(EstadioRelacionado, 3, 0, 1, 1);

        TV = new QLineEdit(tab);
        TV->setObjectName(QStringLiteral("TV"));
        TV->setMinimumSize(QSize(0, 25));

        gridLayout_9->addWidget(TV, 1, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_9->addItem(verticalSpacer_2, 4, 0, 1, 1);


        gridLayout_7->addLayout(gridLayout_9, 0, 1, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        gridLayout_11 = new QGridLayout(tab_2);
        gridLayout_11->setObjectName(QStringLiteral("gridLayout_11"));
        gridLayout_10 = new QGridLayout();
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        EstatChuteFora = new QSpinBox(tab_2);
        EstatChuteFora->setObjectName(QStringLiteral("EstatChuteFora"));

        gridLayout_10->addWidget(EstatChuteFora, 1, 3, 1, 1);

        EstatFaltaCasa = new QSpinBox(tab_2);
        EstatFaltaCasa->setObjectName(QStringLiteral("EstatFaltaCasa"));

        gridLayout_10->addWidget(EstatFaltaCasa, 2, 1, 1, 1);

        label_33 = new QLabel(tab_2);
        label_33->setObjectName(QStringLiteral("label_33"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_33->sizePolicy().hasHeightForWidth());
        label_33->setSizePolicy(sizePolicy2);
        label_33->setAlignment(Qt::AlignCenter);

        gridLayout_10->addWidget(label_33, 1, 2, 1, 1);

        EstatFaltaFora = new QSpinBox(tab_2);
        EstatFaltaFora->setObjectName(QStringLiteral("EstatFaltaFora"));

        gridLayout_10->addWidget(EstatFaltaFora, 2, 3, 1, 1);

        EstatImpedimentoFora = new QSpinBox(tab_2);
        EstatImpedimentoFora->setObjectName(QStringLiteral("EstatImpedimentoFora"));

        gridLayout_10->addWidget(EstatImpedimentoFora, 3, 3, 1, 1);

        label_32 = new QLabel(tab_2);
        label_32->setObjectName(QStringLiteral("label_32"));
        label_32->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_10->addWidget(label_32, 0, 1, 1, 1);

        label_35 = new QLabel(tab_2);
        label_35->setObjectName(QStringLiteral("label_35"));
        label_35->setAlignment(Qt::AlignCenter);

        gridLayout_10->addWidget(label_35, 3, 2, 1, 1);

        EstatChuteCasa = new QSpinBox(tab_2);
        EstatChuteCasa->setObjectName(QStringLiteral("EstatChuteCasa"));

        gridLayout_10->addWidget(EstatChuteCasa, 1, 1, 1, 1);

        EstatImpedimentoCasa = new QSpinBox(tab_2);
        EstatImpedimentoCasa->setObjectName(QStringLiteral("EstatImpedimentoCasa"));

        gridLayout_10->addWidget(EstatImpedimentoCasa, 3, 1, 1, 1);

        EstatEscanteioCasa = new QSpinBox(tab_2);
        EstatEscanteioCasa->setObjectName(QStringLiteral("EstatEscanteioCasa"));

        gridLayout_10->addWidget(EstatEscanteioCasa, 4, 1, 1, 1);

        label_37 = new QLabel(tab_2);
        label_37->setObjectName(QStringLiteral("label_37"));

        gridLayout_10->addWidget(label_37, 0, 3, 1, 1);

        label_34 = new QLabel(tab_2);
        label_34->setObjectName(QStringLiteral("label_34"));
        label_34->setAlignment(Qt::AlignCenter);

        gridLayout_10->addWidget(label_34, 2, 2, 1, 1);

        EstatEscanteioFora = new QSpinBox(tab_2);
        EstatEscanteioFora->setObjectName(QStringLiteral("EstatEscanteioFora"));

        gridLayout_10->addWidget(EstatEscanteioFora, 4, 3, 1, 1);

        label_38 = new QLabel(tab_2);
        label_38->setObjectName(QStringLiteral("label_38"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_38->sizePolicy().hasHeightForWidth());
        label_38->setSizePolicy(sizePolicy3);
        label_38->setMinimumSize(QSize(100, 0));
        label_38->setAlignment(Qt::AlignCenter);

        gridLayout_10->addWidget(label_38, 0, 2, 1, 1);

        label_36 = new QLabel(tab_2);
        label_36->setObjectName(QStringLiteral("label_36"));
        label_36->setAlignment(Qt::AlignCenter);

        gridLayout_10->addWidget(label_36, 4, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_10->addItem(horizontalSpacer_3, 0, 0, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_10->addItem(horizontalSpacer_4, 0, 4, 1, 1);


        gridLayout_11->addLayout(gridLayout_10, 0, 0, 4, 1);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        gridLayout_13 = new QGridLayout(tab_3);
        gridLayout_13->setObjectName(QStringLiteral("gridLayout_13"));
        label_39 = new QLabel(tab_3);
        label_39->setObjectName(QStringLiteral("label_39"));

        gridLayout_13->addWidget(label_39, 0, 0, 1, 1);

        Comentarios = new QTextEdit(tab_3);
        Comentarios->setObjectName(QStringLiteral("Comentarios"));

        gridLayout_13->addWidget(Comentarios, 1, 0, 1, 1);

        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        gridLayout_14 = new QGridLayout(tab_4);
        gridLayout_14->setObjectName(QStringLiteral("gridLayout_14"));
        label = new QLabel(tab_4);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_14->addWidget(label, 0, 0, 1, 1);

        tabWidget->addTab(tab_4, QString());

        gridLayout_5->addWidget(tabWidget, 0, 0, 1, 1);


        gridLayout_12->addLayout(gridLayout_5, 1, 0, 2, 2);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        label_19 = new QLabel(cadastroJogo);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_19, 0, 1, 1, 1);

        label_2 = new QLabel(cadastroJogo);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_2, 0, 2, 1, 1);

        label_3 = new QLabel(cadastroJogo);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_3, 0, 0, 1, 1);

        EquipeForaRelacionada = new QComboBox(cadastroJogo);
        EquipeForaRelacionada->setObjectName(QStringLiteral("EquipeForaRelacionada"));
        sizePolicy1.setHeightForWidth(EquipeForaRelacionada->sizePolicy().hasHeightForWidth());
        EquipeForaRelacionada->setSizePolicy(sizePolicy1);

        gridLayout_4->addWidget(EquipeForaRelacionada, 1, 2, 1, 1);

        GolsTimeCasaPritem = new QSpinBox(cadastroJogo);
        GolsTimeCasaPritem->setObjectName(QStringLiteral("GolsTimeCasaPritem"));
        GolsTimeCasaPritem->setEnabled(false);
        GolsTimeCasaPritem->setMaximumSize(QSize(37, 16777215));

        gridLayout_4->addWidget(GolsTimeCasaPritem, 2, 0, 1, 1, Qt::AlignRight);

        GolsTimeCasaProrrogacao = new QSpinBox(cadastroJogo);
        GolsTimeCasaProrrogacao->setObjectName(QStringLiteral("GolsTimeCasaProrrogacao"));
        GolsTimeCasaProrrogacao->setEnabled(false);
        GolsTimeCasaProrrogacao->setMaximumSize(QSize(37, 16777215));

        gridLayout_4->addWidget(GolsTimeCasaProrrogacao, 3, 0, 1, 1, Qt::AlignRight);

        GolsTimeCasa = new QSpinBox(cadastroJogo);
        GolsTimeCasa->setObjectName(QStringLiteral("GolsTimeCasa"));
        GolsTimeCasa->setMaximumSize(QSize(37, 16777215));
        GolsTimeCasa->setReadOnly(true);
        GolsTimeCasa->setButtonSymbols(QAbstractSpinBox::NoButtons);

        gridLayout_4->addWidget(GolsTimeCasa, 5, 0, 1, 1, Qt::AlignRight);

        GolsTimeCasaPenaltis = new QSpinBox(cadastroJogo);
        GolsTimeCasaPenaltis->setObjectName(QStringLiteral("GolsTimeCasaPenaltis"));
        GolsTimeCasaPenaltis->setEnabled(false);
        GolsTimeCasaPenaltis->setMaximumSize(QSize(37, 16777215));
        GolsTimeCasaPenaltis->setValue(0);

        gridLayout_4->addWidget(GolsTimeCasaPenaltis, 4, 0, 1, 1, Qt::AlignRight);

        isTempoNormal = new QCheckBox(cadastroJogo);
        isTempoNormal->setObjectName(QStringLiteral("isTempoNormal"));
        isTempoNormal->setMinimumSize(QSize(100, 0));
        isTempoNormal->setAcceptDrops(false);
        isTempoNormal->setLayoutDirection(Qt::LeftToRight);
        isTempoNormal->setCheckable(true);
        isTempoNormal->setChecked(false);

        gridLayout_4->addWidget(isTempoNormal, 2, 1, 1, 1);

        label_23 = new QLabel(cadastroJogo);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_23, 5, 1, 1, 1);

        isProrrogacao = new QCheckBox(cadastroJogo);
        isProrrogacao->setObjectName(QStringLiteral("isProrrogacao"));
        isProrrogacao->setMinimumSize(QSize(100, 0));
        isProrrogacao->setLayoutDirection(Qt::LeftToRight);
        isProrrogacao->setTristate(false);

        gridLayout_4->addWidget(isProrrogacao, 3, 1, 1, 1);

        GolsTimeForaPenaltis = new QSpinBox(cadastroJogo);
        GolsTimeForaPenaltis->setObjectName(QStringLiteral("GolsTimeForaPenaltis"));
        GolsTimeForaPenaltis->setEnabled(false);
        GolsTimeForaPenaltis->setMaximumSize(QSize(37, 16777215));

        gridLayout_4->addWidget(GolsTimeForaPenaltis, 4, 2, 1, 1);

        GolsTimeForaProrrogacao = new QSpinBox(cadastroJogo);
        GolsTimeForaProrrogacao->setObjectName(QStringLiteral("GolsTimeForaProrrogacao"));
        GolsTimeForaProrrogacao->setEnabled(false);
        GolsTimeForaProrrogacao->setMaximumSize(QSize(37, 16777215));

        gridLayout_4->addWidget(GolsTimeForaProrrogacao, 3, 2, 1, 1);

        GolsTimeFora = new QSpinBox(cadastroJogo);
        GolsTimeFora->setObjectName(QStringLiteral("GolsTimeFora"));
        GolsTimeFora->setMaximumSize(QSize(37, 16777215));
        GolsTimeFora->setReadOnly(true);
        GolsTimeFora->setButtonSymbols(QAbstractSpinBox::NoButtons);

        gridLayout_4->addWidget(GolsTimeFora, 5, 2, 1, 1);

        isPenaltis = new QCheckBox(cadastroJogo);
        isPenaltis->setObjectName(QStringLiteral("isPenaltis"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(isPenaltis->sizePolicy().hasHeightForWidth());
        isPenaltis->setSizePolicy(sizePolicy4);
        isPenaltis->setMinimumSize(QSize(100, 0));

        gridLayout_4->addWidget(isPenaltis, 4, 1, 1, 1, Qt::AlignHCenter);

        GolsTimeForaPritem = new QSpinBox(cadastroJogo);
        GolsTimeForaPritem->setObjectName(QStringLiteral("GolsTimeForaPritem"));
        GolsTimeForaPritem->setEnabled(false);
        GolsTimeForaPritem->setMaximumSize(QSize(37, 16777215));

        gridLayout_4->addWidget(GolsTimeForaPritem, 2, 2, 1, 1);

        EquipeCasaRelacionada = new QComboBox(cadastroJogo);
        EquipeCasaRelacionada->setObjectName(QStringLiteral("EquipeCasaRelacionada"));
        sizePolicy1.setHeightForWidth(EquipeCasaRelacionada->sizePolicy().hasHeightForWidth());
        EquipeCasaRelacionada->setSizePolicy(sizePolicy1);

        gridLayout_4->addWidget(EquipeCasaRelacionada, 1, 0, 1, 1);


        gridLayout_12->addLayout(gridLayout_4, 0, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_12->addItem(verticalSpacer_3, 3, 0, 1, 1);


        retranslateUi(cadastroJogo);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(cadastroJogo);
    } // setupUi

    void retranslateUi(QWidget *cadastroJogo)
    {
        cadastroJogo->setWindowTitle(QApplication::translate("cadastroJogo", "Form", 0));
        Confirmar->setText(QApplication::translate("cadastroJogo", "Confirmar", 0));
        Cancelar->setText(QApplication::translate("cadastroJogo", "Cancelar", 0));
        label_28->setText(QApplication::translate("cadastroJogo", "\303\201rbitro:", 0));
        label_27->setText(QApplication::translate("cadastroJogo", "Data e Hora do jogo:", 0));
        label_16->setText(QApplication::translate("cadastroJogo", "P\303\272blico:", 0));
        label_4->setText(QApplication::translate("cadastroJogo", "TV:", 0));
        label_29->setText(QApplication::translate("cadastroJogo", "Est\303\241dio relacionado:", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("cadastroJogo", "Geral", 0));
        label_33->setText(QApplication::translate("cadastroJogo", "Chutes a Gol", 0));
        label_32->setText(QApplication::translate("cadastroJogo", "Casa", 0));
        label_35->setText(QApplication::translate("cadastroJogo", "Impedimentos", 0));
        label_37->setText(QApplication::translate("cadastroJogo", "Fora", 0));
        label_34->setText(QApplication::translate("cadastroJogo", "Faltas", 0));
        label_38->setText(QApplication::translate("cadastroJogo", "Estat\303\255sticas", 0));
        label_36->setText(QApplication::translate("cadastroJogo", "Escanteios", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("cadastroJogo", "Estat\303\255sticas", 0));
        label_39->setText(QApplication::translate("cadastroJogo", "Coment\303\241rios:", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("cadastroJogo", "Coment\303\241rios", 0));
        label->setText(QApplication::translate("cadastroJogo", "Ainda n\303\243o implementado!", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("cadastroJogo", "Fotos", 0));
        label_19->setText(QApplication::translate("cadastroJogo", "Resultado", 0));
        label_2->setText(QApplication::translate("cadastroJogo", "Equipe Visitante", 0));
        label_3->setText(QApplication::translate("cadastroJogo", "Equipe Anfitri\303\243", 0));
        isTempoNormal->setText(QApplication::translate("cadastroJogo", "Tempo Normal", 0));
        label_23->setText(QApplication::translate("cadastroJogo", "Total", 0));
        isProrrogacao->setText(QApplication::translate("cadastroJogo", "Prorroga\303\247\303\243o", 0));
        isPenaltis->setText(QApplication::translate("cadastroJogo", "P\303\252naltis", 0));
    } // retranslateUi

};

namespace Ui {
    class cadastroJogo: public Ui_cadastroJogo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CADASTROJOGO_H
