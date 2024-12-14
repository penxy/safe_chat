#pragma once

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <memory>
#include <QVariant>
#include "Chat/chatid.h"
#include "config.h"
class CoreSetting;

/*
struct History{
    QDateTime date;
    QString content;
    ChatId id;//对方的id
    bool isSelf;//是否是自己发送的
    History(){}
    History(QDateTime& t, QString& c, ChatId& id, bool isSelf) : date(t), content(c), id(id), isSelf(isSelf) {}
};
*/
/**
 * @namespace db
 * @note 数据库表结构体
 */
namespace db{
    /**
     * @struct InfoFd
     * @brief 保存好友信息[tbl_friend]
     */
    struct InfoFd{
        ChatId id;
        QString name;
        QString pix64;
        InfoFd(){}
        InfoFd(ChatId& id, QString& name, QString& pix64) : id(id), name(name), pix64(pix64){}
    };
    /**
     * @struct InfoHistory
     * @brief 保存聊天记录[tbl_history]
     */
    struct InfoHistory{
        ChatId id;
        QDateTime date;
        QString content;
        bool isSelf;
        InfoHistory(){}
        InfoHistory(ChatId& id, QDateTime& date, QString& content, bool isSelf) : id(id), date(date), content(content), isSelf(isSelf){}
    };
};
enum class TypeSql : uint8_t{
    SelectFd,
    UpdateFd,
    InsertFd,
    DeleteFd
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
    CoreSql(std::shared_ptr<CoreSetting> setting);
    ~CoreSql();

    const std::vector<QVariant>& query(TypeSql type);

private:
    QSqlDatabase                    m_database;
    std::vector<QVariant>           m_ret; // 查询结果
    std::shared_ptr<CoreSetting>    m_setting;
};