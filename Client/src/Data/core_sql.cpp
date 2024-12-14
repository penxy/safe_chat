#include "core_sql.h"
#include <QDebug>
#include <QFile>
#include "Setting/core_setting.h"
#include "args.h"

CoreSql::CoreSql(std::shared_ptr<CoreSetting> setting) : m_setting(setting){
    if (QSqlDatabase::contains("qt_sql_default_connection")) {
        m_database = QSqlDatabase::database("qt_sql_default_connection");
    } else {
        // 建立和SQlite数据库的连接
        m_database = QSqlDatabase::addDatabase("QSQLITE");
        // 设置数据库文件的名字
        std::string db_path = FLAGS_base + m_setting->getDbName().toStdString();
        qDebug() << QString("db path %1").arg(db_path.c_str());
        m_database.setDatabaseName(db_path.c_str());
    }
    if (m_database.open()) {
        //执行.sql文件
        std::string sql_script_path = FLAGS_base + m_setting->getDbScript().toStdString();
        QFile file(sql_script_path.c_str());
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QByteArray all_data = file.readAll();
            QStringList sql_list = QString(all_data).split(";");
            QSqlQuery query;

            std::for_each(sql_list.begin(), sql_list.end() - 1, [&](QString &sql) {
                if (!query.exec(sql))
                    qDebug() << QString("sql exec failed %1, %2").arg(sql).arg(query.lastError().text());
            });
        }else{
            qDebug() << "sql script file open failed";
        }
    } else {
        qDebug() << "Database Open Failed";

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
        case TypeSql::SelectFd:{
            QString sql = "xxx";
            query.exec(sql);
            db::InfoFd info;
            while(query.next()){
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