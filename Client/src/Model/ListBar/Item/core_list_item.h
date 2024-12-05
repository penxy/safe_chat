#pragma once
#include "config.h"

#include <QLabel>
#include <QLabel>
#include "Base/label_photo.h"
/**
 * @file core_list_item.h
 * @class CoreListItem
 * @brief item of friend list or group list
 */
class CoreListItem : public QWidget{
    Q_OBJECT
public:
    explicit CoreListItem(QWidget *parent = nullptr);
    ~CoreListItem() = default;
protected:
    QLabel m_lab_name;
    LabelPhoto m_lab_photo;
};