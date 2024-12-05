#pragma once

#include "config.h"

#include <QWidget>
#include <QTextEdit>
#include <QPushButton>

/**
 * @class ChatBtm
 * @brief 聊天窗口底部, 包括文本框和发送按钮
 * @todo 后续添加其它按钮，如表情包，文件传输等
 */
class ChatBtm : public QWidget{
    Q_OBJECT
public:
    explicit ChatBtm(QWidget *parent = nullptr);
signals:
    void SigSendMsg(const QString &msg);
protected:
    bool eventFilter(QObject *obj, QEvent *event) override;
private:
    QTextEdit m_edit;
    QPushButton m_btn_send;
};
