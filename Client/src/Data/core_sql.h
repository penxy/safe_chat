#pragma once

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

/**
 * @class CoreSql
 * @brief 数据库操作类
 * @note 把每个表的信息用结构体表示
 * @todo 完善数据库
 */
class CoreSql{
public:
    CoreSql();
    ~CoreSql();
private:
    QSqlDatabase m_database;
    QSqlQuery m_query;
};