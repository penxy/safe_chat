#include "fd_card.h"
#include <QHBoxLayout>

#include "Chat/friend.h"
#include "utils/tool.h"

FdCard::FdCard(std::shared_ptr<Friend>info, QWidget *parent) : QDialog(parent){
    m_lab_id.setText(info.get()->getId().toString());
    m_lab_name.setText(info.get()->getName());
    m_lab_photo.SetPhoto(info.get()->getPix());
    m_btn_add.setText("Add");

    m_lab_photo.setFixedSize(sz::card_photo);
    m_lab_id.setFixedSize(sz::card_id);
    m_lab_name.setFixedSize(sz::card_name);
    m_btn_add.setFixedSize(sz::card_btn);
    this->setFixedSize(sz::dialog_wid);

    QHBoxLayout *layout_photo = new QHBoxLayout;
    layout_photo->addWidget(&m_lab_photo);
    QVBoxLayout *layout_info = new QVBoxLayout;
    layout_info->addWidget(&m_lab_id);
    layout_info->addWidget(&m_lab_name);
    QHBoxLayout *layout_info_main = new QHBoxLayout;
    layout_info_main->setSpacing(40);
    layout_info_main->setContentsMargins(0, 0, 0, 0);
    layout_info_main->setAlignment(Qt::AlignLeft);
    layout_info_main->addLayout(layout_photo);
    layout_info_main->addLayout(layout_info);
    QHBoxLayout *layout_btn = new QHBoxLayout;
    layout_btn->addWidget(&m_btn_add);
    layout_btn->setAlignment(Qt::AlignRight);
    QVBoxLayout *layout_main = new QVBoxLayout(this);
    layout_main->addLayout(layout_info_main);
    layout_main->addLayout(layout_btn);

    this->setStyleSheet(TOOL.getQss(Tool::TypeQss::Label));

    connect(&m_btn_add, &QPushButton::clicked, this, [&](){
        __DELAY__;
        m_btn_add.setEnabled(false);

        QByteArray bytes = m_lab_id.text().toUtf8();
        ChatId id = ChatId(bytes);
        emit SigAdd(id);
    });
}