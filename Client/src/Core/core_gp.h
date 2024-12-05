#pragma once
#include "config.h"
#include <QList>
#include "Service/const_json.h"

#include "Chat/group.h"

class CoreGp{
public:
    CoreGp() = default;
    ~CoreGp() = default;
    CoreGp(const CoreGp&) = default;
    CoreGp& operator=(const CoreGp&) = default;
    CoreGp(CoreGp&&) = default;
    CoreGp& operator=(CoreGp&&) = default;

    virtual bool sendGroup(TypeJson::Send type_send, std::array<QVariant, 4>args) = 0;
    virtual void recvGroup(TypeJson::Recv type_recv, std::array<QVariant, 4>args) = 0;
    
    virtual std::shared_ptr<Group>& getGroup(int idx) = 0;
    virtual QList<std::shared_ptr<Group>>& getGroupList() = 0;

    virtual ChatId& getGroupId(int idx) = 0;
    virtual std::string& getGroupName(int idx) = 0;
    virtual QPixmap& getGroupPhoto(int idx) = 0; 

    DECLARE_SIGNAL(SigUpdateListGp);//更新群列表
protected:
    QList<std::shared_ptr<Group>> m_gp_list;
};