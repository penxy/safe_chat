#include "add_fd_page.h"
#include <QVBoxLayout>
#include <QTimer>
#include "Chat/chatid.h"

#ifndef __DELAY__
#define __DELAY__ QTimer::singleShot(200, this, [&](){});
#endif

AddFdPage::AddFdPage(QWidget *parent) : QWidget(parent){
    m_lab_id.setText("Friend ID:");
    m_lab_message.setText("Message:");
    m_text_message.setPlainText(tr("Hello, I would like to add you as a friend."));
    m_btn_send.setText("send friend request");

    QVBoxLayout *layout_main = new QVBoxLayout(this);
    layout_main->addWidget(&m_lab_id);
    layout_main->addWidget(&m_line_id);
    layout_main->addWidget(&m_lab_message);
    layout_main->addWidget(&m_text_message);
    layout_main->addWidget(&m_btn_send);

    connect(&m_btn_send, &QPushButton::clicked, [this](){
        __DELAY__;
        m_btn_send.setEnabled(false);
        m_btn_send.setText("send success");
        ChatId id(m_line_id.text());
        emit SigAddFriend(id);
    });
}