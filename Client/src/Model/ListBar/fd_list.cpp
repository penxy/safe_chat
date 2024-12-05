#include "fd_list.h"
#include "Item/fd_list_item.h"
#include "Core/core.h"

FdList::FdList(std::shared_ptr<Core> core, QWidget *parent) : CoreList(Type::Identity::Friend, core, parent){
}

/**
 * @def SlotUpdateListFd
 * @brief 更新列表 
 */
void FdList::SlotUpdateListFd(){
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
    auto fd_list = m_core->getFriendList();
    for(auto& fd : fd_list){
        FdListItem *wid_fd_item = new FdListItem(fd, this);
        QListWidgetItem *item = new QListWidgetItem(&m_wid_list);
        item->setSizeHint(wid_fd_item->sizeHint());
        m_wid_list.setItemWidget(item, wid_fd_item);
    }
}