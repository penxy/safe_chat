#pragma once

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>

class ChatId;

/**
 * @class AddFdPage
 * @brief AddFdPage is a page for adding friends
 */
class AddFdPage : public QWidget{
    Q_OBJECT
public:
    explicit AddFdPage(QWidget *parent = nullptr);
signals:
    void SigAddFriend(const ChatId& chatId);
private:
    QLabel              m_lab_id;
    QLineEdit           m_line_id;
    QLabel              m_lab_message;
    QTextEdit           m_text_message;
    QPushButton         m_btn_send;
};

