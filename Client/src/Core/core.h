#pragma once

#include "core_fd.h"
#include "core_gp.h"
#include "core_self.h"
#include "core_recore.h"
#include "Service/protocol.h"
#include "utils/interface.h"

#include <semaphore.h>
#include <QPixmap>
#include <QObject>

class Protocol;
class GpList;
class FdList;

/**
 * @class Core
 * @brief 界面要操作数据的所有接口所在
 * @note 所有的改变操作都不会有多个线程同时操作，因此不需要加锁
 * @todo 完善并实现接口
 * @details 凡是涉及要发送的消息，都需要调用Protocol的enqueueSend()接口;存在信号，当信息改变后，会发送信号改变相应的 ui 类
 */
class Core final : public QObject,
                   public CoreFd,
                   public CoreGp,
                   public CoreSelf,
                   public CoreRecore,
                   public std::enable_shared_from_this<Core> {
    Q_OBJECT
public:
    Core(std::shared_ptr<Protocol>protocol);
    ~Core() = default;
public:
    //fd
    bool sendFriend(TypeJson::Send type_send, std::array<QVariant, 4>args) override;
    void recvFriend(TypeJson::Recv type_recv, std::array<QVariant, 4>args) override;
    
    std::shared_ptr<Friend>& getFriend(int idx) override;
    QList<std::shared_ptr<Friend>> &getFriendList() override;

    ChatId& getFriendId(int idx) override;
    std::string& getFriendName(int idx) override;
    QPixmap& getFriendPhoto(int idx) override; 
    
    //gp
    bool sendGroup(TypeJson::Send type_send, std::array<QVariant, 4>args) override;
    void recvGroup(TypeJson::Recv type_recv, std::array<QVariant, 4>args) override;

    std::shared_ptr<Group>& getGroup(int idx) override;
    QList<std::shared_ptr<Group>> &getGroupList() override;

    ChatId& getGroupId(int idx) override;
    std::string& getGroupName(int idx) override;
    QPixmap& getGroupPhoto(int idx) override;

    //self
    bool setPass(const QString& pass) override;
    bool setName(const QString& name) override;
    bool setStatus(const Type::Status& status) override;

    ChatId& getId() override;
    QString& getName() override;
    Type::Status& getStatus() override;
    QString& getPublicKey() override;

    //core
    void loadGroupRecore(int idx) override;
    void saveGroupRecore(int idx) override;
    void loadFriendRecore(int idx) override;
    void saveFriendRecore(int idx) override;

    SIGNAL_IMPL(Core, SigUpdateListFd);//调用sendFriend后，看情况决定是否发送该信号[比如，好友申请被同意]
    SIGNAL_IMPL(Core, SigUpdateListGp);//调用sendGroup后，看情况决定是否发送该信号
private:
    std::shared_ptr<Protocol> m_protocol;
};
