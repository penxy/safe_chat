#pragma once
#include "config.h"
#include <queue>
#include <memory>

class Friend;
class Group;

/**
 * @class CoreHistory
 * @brief 加载和保存数据
 * @note 接口全部隐藏
 */
class CoreHistory{
public:
    CoreHistory() = default;
    virtual ~CoreHistory() = default;
    CoreHistory(const CoreHistory&) = default;
    CoreHistory& operator=(const CoreHistory&) = default;
    CoreHistory(CoreHistory&&) = default;
    CoreHistory& operator=(CoreHistory&&) = default;
protected:
    virtual void initTimeout() = 0;
    virtual void loadGroupHistory(int idx) = 0;
    virtual void loadFriendHistory(int idx) = 0;
    virtual void autoClearHistory() = 0;
public slots:
    virtual void saveGroupHistory(int idx) = 0;
    virtual void saveFriendHistory(int idx) = 0;
protected:
    //QTimer m_timer_save_history;
    QTimer m_timer_clear_history;
    //static const int TIMEOUT_SAVE_HISTORY = 10000;//10s
    static const int TIMEOUT_CLEAR_HISTORY = 1000 * 60 * 60 * 24;//24h
    static const int LONGEST_CLEAR_HISTORY = 30;//30天

    std::queue<std::pair<std::weak_ptr<Friend>, ns::History>>               m_fd_msg_queue;
    std::queue<std::pair<std::weak_ptr<Group>, ns::History>>                m_gp_msg_queue;
};
