#include "chat_page.h"
#include "Base/widget_blank.h"
#include "Base/Layout.h"
#include "chat_default.h"
#include "Core/core.h"

#include "chat_top.h"
#include "chat_mid.h"
#include "chat_btm.h"

ChatPage::ChatPage(std::shared_ptr<Core> core, QWidget *parent) : QWidget(parent), m_core(core){
    chat_default = new ChatDefault;
    chat_top = new ChatTop;
    chat_mid = new ChatMid;
    chat_btm = new ChatBtm;

    this->resize(sz::chat_wid_base);
    this->setMinimumSize(sz::chat_wid_min);

    {
        WidgetBlank *wid_default = new WidgetBlank;
        Layout *layout_default = new Layout(QBoxLayout::Direction::TopToBottom, wid_default);
        layout_default->addWidget(chat_default);

        WidgetBlank *wid_chat = new WidgetBlank;
        Layout *layout_chat = new Layout(QBoxLayout::Direction::TopToBottom, wid_chat);
        layout_chat->setSpacing(0);
        layout_chat->addWidget(chat_top);
        layout_chat->addWidget(chat_mid);
        layout_chat->addWidget(chat_btm);

        m_chat_main.addWidget(wid_default);
        m_chat_main.addWidget(wid_chat);
        m_chat_main.setCurrentWidget(wid_default);

        Layout *layout_main = new Layout(QBoxLayout::Direction::TopToBottom, this);
        layout_main->addWidget(&m_chat_main);
    }
    {
        connect(chat_btm, &ChatBtm::SigSendMsg, chat_mid, &ChatMid::SlotSendMsg);
    }
}

/**
 * @brief ListPage改变，修正ChatPage
 * @attention 还需要聊天记录之类的
 */
void ChatPage::SlotListChangeIdx(Type::Identity identity, int idx){
    if(m_type == Type::Identity::Friend){
        chat_top->SetInfo(m_core->getFriendName(idx), m_core->getFriendPhoto(idx));
    }else{
        chat_top->SetInfo(m_core->getGroupName(idx), m_core->getGroupPhoto(idx));
    }
    m_chat_main.setCurrentIndex(1);//切换到聊天界面
    //other
}