#include "list_page.h"
#include <QHBoxLayout>

#include "fd_list.h"
#include "gp_list.h"
#include "utils/tool.h"
#include "Core/core.h"

ListPage::ListPage(std::shared_ptr<Core> core, QWidget *parent) : QWidget(parent){
    m_fd_list = new FdList(core, this);
    m_gp_list = new GpList(core, this);

    m_stack_wid.addWidget(new QWidget(this));
    m_stack_wid.addWidget(m_fd_list);
    m_stack_wid.addWidget(m_gp_list);
    m_stack_wid.setCurrentIndex((int)TypePage::NONE);

    QHBoxLayout *layout_main = new QHBoxLayout(this);
    layout_main->setContentsMargins(0, 0, 0, 0);
    layout_main->addWidget(&m_stack_wid);

    connect(m_fd_list, &FdList::SigListChangeIdx, this, [&](Type::Identity identity, int idx){
        emit SigListChangeIdx(identity, idx);
    });
    connect(m_gp_list, &GpList::SigListChangeIdx, this, [&](Type::Identity identity, int idx){
        emit SigListChangeIdx(identity, idx);
    });

    this->setFixedWidth(sz::list_bar_w);
}
/**
 * @brief 设置当前页面
 */
void ListPage::setPage(TypePage type_page){
    m_stack_wid.setCurrentIndex((int)type_page);
}

// void ListPage::addList(Type::Identity indentity, std::shared_ptr<void>info){
//     if(indentity == Type::Identity::Friend)
//         static_cast<FdList*>(m_stack_wid.widget((int)TypePage::Friend))->AddItem(info);
//     else
//         static_cast<GpList*>(m_stack_wid.widget((int)TypePage::Group))->AddItem(info);
// }
// void ListPage::delList(Type::Identity indentity, int id){
//     if(indentity == Type::Identity::Friend)
//         static_cast<FdList*>(m_stack_wid.widget((int)TypePage::Friend))->DelItem(id);
//     else
//         static_cast<GpList*>(m_stack_wid.widget((int)TypePage::Group))->DelItem(id);
// }

void ListPage::SlotUpdateListFd(){
    qDebug() << "update list Fd";
    m_fd_list->UpdateList();
}
void ListPage::SlotUpdateListGp(){
    qDebug() << "update list Gp";
    m_gp_list->UpdateList();
}