#pragma once
#include "config.h"
#include <QList>
#include <memory>
#include <QVariant>
#include "Service/const_json.h"

#include "Chat/friend.h"
#include "utils/interface.h"


class CoreFd{
public:
    CoreFd() = default;
    ~CoreFd() = default;
    CoreFd(const CoreFd&) = default;
    CoreFd& operator=(const CoreFd&) = default;
    CoreFd(CoreFd&&) = default;
    CoreFd& operator=(CoreFd&&) = default;

    virtual bool sendFriend(TypeJson::Send type_send, std::array<QVariant, 4>args) = 0;
    virtual void recvFriend(TypeJson::Recv type_recv, std::array<QVariant, 4>args) = 0;
    
    virtual std::shared_ptr<Friend>& getFriend(int idx) = 0;
    virtual QList<std::shared_ptr<Friend>>& getFriendList() = 0;

    virtual ChatId& getFriendId(int idx) = 0;
    virtual std::string& getFriendName(int idx) = 0;
    virtual QPixmap& getFriendPhoto(int idx) = 0;

    DECLARE_SIGNAL(SigUpdateListFd);//更新好友列表
protected:
    QList<std::shared_ptr<Friend>> m_fd_list;//好友列表
};