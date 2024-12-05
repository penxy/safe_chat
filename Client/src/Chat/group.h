#pragma once

#include "chat.h"
#include "friend.h"
#include "config.h"

#include <memory>
#include <QPixmap>

class GpList;

/**
 * @class Group
 */
class Group final : public Chat, public std::enable_shared_from_this<Group>{
    Q_OBJECT 
public:
    Group() = default;
    Group(const ChatId& id, const QString& pix_base64, const QString& name);
    Group(const Group& other);
    Group& operator=(const Group& other);

    Q_PROPERTY(QString name READ getName WRITE setName NOTIFY SigNameChanged FINAL);
    Q_PROPERTY(QPixmap pix READ getPix WRITE setPix NOTIFY SigPixChanged FINAL);

    SIGNAL_IMPL(Group, SigNameChanged, const QString&);
    SIGNAL_IMPL(Group, SigPixChanged, const QPixmap&);
public:
    ChatId getId() const override;

    void setName(const QString& name) override;
    QString getName() const override;

    void setPix(const QPixmap& pix) override;
    QPixmap getPix() const override;
private:
    template <typename T> bool setVal(T& savedVal, T newVal);
private:
    ChatId                                          m_chat_id;
    QString                                         m_name;
    QPixmap                                         m_pix;
    QList<std::pair<Friend, Type::Role>>            m_members;
};