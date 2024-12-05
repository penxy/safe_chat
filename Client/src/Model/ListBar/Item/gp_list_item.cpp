#include "gp_list_item.h"
#include "Chat/group.h"

GpListItem::GpListItem(std::shared_ptr<void> info, QWidget *parent) : CoreListItem(parent){
    m_info = std::static_pointer_cast<Group>(info);

    m_lab_name.setText(m_info.get()->getName());
    m_lab_photo.SetPhoto(m_info.get()->getPix());
}