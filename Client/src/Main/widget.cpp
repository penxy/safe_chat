#include "widget.h"
#include <QVBoxLayout>
#include <unistd.h>
#include "Model/ListBar/list_page.h"
#include "Model/TitleBar/title_bar.h"
#include "Model/ChatBar/chat_page.h"
#include "Model/Add/add_fd_page.h"

#include "Core/core.h"
#include "Base/widget_blank.h"

Widget::Widget(QWidget *parent) : QWidget(parent){
    m_core = std::make_shared<Core>(nullptr);
    m_tool_page = new ToolPage(this);

    //m_stack_widget
    {
        //default page
        WidgetBlank *widget_default = new WidgetBlank(this);
        m_stack_widget.addWidget(widget_default);
        //Chat Page
        m_list_page = new ListPage(m_core->shared_from_this(), this);
        m_chat_page = new ChatPage(m_core->shared_from_this(), this);
        WidgetBlank *widget_chat = new WidgetBlank(this);
        QHBoxLayout *layout_chat = new QHBoxLayout(widget_chat);
        layout_chat->addWidget(m_list_page);
        layout_chat->addWidget(m_chat_page);
        m_stack_widget.addWidget(widget_chat);
        //Add Fd
        m_add_fd_page = new AddFdPage(this);
        m_stack_widget.addWidget(m_add_fd_page);
        //Setting...

        m_stack_widget.setCurrentIndex((int)TypeWid::Default);
    }

    m_title_bar = new TitleBar(this);
    QHBoxLayout *layout_top = new QHBoxLayout;
    layout_top->addWidget(m_title_bar);

    QHBoxLayout *layout_btm = new QHBoxLayout;
    layout_btm->setSpacing(0);
    layout_btm->addWidget(m_tool_page);
    layout_btm->addWidget(&m_stack_widget);

    QVBoxLayout *layout_main = new QVBoxLayout(this);
    layout_main->setSpacing(0);
    layout_main->addLayout(layout_top);
    layout_main->addLayout(layout_btm);


    //所有对外信号所在
    // connect(m_list_page, &ListPage::SigListChangeIdx, m_chat_page, &ChatPage::SlotListChangeIdx);
    connect(m_tool_page, &ToolPage::SigTool, this, &Widget::SlotTool);
}

void Widget::SlotTool(ToolPage::TypeBtn type){
    switch (type){
        case ToolPage::TypeBtn::Add:{
            m_stack_widget.setCurrentIndex(static_cast<uint8_t>(TypeWid::AddFd));
            break;
        }
        case ToolPage::TypeBtn::ChatPerson:{
            m_stack_widget.setCurrentIndex(static_cast<uint8_t>(TypeWid::Chat));
            m_list_page->setPage(ListPage::TypePage::Friend);
            break;
        }
        case ToolPage::TypeBtn::ChatGroup:{
            m_stack_widget.setCurrentIndex(static_cast<uint8_t>(TypeWid::Chat));
            m_list_page->setPage(ListPage::TypePage::Group);
            break;
        }
        case ToolPage::TypeBtn::Setting:{
            m_stack_widget.setCurrentIndex(static_cast<uint8_t>(TypeWid::Default));
            break;
        }
        default:
            break;
    }
}