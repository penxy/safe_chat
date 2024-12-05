#include "member.h"
#include <QHBoxLayout>
#include "Chat/friend.h"

Member::Member(std::pair<Friend, Type::Role>& info, QWidget *parent) : QWidget(parent) {
    {
        m_lab_id.setToolTip("id");
        m_lab_name.setToolTip("name");
        m_lab_role.setToolTip("role");
        m_lab_photo.setToolTip("photo");

        m_lab_id.setFixedSize(sz::member_lab);
        m_lab_name.setFixedSize(sz::member_lab);
        m_lab_photo.setFixedSize(sz::member_photo);
        m_lab_role.setFixedSize(sz::member_lab);
    }
    {
        m_lab_id.setText(info.first.getId().toString());
        m_lab_name.setText(info.first.getName());
        (info.second == Type::Role::Owner) ? m_lab_role.setText("群主") : ((info.second == Type::Role::Admin ? m_lab_role.setText("管理员") : m_lab_role.setText("成员")));
        m_lab_photo.setPixmap(info.first.getPix());
        m_lab_photo.setScaledContents(true);
        m_lab_photo.setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    }
    {
        QHBoxLayout *layout_photo = new QHBoxLayout;
        layout_photo->addWidget(&m_lab_photo);
        layout_photo->setAlignment(Qt::AlignCenter);

        QHBoxLayout *layout_info = new QHBoxLayout;
        layout_info->addWidget(&m_lab_id);
        layout_info->addWidget(&m_lab_name);
        layout_info->addWidget(&m_lab_role);
        layout_info->setAlignment(Qt::AlignLeft);

        QHBoxLayout *layout_main = new QHBoxLayout(this);
        layout_main->addLayout(layout_photo);
        layout_main->addLayout(layout_info);
    }
    {
        QString styleSheet = QString(R"(
            QWidget{
                background-color: rgb(255, 255, 255);
                border: 1px solid rgb(200, 200, 200);
            }
            QLabel{
                border: 1px solid rgb(200, 200, 200);
                border-radius: 5px;
            }
        )");
        this->setStyleSheet(styleSheet);
    }
}