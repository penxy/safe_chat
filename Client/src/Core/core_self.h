 #pragma once

#include "config.h"
#include "Chat/chatid.h"

/**
 * @class CoreSelf
 * @brief 个人信息保存与修改
 */
class CoreSelf{
public:
    CoreSelf() = default;
    virtual ~CoreSelf() = default;
    CoreSelf(const CoreSelf&) = default;
    CoreSelf& operator=(const CoreSelf&) = default;
    CoreSelf(CoreSelf&&) = default;
    CoreSelf& operator=(CoreSelf&&) = default;

    virtual bool setPass(const QString& pass) = 0;
    virtual bool setName(const QString& name) = 0;
    virtual bool setStatus(const Type::Status& status) = 0;
    
    virtual ChatId& getId() = 0;
    virtual QString& getName() = 0;
    virtual Type::Status& getStatus() = 0;
    virtual QString& getPublicKey() = 0;
protected:
    ChatId m_id;
    QString m_name;
    QString m_pass;
    Type::Status m_status;
    QString m_publicKey;
};