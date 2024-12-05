#pragma once

#include "config.h"
#include "bubble/bubble_msg.h"
#include <QListWidget>

/**
 * @class ChatMid
 * @brief 对话框
 */
class ChatMid : public QWidget{
    Q_OBJECT
public:
    explicit ChatMid(QWidget *parent = nullptr);

private:
    void dealMessageTime(QString curMsgTime);
    void dealMessage(BubbleMsg *messageW, QListWidgetItem *item, QString text, QString time,  BubbleMsg::User_Type type);
//     void on_pushButton_clicked();
public slots:
    void SlotSendMsg(const QString &msg);
//     void SlotMessageSendSuccess(int index);
//     void SlotMessageRecv(MsgInfo *msg_info);
protected:
    void resizeEvent(QResizeEvent *);
private:
    QListWidget m_list_widget;
    std::vector<BubbleMsg*>m_widget_msg_vec;//不需要手动析构
};

