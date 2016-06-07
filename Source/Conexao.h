#ifndef CONEXAO_H
#define CONEXAO_H

#include <iostream>
using std::cout;
using std::endl;

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QMessageBox>
#include <QtSql/QSqlError>
#include <QVariant>

/**
 * @brief The Conexao class
 * Esta classe cria um QSqlDatabase diretamente em seu construtor, realizando uma
 * conexão direta com o banco de dados do PostgreSQL a partir do construtor da classe.
 */

class Conexao
{
    public:
        Conexao(QString host, QString database, QString username, QString password);
        QSqlDatabase get();
        bool isOpened();
        void close();

    private:
        QSqlDatabase db;
        bool opened;
};

#endif // CONEXAO_H
