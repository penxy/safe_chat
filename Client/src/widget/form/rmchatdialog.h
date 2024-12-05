#pragma once

#include "ui_rmchatdialog.h"
#include <QDialog>
#include "utils/interface.h"

/**
 * @class RmChatDialog
 * @brief 移除Chat时的确认对话框
 */
class RmChatDialog : public QDialog
{
    Q_OBJECT
public:
    explicit RmChatDialog(QWidget* parent = nullptr);
signals:
    void SigRmChatAgree();
protected:
    Ui_RemoveChatDialog ui;
};
