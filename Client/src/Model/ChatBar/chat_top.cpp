#include "chat_top.h"
#include <QHBoxLayout>

#include "utils/tool.h"

ChatTop::ChatTop(QWidget *parent) : WidgetBlank(parent){
    {
        m_lab_name.setFixedSize(sz::chat_top_lab);
        m_lab_photo.setFixedSize(sz::chat_top_photo);
        this->setFixedSize(sz::chat_top_wid);
    }
    {
        QHBoxLayout *layout_photo = new QHBoxLayout;
        layout_photo->addWidget(&m_lab_photo);
        QHBoxLayout *layout_name = new QHBoxLayout;
        layout_name->addWidget(&m_lab_name);
        QBoxLayout *layout_main = new QBoxLayout(QBoxLayout::LeftToRight, this);
        layout_main->setAlignment(Qt::AlignLeft);
        layout_main->addLayout(layout_photo);
        layout_main->setSpacing(10);
        layout_main->addLayout(layout_name);

        this->setStyleSheet(TOOL.getQss(Tool::TypeQss::Label));
    }
}

/**
 * @brief 设置聊天窗口顶部信息
 * @param name 聊天对象名称
 * @param photo 聊天对象头像
 */
void ChatTop::SetInfo(const std::string& name, const QPixmap& photo){
    m_lab_name.setText(QString::fromStdString(name));
    m_lab_photo.SetPhoto(photo);
}