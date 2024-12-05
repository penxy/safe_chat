#include "gp_list.h"
#include "Item/gp_list_item.h"
#include "Core/core.h"

GpList::GpList(std::shared_ptr<Core> core, QWidget *parent) : CoreList(Type::Identity::Group, core, parent){
}

/**
 * @def SlotUpdateListGp
 * @brief 更新列表 
 */
void GpList::SlotUpdateListGp(){
    //delete all items
    int number = m_wid_list.count();
    for (int i = 0; i < number; i++){
        QListWidgetItem *item = m_wid_list.takeItem(0);
        if(item){
            delete item;
            item = nullptr;
        }
    }
    //set all items
    auto gp_list = m_core->getFriendList();
    for(auto& gp : gp_list){
        GpListItem *wid_gp_item = new GpListItem(gp, this);
        QListWidgetItem *item = new QListWidgetItem(&m_wid_list);
        item->setSizeHint(wid_gp_item->sizeHint());
        m_wid_list.setItemWidget(item, wid_gp_item);
    }
}