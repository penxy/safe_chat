#pragma once

#include "ui_addfrienddialog.h"
#include <QDialog>
#include "utils/interface.h"

class ChatId;
/**
 * @class AddFriend
 * @brief 添加好友的对话框
 */
class AddFriendDialog : public QDialog{
    Q_OBJECT
public:
    explicit AddFriendDialog(QWidget* parent = nullptr);
signals:
    void SigAddFriend(const ChatId& chatId);
protected:
    Ui_AddFriendDialog ui;
};