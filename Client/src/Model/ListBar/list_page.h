#pragma once
#include "config.h"
#include <QStackedWidget>
#include <memory>

class Core;
class FdList;
class GpList;

/**
 * @file list_page.h
 * @class ListPage
 * @brief 中间的好友、群列表页
 * @note 所有对外的接口，信号，槽函数都在这里
 */
class ListPage : public QWidget{
    Q_OBJECT
public:
    explicit ListPage(std::shared_ptr<Core> core, QWidget *parent = nullptr);
    ~ListPage() = default;

    enum class TypePage{
        NONE,
        Friend,
        Group
    };
    void setPage(TypePage type_page);
    //void addList(Type::Identity, std::shared_ptr<void>);
    //void delList(Type::Identity, int);
signals:
    void SigListChangeIdx(Type::Identity identity, int idx);
private:
    QStackedWidget m_stack_wid;
    FdList *m_fd_list;
    GpList *m_gp_list;
};