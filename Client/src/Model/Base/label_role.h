#pragma once

#include <QLabel>
#include "config.h"

/**
 * @class LabelRole
 * @brief  用于展示群成员列表中的角色
 */
class LabelRole : public QLabel{
public:
    explicit LabelRole(Type::Role role, QWidget *parent = 0);
};

