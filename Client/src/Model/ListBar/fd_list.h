#pragma once

#include "core_list.h"
class Core;

/**
 * @file fd_list.h
 * @class FdList
 * @brief 好友列表
 */
class FdList : public CoreList{
    Q_OBJECT
public:
    explicit FdList(std::shared_ptr<Core> core, QWidget *parent = 0);
    ~FdList() = default;
public slots:
    void SlotUpdateListFd();
};
