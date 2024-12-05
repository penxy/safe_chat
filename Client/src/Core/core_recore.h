#pragma once
#include "config.h"

/**
 * @class CoreRecore
 * @brief 加载和保存数据
 * @note 暂不实现
 */
class CoreRecore{
public:
    CoreRecore() = default;
    virtual ~CoreRecore() = default;
    CoreRecore(const CoreRecore&) = default;
    CoreRecore& operator=(const CoreRecore&) = default;
    CoreRecore(CoreRecore&&) = default;
    CoreRecore& operator=(CoreRecore&&) = default;

    virtual void loadGroupRecore(int idx) = 0;
    virtual void saveGroupRecore(int idx) = 0;

    virtual void loadFriendRecore(int idx) = 0;
    virtual void saveFriendRecore(int idx) = 0;
};
