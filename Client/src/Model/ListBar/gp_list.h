#pragma once

#include "core_list.h"
class Core;

/**
 * @file gp_list.h
 * @class GpList
 * @brief 群组列表
 */
class GpList : public CoreList{
    Q_OBJECT
public:
    explicit GpList(std::shared_ptr<Core> core, QWidget *parent = nullptr);
    ~GpList() = default;
public slots:
    void SlotUpdateListGp();
};