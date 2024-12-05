#include "chat_btm.h"


#include <QHBoxLayout>
#include <QEvent>
#include <QKeyEvent>

#include "utils/tool.h"

ChatBtm::ChatBtm(QWidget *parent) : QWidget(parent){
    {
        m_edit.installEventFilter(this);//触发eventFilter

        m_btn_send.setText("发送");
        m_btn_send.setFixedSize(sz::chat_btm_btn);
        this->setMaximumHeight(sz::chat_btm_wid_max_h);
    }
    {
        QHBoxLayout *layout_btn = new QHBoxLayout;
        layout_btn->addWidget(&m_btn_send);
        layout_btn->setAlignment(Qt::AlignRight | Qt::AlignBottom); 
        QVBoxLayout *layout_main = new QVBoxLayout(this);
        layout_main->addWidget(&m_edit);
        layout_main->addLayout(layout_btn);
        layout_main->setAlignment(Qt::AlignBottom);

        this->setStyleSheet(TOOL.getQss(Tool::TypeQss::TextEdit));
    }
    {
        connect(&m_btn_send, &QPushButton::clicked, this, [&](){
            emit SigSendMsg(m_edit.toPlainText());
            m_edit.clear();
        });
    }
}


bool ChatBtm::eventFilter(QObject *obj, QEvent *event) {
    if (event->type() == QEvent::KeyPress) {
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
        if (keyEvent->key() == Qt::Key_Return || keyEvent->key() == Qt::Key_Enter) {
            emit SigSendMsg(m_edit.toPlainText());
            m_edit.clear();
            return true; // 事件已处理
        }
    }
    return QWidget::eventFilter(obj, event);
}