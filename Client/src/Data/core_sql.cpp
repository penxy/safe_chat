#include "core_sql.h"
#include <QDebug>
#include "args.h"

CoreSql::CoreSql(){
    if (QSqlDatabase::contains("qt_sql_default_connection"))
    {
        m_database = QSqlDatabase::database("qt_sql_default_connection");
    }
    else
    {
        // 建立和SQlite数据库的连接
        m_database = QSqlDatabase::addDatabase("QSQLITE");
        // 设置数据库文件的名字
        QString dbPath = QString::fromStdString(FLAGS_base + std::string("/release/main.db"));
        m_database.setDatabaseName(dbPath);
    }

    if (!m_database.open())
    {
        qDebug() << "Error: Failed to connect database." << m_database.lastError();
    }
    else
    {
        qDebug() << "Database Opened";
        // QString sql2 = QString("insert into student (id,name,age) values (%1,'%2',%3)").arg(2).arg("Wang").arg(25);
        // m_query.exec(sql2);

        // m_query.exec("SELECT * FROM student");
        // while(m_query.next())
        // {
        //     int id = m_query.value(0).toInt();
        //     QString name = m_query.value(1).toString();
        //     int age = m_query.value(2).toInt();
        //     qDebug()<<QString("id:%1    name:%2    age:%3").arg(id).arg(name).arg(age);
        // }
    }
}
CoreSql::~CoreSql(){
    m_database.close();
}

