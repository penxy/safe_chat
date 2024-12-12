#pragma once

#include "chat.h"

#include <memory>
#include <QPixmap>

/**
 * @class Friend
 */
class Friend final : public Chat, public std::enable_shared_from_this<Friend>{
    Q_OBJECT 
public:
    Friend();
    Friend(const ChatId& id, const QString& pix_base64, const QString& name);
    Friend(const Friend& other);
    Friend& operator=(const Friend& other);

    Q_PROPERTY(QString name READ getName WRITE setName NOTIFY SigNameChanged FINAL);
    Q_PROPERTY(QPixmap pix READ getPix WRITE setPix NOTIFY SigPixChanged FINAL);

    SIGNAL_IMPL(Friend, SigNameChanged, const QString&);
    SIGNAL_IMPL(Friend, SigPixChanged, const QPixmap&);
public:
    ChatId& getId() override;

    void setName(const QString& name) override;
    QString& getName() override;

    void setPix(const QPixmap& pix) override;
    QPixmap& getPix() override;

    void setHistory(const QList<ns::History>& history) override;
    QList<ns::History>& getHistory() override;
private:
    template <typename T> bool setVal(T& savedVal, T newVal);
private:
    ChatId                              m_chat_id;
    QString                             m_name;
    QPixmap                             m_pix;
    QList<ns::History>                  m_history;    //历史记录
};