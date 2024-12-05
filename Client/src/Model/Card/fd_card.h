#pragma once
#include "config.h"

#include <QDialog>
#include <QPushButton>
#include <QPixmap>
#include <memory>
#include "Base/label_photo.h"

class Friend;
class ChatId;
/**
 * @class FdCard
 * @brief 好友卡片
 * @deprecated 已弃用
 */
class FdCard : public QDialog {
    Q_OBJECT
public:
    explicit FdCard(std::shared_ptr<Friend>info, QWidget *parent = nullptr);
signals:
    void SigAdd(ChatId id);
protected:
    QPixmap m_photo;

    QLabel m_lab_id;
    QLabel m_lab_name;
    QPushButton m_btn_add;
    LabelPhoto m_lab_photo;
};
