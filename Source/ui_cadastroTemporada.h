/********************************************************************************
** Form generated from reading UI file 'cadastroTemporada.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CADASTROTEMPORADA_H
#define UI_CADASTROTEMPORADA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_cadastroTemporada
{
public:
    QComboBox *campeonatoRelacionado;
    QLabel *label;
    QLineEdit *tempNomeLabel;
    QLabel *label_2;
    QLabel *label_9;
    QPushButton *confirmar;
    QPushButton *cancelar;
    QTextEdit *tempDescricao;
    QGroupBox *groupBox;
    QLabel *label_3;
    QSpinBox *tempPontosVitoria;
    QLabel *label_4;
    QSpinBox *tempPontosEmpate;
    QGroupBox *groupBox_2;
    QSpinBox *tempPontosVitoriaProrrogacao;
    QLabel *label_5;
    QSpinBox *tempPontosEmpateProrrogacao;
    QLabel *label_12;
    QSpinBox *tempPontosDerrotaProrrogacao;
    QLabel *label_7;
    QGroupBox *groupBox_3;
    QSpinBox *tempPontosVitoriaPenaltis;
    QLabel *label_6;
    QSpinBox *tempPontosDerrotaPenaltis;
    QLabel *label_8;
    QGroupBox *groupBox_4;
    QSpinBox *tempNumTimesRebaixamento;
    QSpinBox *tempNumCompet1;
    QLabel *label_16;
    QLabel *label_15;
    QLabel *label_14;
    QSpinBox *tempNumCompet2;
    QSpinBox *tempNumTimesRebaixados;
    QLabel *label_10;
    QPushButton *tempBaixo;
    QLabel *label_13;
    QListWidget *tempCriteriosDesempate;
    QPushButton *tempCima;
    QSpinBox *tempNumTimesPromovidos;
    QLabel *label_11;
    QFrame *line;

    void setupUi(QWidget *cadastroTemporada)
    {
        if (cadastroTemporada->objectName().isEmpty())
            cadastroTemporada->setObjectName(QStringLiteral("cadastroTemporada"));
        cadastroTemporada->resize(642, 521);
        campeonatoRelacionado = new QComboBox(cadastroTemporada);
        campeonatoRelacionado->setObjectName(QStringLiteral("campeonatoRelacionado"));
        campeonatoRelacionado->setGeometry(QRect(20, 30, 151, 22));
        label = new QLabel(cadastroTemporada);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 10, 151, 16));
        tempNomeLabel = new QLineEdit(cadastroTemporada);
        tempNomeLabel->setObjectName(QStringLiteral("tempNomeLabel"));
        tempNomeLabel->setGeometry(QRect(230, 30, 151, 20));
        tempNomeLabel->setMaxLength(150);
        label_2 = new QLabel(cadastroTemporada);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(230, 10, 151, 16));
        label_9 = new QLabel(cadastroTemporada);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(230, 360, 151, 16));
        confirmar = new QPushButton(cadastroTemporada);
        confirmar->setObjectName(QStringLiteral("confirmar"));
        confirmar->setEnabled(true);
        confirmar->setGeometry(QRect(420, 470, 70, 30));
        cancelar = new QPushButton(cadastroTemporada);
        cancelar->setObjectName(QStringLiteral("cancelar"));
        cancelar->setEnabled(true);
        cancelar->setGeometry(QRect(520, 470, 70, 30));
        tempDescricao = new QTextEdit(cadastroTemporada);
        tempDescricao->setObjectName(QStringLiteral("tempDescricao"));
        tempDescricao->setGeometry(QRect(230, 380, 371, 71));
        groupBox = new QGroupBox(cadastroTemporada);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 60, 201, 121));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 20, 151, 16));
        tempPontosVitoria = new QSpinBox(groupBox);
        tempPontosVitoria->setObjectName(QStringLiteral("tempPontosVitoria"));
        tempPontosVitoria->setGeometry(QRect(10, 40, 41, 22));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 70, 151, 16));
        tempPontosEmpate = new QSpinBox(groupBox);
        tempPontosEmpate->setObjectName(QStringLiteral("tempPontosEmpate"));
        tempPontosEmpate->setGeometry(QRect(10, 90, 41, 22));
        groupBox_2 = new QGroupBox(cadastroTemporada);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(20, 190, 201, 171));
        tempPontosVitoriaProrrogacao = new QSpinBox(groupBox_2);
        tempPontosVitoriaProrrogacao->setObjectName(QStringLiteral("tempPontosVitoriaProrrogacao"));
        tempPontosVitoriaProrrogacao->setGeometry(QRect(10, 40, 41, 22));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 20, 161, 16));
        tempPontosEmpateProrrogacao = new QSpinBox(groupBox_2);
        tempPontosEmpateProrrogacao->setObjectName(QStringLiteral("tempPontosEmpateProrrogacao"));
        tempPontosEmpateProrrogacao->setGeometry(QRect(10, 90, 41, 22));
        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(10, 70, 171, 16));
        tempPontosDerrotaProrrogacao = new QSpinBox(groupBox_2);
        tempPontosDerrotaProrrogacao->setObjectName(QStringLiteral("tempPontosDerrotaProrrogacao"));
        tempPontosDerrotaProrrogacao->setGeometry(QRect(10, 140, 41, 22));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 120, 171, 16));
        groupBox_3 = new QGroupBox(cadastroTemporada);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(20, 370, 201, 121));
        tempPontosVitoriaPenaltis = new QSpinBox(groupBox_3);
        tempPontosVitoriaPenaltis->setObjectName(QStringLiteral("tempPontosVitoriaPenaltis"));
        tempPontosVitoriaPenaltis->setGeometry(QRect(10, 40, 41, 22));
        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 20, 151, 16));
        tempPontosDerrotaPenaltis = new QSpinBox(groupBox_3);
        tempPontosDerrotaPenaltis->setObjectName(QStringLiteral("tempPontosDerrotaPenaltis"));
        tempPontosDerrotaPenaltis->setGeometry(QRect(10, 90, 41, 22));
        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 70, 171, 16));
        groupBox_4 = new QGroupBox(cadastroTemporada);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(230, 60, 391, 271));
        tempNumTimesRebaixamento = new QSpinBox(groupBox_4);
        tempNumTimesRebaixamento->setObjectName(QStringLiteral("tempNumTimesRebaixamento"));
        tempNumTimesRebaixamento->setGeometry(QRect(10, 190, 41, 22));
        tempNumCompet1 = new QSpinBox(groupBox_4);
        tempNumCompet1->setObjectName(QStringLiteral("tempNumCompet1"));
        tempNumCompet1->setGeometry(QRect(10, 90, 41, 22));
        label_16 = new QLabel(groupBox_4);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(10, 170, 191, 16));
        label_15 = new QLabel(groupBox_4);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setEnabled(false);
        label_15->setGeometry(QRect(10, 120, 191, 16));
        label_14 = new QLabel(groupBox_4);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(10, 70, 191, 16));
        tempNumCompet2 = new QSpinBox(groupBox_4);
        tempNumCompet2->setObjectName(QStringLiteral("tempNumCompet2"));
        tempNumCompet2->setEnabled(false);
        tempNumCompet2->setGeometry(QRect(10, 140, 41, 22));
        tempNumTimesRebaixados = new QSpinBox(groupBox_4);
        tempNumTimesRebaixados->setObjectName(QStringLiteral("tempNumTimesRebaixados"));
        tempNumTimesRebaixados->setGeometry(QRect(10, 240, 41, 22));
        label_10 = new QLabel(groupBox_4);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(10, 220, 161, 16));
        tempBaixo = new QPushButton(groupBox_4);
        tempBaixo->setObjectName(QStringLiteral("tempBaixo"));
        tempBaixo->setGeometry(QRect(230, 210, 143, 23));
        label_13 = new QLabel(groupBox_4);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(231, 20, 151, 16));
        tempCriteriosDesempate = new QListWidget(groupBox_4);
        tempCriteriosDesempate->setObjectName(QStringLiteral("tempCriteriosDesempate"));
        tempCriteriosDesempate->setGeometry(QRect(231, 41, 141, 151));
        tempCima = new QPushButton(groupBox_4);
        tempCima->setObjectName(QStringLiteral("tempCima"));
        tempCima->setGeometry(QRect(230, 190, 143, 23));
        tempNumTimesPromovidos = new QSpinBox(groupBox_4);
        tempNumTimesPromovidos->setObjectName(QStringLiteral("tempNumTimesPromovidos"));
        tempNumTimesPromovidos->setGeometry(QRect(10, 40, 41, 22));
        label_11 = new QLabel(groupBox_4);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(10, 20, 161, 16));
        line = new QFrame(groupBox_4);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(200, 30, 20, 211));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        QWidget::setTabOrder(campeonatoRelacionado, tempNomeLabel);
        QWidget::setTabOrder(tempNomeLabel, tempPontosVitoria);
        QWidget::setTabOrder(tempPontosVitoria, tempPontosEmpate);
        QWidget::setTabOrder(tempPontosEmpate, tempPontosVitoriaProrrogacao);
        QWidget::setTabOrder(tempPontosVitoriaProrrogacao, tempPontosDerrotaProrrogacao);
        QWidget::setTabOrder(tempPontosDerrotaProrrogacao, tempPontosDerrotaPenaltis);
        QWidget::setTabOrder(tempPontosDerrotaPenaltis, tempNumTimesRebaixados);
        QWidget::setTabOrder(tempNumTimesRebaixados, tempNumTimesPromovidos);
        QWidget::setTabOrder(tempNumTimesPromovidos, tempPontosEmpateProrrogacao);
        QWidget::setTabOrder(tempPontosEmpateProrrogacao, tempNumCompet1);
        QWidget::setTabOrder(tempNumCompet1, tempNumCompet2);
        QWidget::setTabOrder(tempNumCompet2, tempNumTimesRebaixamento);
        QWidget::setTabOrder(tempNumTimesRebaixamento, tempDescricao);
        QWidget::setTabOrder(tempDescricao, confirmar);
        QWidget::setTabOrder(confirmar, cancelar);

        retranslateUi(cadastroTemporada);

        QMetaObject::connectSlotsByName(cadastroTemporada);
    } // setupUi

    void retranslateUi(QWidget *cadastroTemporada)
    {
        cadastroTemporada->setWindowTitle(QApplication::translate("cadastroTemporada", "Cadastro de Temporada", 0));
        label->setText(QApplication::translate("cadastroTemporada", "Campeonato relacionado:", 0));
        label_2->setText(QApplication::translate("cadastroTemporada", "Nome da temporada:", 0));
        label_9->setText(QApplication::translate("cadastroTemporada", "F\303\263rmula de disputa:", 0));
        confirmar->setText(QApplication::translate("cadastroTemporada", "Confirmar", 0));
        cancelar->setText(QApplication::translate("cadastroTemporada", "Cancelar", 0));
        groupBox->setTitle(QApplication::translate("cadastroTemporada", "Tempo normal:", 0));
        label_3->setText(QApplication::translate("cadastroTemporada", "Pontos por vit\303\263ria:", 0));
        label_4->setText(QApplication::translate("cadastroTemporada", "Pontos por empate:", 0));
        groupBox_2->setTitle(QApplication::translate("cadastroTemporada", "Prorroga\303\247\303\243o:", 0));
        label_5->setText(QApplication::translate("cadastroTemporada", "Pontos de vit\303\263ria na prorroga\303\247\303\243o:", 0));
        label_12->setText(QApplication::translate("cadastroTemporada", "Pontos de empate em prorroga\303\247\303\243o:", 0));
        label_7->setText(QApplication::translate("cadastroTemporada", "Pontos de derrota na prorroga\303\247\303\243o:", 0));
        groupBox_3->setTitle(QApplication::translate("cadastroTemporada", "P\303\252naltis", 0));
        label_6->setText(QApplication::translate("cadastroTemporada", "Pontos de vit\303\263ria nos p\303\252naltis:", 0));
        label_8->setText(QApplication::translate("cadastroTemporada", "Pontos de derrota nos p\303\252naltis:", 0));
        groupBox_4->setTitle(QApplication::translate("cadastroTemporada", "Tabela de Classifica\303\247\303\243o:", 0));
        label_16->setText(QApplication::translate("cadastroTemporada", "N\302\272 de Equipes Play-Off Rebaixamento:", 0));
        label_15->setText(QApplication::translate("cadastroTemporada", "N\302\272 de Equipes Competi\303\247\303\243o 2:", 0));
        label_14->setText(QApplication::translate("cadastroTemporada", "N\302\272 de Equipes Competi\303\247\303\243o 1:", 0));
        label_10->setText(QApplication::translate("cadastroTemporada", "N\302\272 de Equipes Rebaixadas:", 0));
        tempBaixo->setText(QApplication::translate("cadastroTemporada", "\342\206\223 ", 0));
        label_13->setText(QApplication::translate("cadastroTemporada", "Crit\303\251rios de desempate:", 0));
        tempCima->setText(QApplication::translate("cadastroTemporada", "\342\206\221 ", 0));
        label_11->setText(QApplication::translate("cadastroTemporada", "N\302\272 de Equipes Promovidas:", 0));
    } // retranslateUi

};

namespace Ui {
    class cadastroTemporada: public Ui_cadastroTemporada {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CADASTROTEMPORADA_H
