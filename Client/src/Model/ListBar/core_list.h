#pragma once
#include "config.h"

#include <QListWidget>
#include <QWidget>
#include <memory>

class Core;

/**
 * @file core_list.h
 * @class CoreList
 * @brief base class for FdList and GpList
 */
class CoreList : public QWidget{
    Q_OBJECT
public:
    explicit CoreList(Type::Identity identity, std::shared_ptr<Core> core, QWidget *parent = nullptr);
    ~CoreList() = default;
signals:
    void SigListChangeIdx(Type::Identity identity, int idx);//这个信号会经过ListPage中转，最终到达ChatMid
protected:
    QListWidget m_wid_list;
    std::shared_ptr<Core> m_core;
private:
    int m_cur_idx = -1;
    Type::Identity m_identity;
};

