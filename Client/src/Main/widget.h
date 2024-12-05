#pragma once
#include "config.h"
#include <memory>
#include "Model/ToolBar/tool_page.h"
#include <QStackedWidget>

class Core;
class TitleBar;
class ListPage;
class ChatPage;
class AddFdPage;

/**
 * @class Widget
 * @brief  主窗口类
 * @details 显示所有组件，连接所有不同组件之间的信号
 * @todo 完成setting_page, 以及各种信号的连接
 */
class Widget : public QWidget{
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = 0);
public slots:
    void SlotTool(ToolPage::TypeBtn type);                                          //工具栏按钮点击, 打开相应的页面
    //void SlotAdd(ChatId id);                                                        //添加ChatId的dialog点击添加
public:
    enum class TypeWid : uint8_t{
        Default,
        Chat,
        AddFd
    };
private:
    TitleBar *m_title_bar;

    ToolPage *m_tool_page;
    QStackedWidget m_stack_widget;

    //stack widget items
    ListPage *m_list_page;
    ChatPage *m_chat_page;
    //add fd
    AddFdPage *m_add_fd_page;


    std::shared_ptr<Core> m_core;
};
