#include "Conexao.h"

/**
 * @brief Conexao::Conexao
 * Construtor da classe, que cria um banco de dados PostgreSQL e se conecta ao banco usando dados padrões.
 */
Conexao::Conexao(QString host, QString database, QString username, QString password)
{
    opened = true;

    db = QSqlDatabase::addDatabase("QPSQL");
    db.setPort(5432);
    db.setHostName(host);
    db.setDatabaseName(database);
    db.setUserName(username);
    db.setPassword(password);
    if (!db.open()) {
        opened = false;
    }
}

QSqlDatabase Conexao::get()
{
    return db;
}

bool Conexao::isOpened()
{
    return opened;
}

void Conexao::close()
{
    if(opened)
    {
        db.close();
    }
}
