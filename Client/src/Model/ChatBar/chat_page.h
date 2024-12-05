#pragma once

#include "config.h"
#include <QStackedWidget>
#include <memory>

class Core;
class Group;
class Friend;
class ChatDefault;
class ChatTop;
class ChatMid;
class ChatBtm;

/**
 * @class ChatPage
 * @brief 总的聊天页面，对外接口
 */
class ChatPage : public QWidget{
    Q_OBJECT
public:
    explicit ChatPage(std::shared_ptr<Core> core, QWidget *parent = 0);
public slots:
    void SlotListChangeIdx(Type::Identity identity, int idx);//切换聊天对象
private:
    Type::Identity m_type;

    std::shared_ptr<Group> m_group_info = nullptr;
    std::shared_ptr<Friend> m_friend_info = nullptr;

    QStackedWidget m_chat_main;
    std::shared_ptr<Core> m_core;

    ChatDefault *chat_default;
    ChatTop *chat_top;
    ChatMid *chat_mid;
    ChatBtm *chat_btm;
};