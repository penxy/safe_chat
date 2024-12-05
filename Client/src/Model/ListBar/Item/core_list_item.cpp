#include "core_list_item.h"
#include <QVBoxLayout>

#include "utils/tool.h"

CoreListItem::CoreListItem(QWidget *parent) : QWidget(parent){
    m_lab_name.setToolTip("name");
    
    m_lab_photo.setFixedSize(sz::fd_list_photo);
    m_lab_name.setFixedSize(sz::fd_list_name);
    this->setFixedSize(sz::fd_list_wid);

    QVBoxLayout* layout_photo = new QVBoxLayout;
    layout_photo->setMargin(0);
    layout_photo->addWidget(&m_lab_photo);
    QVBoxLayout* layout_name = new QVBoxLayout;
    layout_name->setSpacing(5);
    layout_name->addWidget(&m_lab_name);
    layout_name->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    QHBoxLayout* layout_main = new QHBoxLayout(this);
    layout_main->addLayout(layout_photo);
    layout_main->addLayout(layout_name);

    this->setStyleSheet(TOOL.getQss(Tool::TypeQss::Label));
}
