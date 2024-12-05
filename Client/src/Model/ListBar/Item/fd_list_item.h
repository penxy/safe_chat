#pragma once

#include "core_list_item.h"
#include <memory>

class Friend;
/**
 * @file fd_list_item.h
 * @class FdListItem
 * @brief 好友列表中的一项
 */
class FdListItem : public CoreListItem{
    Q_OBJECT
public:
    explicit FdListItem(std::shared_ptr<void> info, QWidget *parent = 0);
private:
    std::shared_ptr<Friend>m_info;
};
