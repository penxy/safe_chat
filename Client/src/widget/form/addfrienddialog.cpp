#include "addfrienddialog.h"
#include "Chat/chatid.h"
#include <QTimer>

#ifndef __DELAY__
#define __DELAY__ QTimer::singleShot(200, this, [&](){});
#endif

AddFriendDialog::AddFriendDialog(QWidget *parent) : QDialog(parent){
    ui.setupUi(this);
    ui.edit_message->setPlaceholderText("请输入验证信息");
    connect(ui.btn_send, &QPushButton::clicked, [this](){
        __DELAY__;
        ui.btn_send->setEnabled(false);
        ui.btn_send->setText("send success");
        ChatId id(ui.line_id->text());
        emit SigAddFriend(id);
    });
}