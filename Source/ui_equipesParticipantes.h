/********************************************************************************
** Form generated from reading UI file 'equipesParticipantes.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EQUIPESPARTICIPANTES_H
#define UI_EQUIPESPARTICIPANTES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_equipesParticipantes
{
public:
    QTableWidget *tableWidgetEquipes;
    QPushButton *seta;
    QPushButton *confirmar;
    QTableWidget *tableWidgetParticipantes;
    QPushButton *cancelar;
    QPushButton *remover;
    QLabel *label;
    QLabel *equipesRestantes;

    void setupUi(QWidget *equipesParticipantes)
    {
        if (equipesParticipantes->objectName().isEmpty())
            equipesParticipantes->setObjectName(QStringLiteral("equipesParticipantes"));
        equipesParticipantes->resize(721, 422);
        tableWidgetEquipes = new QTableWidget(equipesParticipantes);
        if (tableWidgetEquipes->columnCount() < 3)
            tableWidgetEquipes->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidgetEquipes->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidgetEquipes->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidgetEquipes->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableWidgetEquipes->setObjectName(QStringLiteral("tableWidgetEquipes"));
        tableWidgetEquipes->setGeometry(QRect(10, 50, 311, 261));
        tableWidgetEquipes->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidgetEquipes->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidgetEquipes->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidgetEquipes->horizontalHeader()->setVisible(true);
        tableWidgetEquipes->verticalHeader()->setVisible(false);
        seta = new QPushButton(equipesParticipantes);
        seta->setObjectName(QStringLiteral("seta"));
        seta->setEnabled(false);
        seta->setGeometry(QRect(330, 160, 61, 51));
        confirmar = new QPushButton(equipesParticipantes);
        confirmar->setObjectName(QStringLiteral("confirmar"));
        confirmar->setGeometry(QRect(560, 380, 71, 31));
        tableWidgetParticipantes = new QTableWidget(equipesParticipantes);
        if (tableWidgetParticipantes->columnCount() < 3)
            tableWidgetParticipantes->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidgetParticipantes->setHorizontalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidgetParticipantes->setHorizontalHeaderItem(1, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidgetParticipantes->setHorizontalHeaderItem(2, __qtablewidgetitem5);
        tableWidgetParticipantes->setObjectName(QStringLiteral("tableWidgetParticipantes"));
        tableWidgetParticipantes->setGeometry(QRect(400, 50, 311, 261));
        tableWidgetParticipantes->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidgetParticipantes->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidgetParticipantes->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidgetParticipantes->horizontalHeader()->setVisible(true);
        tableWidgetParticipantes->verticalHeader()->setVisible(false);
        cancelar = new QPushButton(equipesParticipantes);
        cancelar->setObjectName(QStringLiteral("cancelar"));
        cancelar->setGeometry(QRect(640, 380, 71, 31));
        remover = new QPushButton(equipesParticipantes);
        remover->setObjectName(QStringLiteral("remover"));
        remover->setEnabled(false);
        remover->setGeometry(QRect(640, 320, 71, 25));
        label = new QLabel(equipesParticipantes);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(410, 320, 101, 16));
        equipesRestantes = new QLabel(equipesParticipantes);
        equipesRestantes->setObjectName(QStringLiteral("equipesRestantes"));
        equipesRestantes->setGeometry(QRect(530, 320, 101, 16));

        retranslateUi(equipesParticipantes);

        QMetaObject::connectSlotsByName(equipesParticipantes);
    } // setupUi

    void retranslateUi(QWidget *equipesParticipantes)
    {
        equipesParticipantes->setWindowTitle(QApplication::translate("equipesParticipantes", "Form", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidgetEquipes->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("equipesParticipantes", "ID", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidgetEquipes->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("equipesParticipantes", "Equipe", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidgetEquipes->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("equipesParticipantes", "Tipo", 0));
        seta->setText(QApplication::translate("equipesParticipantes", ">>", 0));
        confirmar->setText(QApplication::translate("equipesParticipantes", "Confirmar", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidgetParticipantes->horizontalHeaderItem(0);
        ___qtablewidgetitem3->setText(QApplication::translate("equipesParticipantes", "ID", 0));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidgetParticipantes->horizontalHeaderItem(1);
        ___qtablewidgetitem4->setText(QApplication::translate("equipesParticipantes", "Equipe", 0));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidgetParticipantes->horizontalHeaderItem(2);
        ___qtablewidgetitem5->setText(QApplication::translate("equipesParticipantes", "Tipo", 0));
        cancelar->setText(QApplication::translate("equipesParticipantes", "Cancelar", 0));
        remover->setText(QApplication::translate("equipesParticipantes", "Remover", 0));
        label->setText(QApplication::translate("equipesParticipantes", "Equipes restantes:", 0));
        equipesRestantes->setText(QApplication::translate("equipesParticipantes", "<html><head/><body><p align=\"right\"><br/></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class equipesParticipantes: public Ui_equipesParticipantes {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EQUIPESPARTICIPANTES_H
