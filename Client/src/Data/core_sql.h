#pragma once

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <memory>
#include <QVariant>
#include "Chat/chatid.h"
#include "config.h"
class Setting;
/**
 * @namespace db
 * @note 数据库表结构体
 */
namespace db{
    struct InfoFd{
        int idx;
        ChatId id;
        QString name;
        QString pix64;
        QList<ns::History> history;
        InfoFd(){}
        InfoFd(int idx, ChatId& id, QString& name, QString& pix64, QList<ns::History>& history) : idx(idx), id(id), name(name), pix64(pix64), history(history){}
    };
};
enum class TypeSql : uint8_t{
    LoadFd,
};

Q_DECLARE_METATYPE(db::InfoFd);

/**
 * @class CoreSql
 * @brief 数据库操作类
 * @note 把每个表的信息用结构体表示
 * @todo 完善数据库
 */
class CoreSql : public std::enable_shared_from_this<CoreSql>{
public:
    CoreSql(std::shared_ptr<Setting> setting);
    ~CoreSql();

    const std::vector<QVariant>& query(TypeSql type);

private:
    QSqlDatabase                    m_database;
    std::vector<QVariant>           m_ret; // 查询结果
    std::shared_ptr<Setting>        m_setting;
};