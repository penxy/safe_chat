#include "core_sql.h"
#include <QDebug>
#include "Setting/setting.h"
#include "args.h"

CoreSql::CoreSql(std::shared_ptr<Setting> setting) : m_setting(setting){
    if (QSqlDatabase::contains("qt_sql_default_connection"))
    {
        m_database = QSqlDatabase::database("qt_sql_default_connection");
    }
    else
    {
        // 建立和SQlite数据库的连接
        m_database = QSqlDatabase::addDatabase("QSQLITE");
        // 设置数据库文件的名字
        QString dbPath = QString::fromStdString(FLAGS_base + m_setting->getDb().toStdString());
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

const std::vector<QVariant>& CoreSql::query(TypeSql type){
    QSqlQuery query;
    switch(type){
        case TypeSql::LoadFd:{
            QString sql = "xxx";
            query.exec(sql);
            db::InfoFd info;
            while(query.next()){
                info.idx = query.value(0).toInt();
                info.name = query.value(1).toString();
                info.id = ChatId(query.value(2).toString());
                info.pix64 = query.value(3).toString();
            }
            QString sql_msg = "xxx";
            query.exec(sql_msg);
            while(query.next()){
                //...
            }
        }   
    }
}