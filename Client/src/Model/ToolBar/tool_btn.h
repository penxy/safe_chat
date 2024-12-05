#pragma once

#include <QPushButton>
#include <QMouseEvent>
#include "Base/btn_base.h"

/**
 * @file tool_btn.h
 * @class ToolBtn
 * @brief 工具栏页面的按钮
 */
class ToolBtn : public BtnBase{
    Q_OBJECT
public:
    explicit ToolBtn(QStringList&& path_list, QWidget *parent = nullptr);
protected:
    void mousePressEvent(QMouseEvent *event) override;
};
